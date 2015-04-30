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

+ (TYVEmployeesPool *)pool {
    return [[[TYVEmployeesPool alloc] init] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addEmployee:(TYVEmployee *)anEmployee {
    [self.employees addObject:anEmployee];
}

- (void)removeEmployee:(TYVEmployee *)anEmployee {
    [self.employees removeObject:anEmployee];
}

- (id)freeEmployeeWithClass:(Class)class {
    __block TYVEmployee *employee = nil;
    [self.employees enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        employee = obj;
        if ([employee isKindOfClass:class] && employee.isFree == YES) {
            *stop = YES;
        }
    }];
    
    return employee;
}

- (NSArray *)freeEmployeesWithClass:(Class)class {
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF isKindOfClass: %@ && SELF.isFree == YES", class];
    return [self.employees filteredArrayUsingPredicate:predicate];
}

- (NSArray *)employeesWithClass:(Class)class {
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF isKindOfClass: %@", class];
    return [self.employees filteredArrayUsingPredicate:predicate];
}

- (BOOL)containsEmployee:(TYVEmployee *)anEmployee {
    return [self.employees containsObject:anEmployee];
}

- (NSUInteger)count {
    return [self.employees count];
}

@end
