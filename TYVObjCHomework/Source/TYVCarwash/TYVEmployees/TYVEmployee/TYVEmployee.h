//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyFlow.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@interface TYVEmployee : TYVMoneyFlow
@property (nonatomic, readonly)    NSDecimalNumber    *money;
@property (nonatomic, readonly)    NSString           *duty;

@property (nonatomic, readonly)    NSDecimalNumber    *salary;
@property (nonatomic, readonly)    NSUInteger         experience;

- (void)work;

@end
