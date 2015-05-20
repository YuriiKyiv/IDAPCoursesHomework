//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVProtocolObservableObject.h"
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

- (void)employeeDidPerfomWork:(TYVEmployee *)employee;

@end

@interface TYVEmployee : TYVProtocolObservableObject <TYVEmployeeObserver, TYVMoneyTransfer>
@property (nonatomic, readonly) NSString            *duty;

@property (nonatomic, readonly) NSDecimalNumber     *salary;
@property (nonatomic, assign)   NSUInteger          experience;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

- (void)workWithObject:(id<TYVMoneyTransfer>)object;

- (void)perfomWorkWithObject:(id<TYVMoneyTransfer>)object;

@end
