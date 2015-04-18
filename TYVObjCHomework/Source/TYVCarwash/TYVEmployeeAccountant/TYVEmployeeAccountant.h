//
//  TYVEmployeeAccountant.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVEmployeeDirector.h"

@interface TYVEmployeeAccountant : TYVEmployee

- (void)count;

- (void)giveMoneyToDirector:(TYVEmployeeDirector *)aDirector;

- (void)takeMoney:(NSDecimalNumber *)money;

@end
