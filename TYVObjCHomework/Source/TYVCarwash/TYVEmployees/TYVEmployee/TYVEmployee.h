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
#import "TYVEmployeeObserverProtocol.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@class TYVEmployee;

typedef NS_ENUM(NSUInteger, TYVEmployeeState) {
    TYVEmployeeDidBecomeFree,
    TYVEmployeeDidBecomeBusy,
    TYVEmployeeDidPerformWorkWithObject
};

@interface TYVEmployee : TYVProtocolObservableObject <TYVEmployeeObserverProtocol, TYVMoneyTransfer>
@property (nonatomic, readonly) NSString            *duty;

@property (nonatomic, readonly) NSDecimalNumber     *salary;
@property (nonatomic, assign)   NSUInteger          experience;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

// For overriding method
- (void)proccesWithObject:(id<TYVMoneyTransfer>)object;

// For overriding method
- (void)finalizeProccesingWithObjectOnMainThread:(id<TYVMoneyTransfer>)object;

- (void)performWorkWithObject:(id<TYVMoneyTransfer>)object;

@end
