//
//  TYVEmployeesPool.h
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVEmployee;

@interface TYVEmployeesPool : NSObject

- (void) addEmployee:(TYVEmployee *)enEmployee;

- (void) removeEmployee:(TYVEmployee *)enEmployee;

- (TYVEmployee *) freeEmployeeWithClass:(Class)class;

- (NSArray *) freeEmployeesWithClass:(Class)class;

@end
