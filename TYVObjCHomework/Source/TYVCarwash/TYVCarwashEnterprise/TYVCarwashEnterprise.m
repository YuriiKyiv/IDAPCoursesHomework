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

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)   TYVQueue            *cars;

@property (nonatomic, retain)   NSMutableArray      *mutableBuildings;
@property (nonatomic, retain)   TYVEmployeesPool    *employees;

@property (nonatomic, retain)   TYVDirector         *director;

- (void)hireAdminStaff;

- (void)hireWasher;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableBuildings = nil;
    self.employees = nil;
    self.director = nil;
    self.cars = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self prepareBuildings];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)prepareBuildings {
    NSMutableArray *buildings = [NSMutableArray array];
    
    for(int i = 0; i < 2; i++) {
        [buildings addObject:[TYVBuilding object]];
    }
    
    self.mutableBuildings = buildings;
}

- (void)hireStaff {
    self.employees = [TYVEmployeesPool pool];
    [self hireAdminStaff];
    [self hireWasher];
}

- (void)work {
    self.cars = [[[TYVQueue alloc] init] autorelease];
    TYVQueue *queue = self.cars;
    for (NSUInteger i = 0; i < 10; i++) {
        [queue enqueueObject:[TYVCar object]];
    }
    
    TYVWasher *washer = [self.employees freeEmployeeWithClass:[TYVWasher class]];
    [washer perfomWorkWithObject:[queue dequeueObject]];
    
}

#pragma mark -
#pragma mark Private Methods

- (void)hireAdminStaff {
    TYVAccountant *accountant = [TYVAccountant object];
    TYVDirector *director = [TYVDirector object];
    
    [self.employees addEmployee:accountant];
    self.director = director;
    
    director.subordinate = accountant;
}

- (void)hireWasher {
    TYVEmployeesPool *pool = self.employees;
    TYVAccountant *accountant = [pool freeEmployeeWithClass:[TYVAccountant class]];
    TYVWasher *washer = [TYVWasher object];
    [pool addObservableEmployee:washer withObserver:self];
    accountant.subordinate = washer;
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVEmployee *)employee {
    TYVQueue *cars = self.cars;
    if (!cars.isEmpty) {
        [employee perfomWorkWithObject:[cars dequeueObject]];
    }
}

- (void)employeeDidBecomeBusy:(TYVEmployee *)employee {
    NSLog(@"Employee is starting to work");
}

@end
