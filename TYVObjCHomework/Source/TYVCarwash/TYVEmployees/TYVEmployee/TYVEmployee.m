//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVSelector.h"
#import "TYVMoneyTransferProtocol.h"
#import "TYVQueue.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString        *duty;
@property (nonatomic, retain)   NSDecimalNumber *salary;

@property (nonatomic, retain)   TYVQueue        *objectsQueue;

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransferProtocol>)object;
- (void)performWorkWithObjectOnMainThread:(id<TYVMoneyTransferProtocol>)object;

@end

@implementation TYVEmployee

@synthesize money = _money;

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    self.objectsQueue = nil;
    self.money = nil;
    
    [self removeObserver:self];
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithDuty:@""
                       salary:[NSDecimalNumber zero]
                        money:[NSDecimalNumber zero]];
}

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money
{
    self = [super init];
    if (self) {
        self.duty = duty;
        self.salary = salary;
        self.state = TYVEmployeeDidBecomeFree;
        self.money = money;
        self.objectsQueue = [[[TYVQueue alloc] init] autorelease];
        
        [self addObserver:self];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TYVEmployeeDidBecomeFree:
            return @selector(employeeDidBecomeFree:);
            
        case TYVEmployeeDidBecomeBusy:
            return @selector(employeeDidBecomeBusy:);
            
        case TYVEmployeeDidPerformWorkWithObject:
            return @selector(employeeDidPerformWork:);
            
        default:
            return [super selectorForState:state];
    }
}

- (void)processWithObject:(id<TYVMoneyTransferProtocol> )object {

}

- (void)finalizeProcessWithObjectOnMainThread:(TYVEmployee *)object {
    object.state = TYVEmployeeDidBecomeFree;
}

- (void)performWorkWithObject:(id<TYVMoneyTransferProtocol>)object {
    if (object) {
        NSLog(@"%@ with experience %lu started to work with %@",
              [self class],
              (unsigned long)self.experience,
              [object class]);
        self.state = TYVEmployeeDidBecomeBusy;
//        [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
//                               withObject:object];
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            [self performWorkWithObjectInBackground:object];
        });
    }
}


#pragma mark -
#pragma mark Private Methods

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransferProtocol>)object {
    [self processWithObject:object];
//    [self performSelectorOnMainThread:@selector(performWorkWithObjectOnMainThread:)
//                           withObject:object
//                        waitUntilDone:NO];
    dispatch_async(dispatch_get_main_queue(), ^ {
        [self performWorkWithObjectOnMainThread:object];
    });
    
}

- (void)performWorkWithObjectOnMainThread:(id<TYVMoneyTransferProtocol>)object {
    self.state = TYVEmployeeDidPerformWorkWithObject;
    [self finalizeProcessWithObjectOnMainThread:object];
}

#pragma mark -
#pragma mark TYVMoneyTransfer

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransferProtocol>)object {
    [self takeMoney:money];
    [object giveMoney:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransferProtocol>)object {
    [self giveMoney:money];
    [object takeMoney:money];
}

- (void)takeMoney:(NSDecimalNumber *)money {
    @synchronized (self) {
        self.money = [self.money decimalNumberByAdding:money];
    }
}

- (void)giveMoney:(NSDecimalNumber *)money {
    @synchronized (self) {
        self.money = [self.money decimalNumberBySubtracting:money];
    }
}

@end
