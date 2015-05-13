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

static const NSUInteger kTYVMaxWasharsCount = 50;
static const NSUInteger kTYVMaxCarsCount = 1000;

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
    TYVQueue *carsQueue = self.cars;
    for (NSUInteger i = 0; i < kTYVMaxCarsCount; i++) {
        [carsQueue enqueueObject:[TYVCar object]];
    }
    
//    TYVWasher *washer = [self.employees freeEmployeeWithClass:[TYVWasher class]];
//    [washer perfomWorkWithObject:[carsQueue dequeueObject]];
    
    TYVWasher *washer = nil;
    while (!carsQueue.isEmpty && (washer = [self.employees freeEmployeeWithClass:[TYVWasher class]])) {
        [washer perfomWorkWithObjectInBackground:[carsQueue dequeueObject]];
    }
    
    while (true) {
    
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
}

- (void)hireWasher {
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

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVWasher *)washer {
    TYVQueue *cars = self.cars;
    if (!cars.isEmpty) {
        [washer perfomWorkWithObjectInBackground:[cars dequeueObject]];
    } else {
        NSLog(@"Cars queue is empty");
    }
}

- (void)employeeDidBecomeBusy:(TYVEmployee *)employee {
    NSLog(@"Employee is starting to work");
}

@end
