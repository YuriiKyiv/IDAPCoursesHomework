//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString        *duty;
@property (nonatomic, retain)   NSDecimalNumber *salary;

@property (nonatomic, retain)   NSHashTable     *observersHashTable;

- (void)notifyWithSelector:(SEL)selector;

@end

@implementation TYVEmployee

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    self.delegate = nil;
    self.delegatingObject = nil;
    self.ObserversHashTable = nil;
    
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
        self.free = YES;
        self.ObserversHashTable = [NSHashTable weakObjectsHashTable];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observersSet {
    return self.observersHashTable.setRepresentation;
}

- (void)setDelegatingObject:(id)object {
    if (_delegatingObject != object) {
        _delegatingObject.delegate = nil;
        
        [_delegatingObject release];
        _delegatingObject = [object retain];
        
        _delegatingObject.delegate = self;
    }
}

-(void)setFree:(BOOL)free {
    _free = free;
    if (_free && [self.delegate respondsToSelector:@selector(employeeDidBecomeFree:)]) {
        [self.delegate employeeDidBecomeFree:self];
        
    }

    [self notifyWithSelector:[self selectorForState:free]];
}

#pragma mark -
#pragma mark Public Methods

- (SEL)selectorForState:(BOOL)state {
    return (state) ? @selector(employeeDidBecomeFree:) : @selector(employeeDidBecomeNotFree:);
}

- (void)perfomWorkWithObject:(TYVMoneyKeeper *)anObject {
    self.free = NO;
    [self takeMoney:anObject.money fromMoneykeeper:anObject];
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

#pragma mark -
#pragma mark Private Methods

- (void)notifyWithSelector:(SEL)selector {
    NSHashTable *observers = self.observersHashTable;
    NSLog(@"Count = %lu", (unsigned long)[observers count]);
    for (id observer in observers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:self];
        }
    }
}

#pragma mark -
#pragma mark TYVEmployeeDelegate

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object {
    [self perfomWorkWithObject:employee];
}

@end
