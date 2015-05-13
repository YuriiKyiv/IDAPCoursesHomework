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

typedef NS_ENUM(NSUInteger, TYVEmployeeState) {
    TYVEmployeeDidBecomeFree,
    TYVEmployeeDidBecomeBusy,
    TYVEmployeeDidPerfomWorkWithObject
};

@protocol TYVEmployeeDelegate <NSObject>

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object;

@optional
- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

@end

@protocol TYVEmployeeObserver <NSObject>

- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

- (void)employeeDidBecomeBusy:(TYVEmployee *)employee;

@end

@interface TYVEmployee : TYVMoneyKeeper <TYVEmployeeDelegate>
@property (nonatomic, readonly)                 NSString                *duty;

@property (nonatomic, readonly)                 NSDecimalNumber         *salary;
@property (nonatomic, assign)                   NSUInteger              experience;

@property (nonatomic, assign, getter=isFree)    BOOL                    free;

@property (nonatomic, readonly)                 NSSet                   *observersSet;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

- (void)perfomWorkWithObject:(id)object;

- (void)perfomWorkWithObjectInBackground:(TYVMoneyKeeper *)object;

- (void)addObserver:(id)observer;

- (void)removeObserver:(id)observer;

- (BOOL)containsObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

- (void)notifyWithSelector:(SEL)selector;

@end
