//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyKeeper.h"
#import "TYVMoneyTransfer.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@class TYVEmployee;

typedef NS_ENUM(NSUInteger, TYVEmployeeState) {
    TYVEmployeeDidBecomeFree,
    TYVEmployeeDidBecomeBusy,
    TYVEmployeeDidPerfomWorkWithObject
};

@protocol TYVEmployeeObserver <NSObject>

@optional
- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

- (void)employeeDidBecomeBusy:(TYVEmployee *)employee;

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object;

@end

@interface TYVEmployee : NSObject <TYVEmployeeObserver, TYVMoneyTransfer>
@property (nonatomic, readonly) NSString            *duty;

@property (nonatomic, readonly) NSDecimalNumber     *salary;
@property (nonatomic, assign)   NSUInteger          experience;

@property (nonatomic, assign)   TYVEmployeeState    state;

@property (nonatomic, readonly) NSSet               *observersSet;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

- (void)workWithObject:(id)object;

- (void)perfomWorkWithObject:(id<TYVMoneyTransfer>)object;

- (void)addObserver:(id)observer;

- (void)removeObserver:(id)observer;

- (BOOL)containsObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

- (void)notifyWithSelector:(NSString *)stringSelector;

@end
