//
//  TYVEmployeesPool.m
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"

typedef BOOL(^TYVFindEmployeeBlock)(TYVEmployee *);

@interface TYVEmployeesPool ()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeesSet;
@property (nonatomic, retain)   NSDictionary    *blocks;

- (id)employeeWithBlock:(BOOL(^)(TYVEmployee *))block;
- (id)employeesWithBlock:(BOOL(^)(TYVEmployee *))block;

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
    return [self employeeWithBlock:^(TYVEmployee *employee) {
        return (BOOL)([employee isMemberOfClass:class]
                      && employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (id)freeEmployee {
    return [self employeeWithBlock:^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (NSSet *)freeEmployeesWithClass:(Class)class {
    return [self employeesWithBlock:^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree
                      && employee.state == TYVEmployeeDidBecomeFree);
    }];
}

- (NSSet *)employeesWithClass:(Class)class {
    return [self employeesWithBlock:^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
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

- (id)employeeWithBlock:(BOOL(^)(TYVEmployee *))block {
    @synchronized(self) {
        __block TYVEmployee *employee = nil;
        [self.mutableEmployeesSet enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
            employee = obj;
            if (block(employee)) {
                *stop = YES;
            } else {
                employee = nil;
            }
        }];
        
        return employee;
    }
}

- (id)employeesWithBlock:(BOOL(^)(TYVEmployee *))block {
    @synchronized (self) {
        NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(TYVEmployee *evaluatedObject, NSDictionary *bindings) {
            return block(evaluatedObject);
        }];
        
        return [self.mutableEmployeesSet filteredSetUsingPredicate:predicate];
    }
}

- (void)initBlocks {
    TYVFindEmployeeBlock employeeClassBlock = ^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree
                      && employee.state == TYVEmployeeDidBecomeFree);
    };
    
    TYVFindEmployeeBlock employeeBlock = ^(TYVEmployee *employee) {
        return (BOOL)(employee.state == TYVEmployeeDidBecomeFree);
    };
    
    self.blocks = @{@"employeeWithClass" : employeeClassBlock,
                    @"employee" : employeeBlock};
}

@end
