//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVSelectorWrapper.h"
#import "TYVMoneyTransfer.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString            *duty;
@property (nonatomic, retain)   NSDecimalNumber     *salary;

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransfer>)object;
- (void)finishWorkWithObjectOnMainThread:(id<TYVMoneyTransfer>)object;

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

- (void)workWithObject:(id<TYVMoneyTransfer> )object {
    [self takeMoney:object.money fromObject:object];
}

- (void)performWorkWithObject:(id<TYVMoneyTransfer>)object {
    @synchronized (self) {
        self.state = TYVEmployeeDidBecomeBusy;
        [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:) withObject:object];
    }
}

- (void)performWorkWithObjectInBackground:(id<TYVMoneyTransfer>)object {
    @autoreleasepool {
        @synchronized (self) {
            [self workWithObject:object];
#warning add method of notification on main thread
        }
    }
}

- (void)finishWorkWithObjectOnMainThread:(id<TYVMoneyTransfer>)object {
    self.state = TYVEmployeeDidPerformWorkWithObject;
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    [self performWorkWithObject:employee];
}

#pragma mark -
#pragma mark TYVMoneyTransfer

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object {
    @synchronized(object) {
        self.money = [self.money decimalNumberByAdding:money];
        object.money = [object.money decimalNumberBySubtracting:money];
    }
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object {
    @synchronized(object) {
        self.money = [self.money decimalNumberBySubtracting:money];
        object.money = [object.money decimalNumberByAdding:money];
    }
}

@end
