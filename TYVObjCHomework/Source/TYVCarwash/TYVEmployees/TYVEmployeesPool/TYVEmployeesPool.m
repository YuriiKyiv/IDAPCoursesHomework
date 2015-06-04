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
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeesSet;

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
    @synchronized(self) {
        __block TYVEmployee *employee = nil;
        [self.mutableEmployeesSet enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
            employee = obj;
            if ([employee isMemberOfClass:class] && employee.state == TYVEmployeeDidBecomeFree) {
                *stop = YES;
            } else {
                employee = nil;
            }
        }];
    
        return employee;
    }
}

- (id)freeEmployee {
    @synchronized(self) {
        __block TYVEmployee *employee = nil;
        [self.mutableEmployeesSet enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
            employee = obj;
            if (employee.state == TYVEmployeeDidBecomeFree) {
                *stop = YES;
            } else {
                employee = nil;
            }
        }];
        
        return employee;
    }
}

- (NSSet *)freeEmployeesWithClass:(Class)class {
    @synchronized(self) {
        NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(TYVEmployee *evaluatedObject, NSDictionary *bindings) {
        return ([evaluatedObject isMemberOfClass:class]
                && evaluatedObject.state == TYVEmployeeDidBecomeFree);
        }];
    
        return [self.mutableEmployeesSet filteredSetUsingPredicate:predicate];
        
    }
}

- (NSSet *)employeesWithClass:(Class)class {
    @synchronized(self) {
        NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary *bindings) {
            return ([evaluatedObject isMemberOfClass:class]);
        }];
    
        return [self.mutableEmployeesSet filteredSetUsingPredicate:predicate];
        
    }
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

@end
