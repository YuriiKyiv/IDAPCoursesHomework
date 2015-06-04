//
//  TYVEmployeesPool.h
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVEmployee;

@protocol TYVDelegatingEmployee <NSObject>
@property (nonatomic, assign)   id  delegate;

@end

@interface TYVEmployeesPool : NSObject
@property (nonatomic, readonly)   NSSet    *employeesSet;

+ (TYVEmployeesPool *)pool;

- (void)addEmployee:(TYVEmployee *)employee;

- (void)removeEmployee:(TYVEmployee *)employee;

- (id)freeEmployeeWithClass:(Class)class;

- (id)freeEmployee;

- (NSSet *)freeEmployeesWithClass:(Class)class;

- (NSSet *)employeesWithClass:(Class)class;

- (BOOL)containsEmployee:(TYVEmployee *)employee;

- (NSUInteger)count;

@end
