//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVSelector.h"
#import "TYVMoneyTransfer.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString            *duty;
@property (nonatomic, retain)   NSDecimalNumber     *salary;

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransfer>)object;
- (void)performWorkWithObjectOnMainThread:(id<TYVMoneyTransfer>)object;

@end

@implementation TYVEmployee

@synthesize money = _money;

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    
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
            return NULL;
    }
}

- (void)proccesWithObject:(id<TYVMoneyTransfer> )object {

}

- (void)finalizeProccesingWithObjectOnMainThread:(TYVEmployee *)object {
    object.state = TYVEmployeeDidBecomeFree;
}

- (void)performWorkWithObject:(id<TYVMoneyTransfer>)object {
    @synchronized (self) {
        self.state = TYVEmployeeDidBecomeBusy;
        
        [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                               withObject:object];
    }
}


#pragma mark -
#pragma mark Private Methods

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransfer>)object {
    @autoreleasepool {
        @synchronized (self) {
            [self proccesWithObject:object];
            
            [self performSelectorOnMainThread:@selector(performWorkWithObjectOnMainThread:)
                                   withObject:object
                                waitUntilDone:NO];
        }
    }
}

- (void)performWorkWithObjectOnMainThread:(id<TYVMoneyTransfer>)object {
    @autoreleasepool {
        @synchronized (self) {
            [self finalizeProccesingWithObjectOnMainThread:object];
            
            self.state = TYVEmployeeDidPerformWorkWithObject;
        }
    }
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    [self performWorkWithObject:employee];
}

#pragma mark -
#pragma mark TYVMoneyTransfer

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object {
    [self takeMoney:money];
    [object giveMoney:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object {
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
