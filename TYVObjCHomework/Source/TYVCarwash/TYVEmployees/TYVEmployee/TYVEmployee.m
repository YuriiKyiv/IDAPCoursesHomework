//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVSelectorWrapper.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString            *duty;
@property (nonatomic, retain)   NSDecimalNumber     *salary;

@property (nonatomic, retain)   NSHashTable         *observersHashTable;

@end

@implementation TYVEmployee
@synthesize money = _money;

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    self.observersHashTable = nil;
    
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
        self.observersHashTable = [NSHashTable weakObjectsHashTable];
        self.state = TYVEmployeeDidBecomeFree;
        self.money = [NSDecimalNumber decimalNumberWithString:@"0"];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observersSet {
    return self.observersHashTable.setRepresentation;
}

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

- (void)notifyWithSelector:(NSString *)stringSelector {
    @synchronized(self) {
        SEL selector = NSSelectorFromString(stringSelector);
        NSHashTable *observers = self.observersHashTable;
        for (id observer in observers) {
            if ([observer respondsToSelector:selector]) {
                [observer performSelector:selector withObject:self];
            }
        }
    }
}

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

- (void)addObserver:(id)observer {
    [self.observersHashTable addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.observersHashTable removeObject:observer];
}

- (BOOL)containsObserver:(id)observer {
    return [self.observersHashTable containsObject:observer];
}

#warning add synchronized in moneykeeper
#warning fix synchronized here
- (void)workWithObject:(id<TYVMoneyTransfer> )object {
    @autoreleasepool {
        @synchronized (object) {
            self.state = TYVEmployeeDidBecomeBusy;
            [self takeMoney:object.money fromObject:object];
        }
    }
}

- (void)perfomWorkWithObject:(TYVMoneyKeeper *)object {
    [self performSelectorInBackground:@selector(workWithObject:) withObject:object];
}

#pragma mark -
#pragma mark TYVEmployeeDelegate

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
