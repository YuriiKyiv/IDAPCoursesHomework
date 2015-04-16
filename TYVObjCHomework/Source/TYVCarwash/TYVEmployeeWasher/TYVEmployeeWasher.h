//
//  TYVEmployeeWasher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVCar.h"

@interface TYVEmployeeWasher : TYVEmployee

- (void)take:(TYVCar *)aCar;

- (void)wash:(TYVCar *)aCar;

@end
