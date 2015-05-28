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

- (void)proccesWithObject:(id<TYVMoneyTransferProtocol> )object {

}

- (void)finalizeProccesingWithObjectOnMainThread:(TYVEmployee *)object {
    object.state = TYVEmployeeDidBecomeFree;
}

- (void)performWorkWithObject:(id<TYVMoneyTransferProtocol>)object {
    if (object) {
        @synchronized (self) {
            if (TYVEmployeeDidBecomeFree == self.state) {
                self.state = TYVEmployeeDidBecomeBusy;
                [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                       withObject:object];
            } else {
                [self.objectsQueue enqueueObject:object];
            }
        }
    }
}


#pragma mark -
#pragma mark Private Methods

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransferProtocol>)object {
    @autoreleasepool {
        if (object) {
            [self proccesWithObject:object];
            [self performSelectorOnMainThread:@selector(performWorkWithObjectOnMainThread:)
                                   withObject:object
                                waitUntilDone:NO];
        }
    }
}

- (void)performWorkWithObjectOnMainThread:(id<TYVMoneyTransferProtocol>)object {
    @autoreleasepool {

        @synchronized (self) {
            TYVQueue *queue = self.objectsQueue;
            id proccesingObject = [queue dequeueObject];
            if (proccesingObject) {
                [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                       withObject:proccesingObject];
            } else {
                self.state = TYVEmployeeDidPerformWorkWithObject;
            }
        }
        
        [self finalizeProccesingWithObjectOnMainThread:object];
    }
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    if (self != employee) {
        [self performWorkWithObject:employee];
    }
}

- (void)employeeDidBecomeFree:(TYVEmployee *)employee {
    @synchronized (self) {
        TYVQueue *queue = self.objectsQueue;
        if (TYVEmployeeDidBecomeFree == self.state) {
            [self performWorkWithObject:[queue dequeueObject]];
        }
    }
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
