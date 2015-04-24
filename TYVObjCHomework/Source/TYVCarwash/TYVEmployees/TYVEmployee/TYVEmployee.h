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

@interface TYVEmployee : TYVMoneyKeeper
@property (nonatomic, readonly)                 NSString           *duty;

@property (nonatomic, readonly)                 NSDecimalNumber    *salary;
@property (nonatomic, readonly)                 NSUInteger         experience;

@property (nonatomic, assign, getter=isFree)    BOOL               free;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money;

- (void)work;

@end
