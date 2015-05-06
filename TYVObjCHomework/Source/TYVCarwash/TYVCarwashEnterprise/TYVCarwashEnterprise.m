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

#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)    NSMutableArray      *mutableBuildings;
@property (nonatomic, retain)    TYVEmployeesPool    *employees;

@property (nonatomic, retain)    TYVDirector         *director;

- (void)hireStaffForAdminBuildingWithRoom;

- (void)hireStaffForCarwashBuildingWithRoom;

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
    
    self.MutableBuildings = buildings;
}

- (void)hireStaff {
    self.employees = [TYVEmployeesPool pool];
    [self hireStaffForAdminBuildingWithRoom];
    [self hireStaffForCarwashBuildingWithRoom];
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

- (void)hireStaffForAdminBuildingWithRoom {
    TYVAccountant *accountant = [TYVAccountant object];
    TYVDirector *director = [TYVDirector object];
    
    [self.employees addEmployee:accountant];
    self.director = director;
    
    TYVRoom *adminRoom = [[[TYVRoom alloc] initWithHumanCapacity:2] autorelease];
    [adminRoom addHuman:director];
    [adminRoom addHuman:accountant];
    
    [self.mutableBuildings[0] addRoom:adminRoom];
}

- (void)hireStaffForCarwashBuildingWithRoom {
    TYVWasher *washer = [TYVWasher object];
    [self.employees addEmployee:washer];
    
    TYVCarwashRoom *carwashRoom = [[[TYVCarwashRoom alloc] initWithHumanCapacity:1 carCapacity:1] autorelease];
    [carwashRoom addHuman:washer];
    
    [self.mutableBuildings[1] addRoom:carwashRoom];
}

@end
