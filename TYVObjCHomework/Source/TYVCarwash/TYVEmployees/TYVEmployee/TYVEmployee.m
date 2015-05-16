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

- (instancetype)init
{
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
#pragma mark Accessors

- (void)setState:(TYVEmployeeState)state {
    @synchronized(self) {
        if (_state != state) {
            _state = state;
            NSString *stringSelector = NSStringFromSelector([self selectorForState:state]);
            [self performSelectorOnMainThread:@selector(notifyWithSelector:)
                                   withObject:stringSelector
                                waitUntilDone:NO];
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TYVEmployeeDidBecomeFree:
            return @selector(employeeDidBecomeFree:);
            
        case TYVEmployeeDidBecomeBusy:
            return @selector(employeeDidBecomeBusy:);
            
        case TYVEmployeeDidPerfomWorkWithObject:
            return @selector(employee:didPerfomWorkWithObject:);
            
        default:
            return nil;
    }
}

- (void)workWithObject:(id<TYVMoneyTransfer> )object {
    @autoreleasepool {
        @synchronized (object) {
            self.state = TYVEmployeeDidBecomeBusy;
            [self takeMoney:object.money fromObject:object];
        }
    }
}

- (void)perfomWorkWithObject:(id<TYVMoneyTransfer>)object {
    [self performSelectorInBackground:@selector(workWithObject:) withObject:object];
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object {
    [self perfomWorkWithObject:employee];
}

#pragma mark -
#pragma mark TYVMoneyTransfer

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object {
    self.money = [self.money decimalNumberByAdding:money];
    object.money = [object.money decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object {
    self.money = [self.money decimalNumberBySubtracting:money];
    object.money = [object.money decimalNumberByAdding:money];
}

@end
