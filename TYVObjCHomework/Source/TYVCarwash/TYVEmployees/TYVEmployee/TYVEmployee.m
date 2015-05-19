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

@property (nonatomic, retain)   NSRecursiveLock     *lock;
@property (nonatomic, retain)   NSRecursiveLock     *moneylock;

@end

@implementation TYVEmployee

@synthesize money = _money;

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    self.lock = nil;
    self.moneylock = nil;
    
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
        self.lock = [[NSRecursiveLock new] autorelease];
        self.moneylock = [[NSRecursiveLock new] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    NSRecursiveLock *lock = self.lock;
    if (super.state != state) {
        [lock lock];
        if (super.state != state) {
            super.state = state;
            [self performSelectorOnMainThread:@selector(notify)
                                   withObject:nil
                                    waitUntilDone:NO];
        }
            
        [lock unlock];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)notify {
    [self notifyWithSelector:[self selectorForState:self.state]];
}

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TYVEmployeeDidBecomeFree:
            return @selector(employeeDidBecomeFree:);
            
        case TYVEmployeeDidBecomeBusy:
            return @selector(employeeDidBecomeBusy:);
            
        case TYVEmployeeDidPerfomWorkWithObject:
            return @selector(employeeDidPerfomWork:);
            
        default:
            return nil;
    }
}

- (void)workWithObject:(id<TYVMoneyTransfer> )object {
    @autoreleasepool {
            [self takeMoney:object.money fromObject:object];
    }
}

- (void)perfomWorkWithObject:(id<TYVMoneyTransfer>)object {
    self.state = TYVEmployeeDidBecomeBusy;
    [self performSelectorInBackground:@selector(workWithObject:) withObject:object];
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerfomWork:(TYVEmployee *)employee {
    [self perfomWorkWithObject:employee];
}

#pragma mark -
#pragma mark TYVMoneyTransfer

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object {
    NSRecursiveLock *lock = self.lock;
    [lock lock];
    self.money = [self.money decimalNumberByAdding:money];
    object.money = [object.money decimalNumberBySubtracting:money];
    [lock unlock];
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object {
    self.money = [self.money decimalNumberBySubtracting:money];
    object.money = [object.money decimalNumberByAdding:money];
}

@end
