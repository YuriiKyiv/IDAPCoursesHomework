//
//  TYVEmployeesPool.m
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"

typedef BOOL(^TYVfunction)(TYVEmployee *employee, Class class);

@interface TYVEmployeesPool ()
@property (nonatomic, retain)   NSMutableArray    *employees;

- (TYVfunction) comparatorEmployeeWithClass;

@end

@implementation TYVEmployeesPool

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.employees = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.employees = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Class Methods

+ (TYVEmployeesPool *) pool {
    return [[[TYVEmployeesPool alloc] init] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void) addEmployee:(TYVEmployee *)anEmployee {
    [self.employees addObject:anEmployee];
}

- (void) removeEmployee:(TYVEmployee *)anEmployee {
    [self.employees removeObject:anEmployee];
}

- (TYVEmployee *) freeEmployeeWithClass:(Class)class {
    for (TYVEmployee *employee in self.employees) {
        if ([employee isKindOfClass:class] && employee.isFree) {
            return employee;
        }
    }
    
    return nil;
}

- (NSArray *) freeEmployeesWithClass:(Class)class {
    NSMutableArray *classEmployees = [NSMutableArray array];
    for (TYVEmployee *employee in self.employees) {
        if ([employee isKindOfClass:class] && employee.isFree) {
            [classEmployees addObject:employee];
        }
    }
    
    return [[classEmployees copy] autorelease];
}

- (NSArray *) employeesWithClass:(Class)class {
    NSMutableArray *classEmployees = [NSMutableArray array];
    for (TYVEmployee *employee in self.employees) {
        if ([employee isKindOfClass:class]) {
            [classEmployees addObject:employee];
        }
    }
    
    return [[classEmployees copy] autorelease];
}

- (BOOL) containsEmployee:(TYVEmployee *)anEmployee {
    return [self.employees containsObject:anEmployee];
}

- (NSUInteger) count {
    return [self.employees count];
}

#pragma mark -
#pragma mark Comparators

- (TYVfunction) comparatorEmployeeWithClass {
//    TYVfunction function = ^(TYVEmployee *employee, Class class) {
//        return ([employee isKindOfClass:class]);
//    };
//    
//    return [[function copy] autorelease];
    return nil;
}

@end
