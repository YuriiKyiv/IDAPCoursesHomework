//
//  TYVEmployeesPool.m
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"

#import "NSSet+TYVExtentions.h"

@interface TYVEmployeesPool ()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeesSet;

- (void)initBlocks;

@end

@implementation TYVEmployeesPool

@dynamic employeesSet;

#pragma mark -
#pragma mark Class Methods

+ (TYVEmployeesPool *)pool {
    @synchronized(self) {
        return [[[TYVEmployeesPool alloc] init] autorelease];
    }
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableEmployeesSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployeesSet = [NSMutableSet set];
        [self initBlocks];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)employeesSet {
    @synchronized (self) {
        return [[self.mutableEmployeesSet copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addEmployee:(TYVEmployee *)employee {
    @synchronized(self) {
        [self.mutableEmployeesSet addObject:employee];
    }
}

- (void)removeEmployee:(TYVEmployee *)employee {
    @synchronized(self) {
        [self.mutableEmployeesSet removeObject:employee];
    }
}

- (id)freeEmployeeWithClass:(Class)class {
    return [self.mutableEmployeesSet objectWithBlock:^(TYVEmployee *employee) {
        return (BOOL)([employee isMemberOfClass:class]
                      && employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (id)freeEmployee {
    return [self.mutableEmployeesSet objectWithBlock:^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (NSSet *)freeEmployeesWithClass:(Class)class {
    return [self.mutableEmployeesSet objectsWithBlock:^(TYVEmployee *employee) {
        return (BOOL)([employee isMemberOfClass:class]
                      && employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (NSSet *)employeesWithClass:(Class)class {
    return [self.mutableEmployeesSet objectWithBlock:^(TYVEmployee *employee) {
        return (BOOL)([employee isMemberOfClass:class]);
    }];
}

- (BOOL)containsEmployee:(TYVEmployee *)employee {
    @synchronized(self) {
        return [self.mutableEmployeesSet containsObject:employee];
    }
}

- (NSUInteger)count {
    @synchronized(self) {
        return [self.mutableEmployeesSet count];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)initBlocks {
//    TYVFindObjectBlock employeeClassBlock = ^(TYVEmployee *employee) {
//        return (BOOL)([employee isMemberOfClass:class]
//                      && employee.state == TYVEmployeeDidBecomeFree);
//    };
    
//    TYVFindObjectBlock employeeBlock = ^(TYVEmployee *employee) {
//        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
//    };
}

- (TYVFindObjectBlock)freeEmployeeBlock {
    return ^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
    };
}

@end
