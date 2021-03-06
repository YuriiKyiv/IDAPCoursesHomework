//
//  TYVCarwashEnterprise.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashEnterprise.h"
#import "TYVWasher.h"
#import "TYVAccountant.h"
#import "TYVDirector.h"
#import "TYVRoom.h"
#import "TYVCarwashRoom.h"
#import "TYVCar.h"
#import "TYVBuilding.h"
#import "TYVEmployeesPool.h"
#import "TYVQueue.h"
#import "TYVDispatcher.h"

#import "NSObject+TYVNSObjectExtensions.h"

static const NSUInteger kTYVMaxEmployeeCount = 23;

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)   TYVDispatcher   *washerDispatcher;
@property (nonatomic, retain)   TYVDispatcher   *accountantDispatcher;
@property (nonatomic, retain)   TYVDispatcher   *directorDispatcher;

- (void)hireDirector;

- (void)hireWashers;

- (void)hireAccountants;

- (void)removeConnections;

- (void)removeConnectionsWithDispatcher:(TYVDispatcher *)dispathcer;

- (void)hireEmployeesWithClass:(Class)class dispatcher:(TYVDispatcher *)dispatcher;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeConnections];
    
    self.washerDispatcher = nil;
    self.accountantDispatcher = nil;
    self.directorDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.washerDispatcher = [TYVDispatcher object];
        self.accountantDispatcher = [TYVDispatcher object];
        self.directorDispatcher = [TYVDispatcher object];
        
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hireStaff {
    [self hireDirector];
    [self hireWashers];
    [self hireAccountants];
}

- (void)washCar:(TYVCar *)car {
    [self.washerDispatcher addProcessingObject:car];
}

#pragma mark -
#pragma mark Private Methods

- (void)hireDirector {
    [self.directorDispatcher addHandler:[TYVDirector object]];
}

- (void)hireWashers {
    [self hireEmployeesWithClass:[TYVWasher class]
                      dispatcher:self.washerDispatcher];
}

- (void)hireAccountants {
    [self hireEmployeesWithClass:[TYVAccountant class]
                      dispatcher:self.accountantDispatcher];
}

- (void)hireEmployeesWithClass:(Class)class dispatcher:(TYVDispatcher *)dispatcher {
    NSUInteger randomWashersCount = 1 + arc4random_uniform(kTYVMaxEmployeeCount);
    NSLog(@"%@ count = %lu", class,(unsigned long)randomWashersCount);
    for (NSUInteger index = 0; index < randomWashersCount; index++) {
        TYVEmployee *employee = [class object];
        employee.experience = index;
        [employee addObserver:self];
        [dispatcher addHandler:employee];
    }
}

- (void)removeConnections {
    [self removeConnectionsWithDispatcher:self.directorDispatcher];
    [self removeConnectionsWithDispatcher:self.accountantDispatcher];
    [self removeConnectionsWithDispatcher:self.washerDispatcher];
}

- (void)removeConnectionsWithDispatcher:(TYVDispatcher *)dispathcer {
    NSSet *employeesSet = [dispathcer handlersSet];
    for (TYVEmployee *handler in employeesSet) {
        [handler removeObserver:self];
    }
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    if ([employee isMemberOfClass:[TYVWasher class]]) {
        [self.accountantDispatcher addProcessingObject:employee];
    } else if ([employee isMemberOfClass:[TYVAccountant class]]) {
        [self.directorDispatcher addProcessingObject:employee];
    }
}

@end
