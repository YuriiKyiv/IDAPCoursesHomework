//
//  TYVWasher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"
#import "TYVCar.h"

@interface TYVWasher : TYVEmployee
@property (nonatomic, retain)       TYVCar             *car;
@property (nonatomic, readonly)     NSDecimalNumber    *price;

- (void)wash;

@end
