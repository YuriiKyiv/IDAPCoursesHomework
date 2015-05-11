//
//  TYVEmployeesPool.m
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"

@interface TYVEmployeesPool ()
@property (nonatomic, retain)   NSMutableSet    *employeesSet;

@end

@implementation TYVEmployeesPool


#pragma mark -
#pragma mark Class Methods

+ (TYVEmployeesPool *)pool {
    return [[[TYVEmployeesPool alloc] init] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.employeesSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.employeesSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)addEmployee:(TYVEmployee *)employee {
    [self.employeesSet addObject:employee];
}

- (void)removeEmployee:(TYVEmployee *)employee {
    [self.employeesSet removeObject:employee];
}

- (id)freeEmployeeWithClass:(Class)class {
    __block TYVEmployee *employee = nil;
    [self.employeesSet enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
        employee = obj;
        if ([employee isKindOfClass:class] && employee.isFree == YES) {
            *stop = YES;
        }
    }];
    
    return employee;
}

- (NSSet *)freeEmployeesWithClass:(Class)class {
    NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(TYVEmployee *evaluatedObject, NSDictionary *bindings) {
        return ([evaluatedObject isKindOfClass:class]
                && evaluatedObject.isFree);
    }];
    
    return [self.employeesSet filteredSetUsingPredicate:predicate];
}

- (NSSet *)employeesWithClass:(Class)class {
    NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary *bindings) {
        return ([evaluatedObject isKindOfClass:class]);
    }];
    
    return [self.employeesSet filteredSetUsingPredicate:predicate];
}

- (BOOL)containsEmployee:(TYVEmployee *)employee {
    return [self.employeesSet containsObject:employee];
}

- (NSUInteger)count {
    return [self.employeesSet count];
}

@end
