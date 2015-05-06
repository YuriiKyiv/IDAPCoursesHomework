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

- (void)hireWashers;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableBuildings = nil;
    self.employees = nil;
    self.director = nil;
    
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
    [self hireWashers];
}

- (void)work {
    TYVCar *car = [TYVCar object];
    
    TYVWasher *washer = [self.employees freeEmployeeWithClass:[TYVWasher class]];
    [washer perfomWorkWithObject:car];
    
    TYVAccountant *accountant = [self.employees freeEmployeeWithClass:[TYVAccountant class]];
    [accountant perfomWorkWithObject:washer];
    
    TYVDirector *director = self.director;
    [director perfomWorkWithObject:accountant];
}

#pragma mark -
#pragma mark Private Methods

- (void)hireAdminStaff {
    TYVAccountant *accountant = [TYVAccountant object];
    TYVDirector *director = [TYVDirector object];
    
    [self.employees addEmployee:accountant];
    self.director = director;
    
    accountant.delegate = director;
    director.delegatingObject = accountant;
}

- (void)hireWashers {
    TYVEmployeesPool *pool = self.employees;
    TYVAccountant *accountant = [pool freeEmployeeWithClass:[TYVAccountant class]];
    TYVWasher *washer = nil;
    
    NSUInteger count = arc4random_uniform(1000);
    for (NSUInteger iter = 0; iter < count; iter++) {
        washer = [TYVWasher object];
        washer.experience = iter;
        washer.delegate = accountant;
        accountant.delegatingObject = washer;
        [pool addEmployee:washer];
    }
}

@end
