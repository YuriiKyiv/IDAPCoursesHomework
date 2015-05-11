//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyKeeper.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@class TYVEmployee;

@protocol TYVEmployeeDelegate <NSObject>

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object;

@optional
- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

@end

@protocol TYVEmployeeObserver <NSObject>

- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

- (void)employeeDidBecomeNotFree:(TYVEmployee *)employee;

@end

@interface TYVEmployee : TYVMoneyKeeper <TYVEmployeeDelegate>
@property (nonatomic, readonly)                 NSString                *duty;

@property (nonatomic, readonly)                 NSDecimalNumber         *salary;
@property (nonatomic, assign)                   NSUInteger              experience;

@property (nonatomic, assign, getter=isFree)    BOOL                    free;

@property (nonatomic, assign)                   id<TYVEmployeeDelegate> delegate;
@property (nonatomic, retain)                   TYVEmployee             *subordinate;

@property (nonatomic, readonly)                 NSSet                   *observersSet;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

- (void)perfomWorkWithObject:(id)anObject;

- (void)addObserver:(id)observer;

- (void)removeObserver:(id)observer;

- (BOOL)containsObserver:(id)observer;

- (SEL)selectorForState:(BOOL)state;

@end
