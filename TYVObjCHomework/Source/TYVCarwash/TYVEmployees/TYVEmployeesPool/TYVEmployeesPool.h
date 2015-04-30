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

+ (TYVEmployeesPool *) pool;

- (void)addEmployee:(TYVEmployee *)anEmployee;

- (void)removeEmployee:(TYVEmployee *)anEmployee;

- (id)freeEmployeeWithClass:(Class)class;

- (NSArray *)freeEmployeesWithClass:(Class)class;

- (NSArray *)employeesWithClass:(Class)class;

- (BOOL)containsEmployee:(TYVEmployee *)anEmployee;

- (NSUInteger)count;

@end
