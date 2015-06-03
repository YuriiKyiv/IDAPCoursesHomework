//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVProtocolObservableObject.h"
#import "TYVMoneyTransferProtocol.h"
#import "TYVEmployeeObserverProtocol.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@class TYVEmployee;

typedef NS_ENUM(NSUInteger, TYVEmployeeState) {
    TYVEmployeeDidBecomeFree,
    TYVEmployeeDidBecomeBusy,
    TYVEmployeeDidPerformWorkWithObject
};

@interface TYVEmployee : TYVProtocolObservableObject <TYVEmployeeObserverProtocol, TYVMoneyTransferProtocol>
@property (nonatomic, readonly) NSString            *duty;

@property (nonatomic, readonly) NSDecimalNumber     *salary;
@property (nonatomic, assign)   NSUInteger          experience;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

// This is the method for overriding
// Do not call a message directly
- (void)processWithObject:(id<TYVMoneyTransferProtocol>)object;

// This is the method for overriding
// Do not call a message directly
- (void)finalizeProcessingWithObjectOnMainThread:(id<TYVMoneyTransferProtocol>)object;

- (void)performWorkWithObject:(id<TYVMoneyTransferProtocol>)object;

@end
