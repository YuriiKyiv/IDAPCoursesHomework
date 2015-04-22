//
//  TYVAccountant.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVAccountant : TYVEmployee
@property (nonatomic, readonly)    NSDecimalNumber    *capital;

- (void)count;

@end
