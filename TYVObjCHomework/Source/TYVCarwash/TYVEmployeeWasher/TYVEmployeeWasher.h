//
//  TYVEmployeeWasher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVCar.h"
#import "TYVEmployeeAccountant.h"

@interface TYVEmployeeWasher : TYVEmployee

@property (nonatomic, retain)   TYVCar  *car;

- (void)wash;

- (void)takeMoney;

- (void)giveMoneyToAccountant:(TYVEmployeeAccountant *)accountant;

@end
