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

#import "NSObject+TYVNSObjectExtensions.h"

static const NSUInteger kTYVMaxWasharsCount = 23;

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)   TYVQueue            *cars;

@property (nonatomic, retain)   TYVEmployeesPool    *employees;

@property (nonatomic, retain)   TYVDirector         *director;

- (void)hireAdminStaff;

- (void)hireWashers;

- (void)killEmployeesConnections;

- (void)giveWorkToWasher:(TYVWasher *)washer;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self killEmployeesConnections];
    
    self.employees = nil;
    self.director = nil;
    self.cars = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hireStaff {
    self.employees = [TYVEmployeesPool pool];
    [self hireAdminStaff];
    [self hireWashers];
}

- (void)addCar:(TYVCar *)car {
    @synchronized (self) {
        TYVWasher *washer = [self.employees freeEmployeeWithClass:[TYVWasher class]];
        if (washer) {
            [washer performWorkWithObject:car];
        } else {
            [self.cars enqueueObject:car];
        }
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)hireAdminStaff {
    TYVAccountant *accountant = [TYVAccountant object];
    TYVDirector *director = [TYVDirector object];
    
    [self.employees addEmployee:accountant];
    self.director = director;
    [accountant addObserver:director];
    [accountant addObserver:accountant];
}

- (void)hireWashers {
    TYVEmployeesPool *pool = self.employees;
    TYVAccountant *accountant = [pool freeEmployeeWithClass:[TYVAccountant class]];
    NSUInteger randomWashersCount = arc4random_uniform(kTYVMaxWasharsCount);
    for (NSUInteger index = 0; index < randomWashersCount; index++) {
        TYVWasher *washer = [TYVWasher object];
        [washer addObserver:accountant];
        [washer addObserver:self];
        [pool addEmployee:washer];
        washer.experience = index;
    }
}

- (void)killEmployeesConnections {
    NSSet *washersSet = [self.employees employeesWithClass:[TYVWasher class]];
    NSSet *accountantsSet = [self.employees employeesWithClass:[TYVAccountant class]];
    for (TYVEmployee *employee in washersSet) {
        [employee removeObserver:self];
        for (TYVAccountant *accountant in accountantsSet) {
            [employee removeObserver:accountant];
        }
    }
    
    for (TYVEmployee *employee in accountantsSet) {
        [employee removeObserver:self.director];
    }
}

- (void)giveWorkToWasher:(TYVWasher *)washer {
    @synchronized (self) {
        TYVQueue *cars = self.cars;
        if (!cars.isEmpty && TYVEmployeeDidBecomeFree == washer.state) {
            [washer performWorkWithObject:[cars dequeueObject]];
        }
    }

}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVWasher *)washer {
    [self giveWorkToWasher:washer];
}

@end
