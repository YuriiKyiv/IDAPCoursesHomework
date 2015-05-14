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
    self = [super initWithMoney:money];
    if (self) {
        self.duty = duty;
        self.salary = salary;
        self.observersHashTable = [NSHashTable weakObjectsHashTable];
        self.state = TYVEmployeeDidBecomeFree;
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

- (void)workWithObject:(TYVMoneyKeeper *)object {
    self.state = TYVEmployeeDidBecomeBusy;
    [self takeMoney:object.money fromMoneykeeper:object];
}

- (void)perfomWorkWithObjectInBackground:(TYVMoneyKeeper *)object {
    [self performSelectorInBackground:@selector(workWithObject:) withObject:object];
}

#pragma mark -
#pragma mark TYVEmployeeDelegate

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object {
    [self perfomWorkWithObjectInBackground:employee];
}

@end
