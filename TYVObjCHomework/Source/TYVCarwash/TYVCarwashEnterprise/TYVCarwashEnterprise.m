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
#import "TYVCarwashBuilding.h"
#import "TYVEmployeesPool.h"

#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)    NSMutableArray      *MutableBuildings;
@property (nonatomic, retain)    TYVEmployeesPool    *employees;

@property (nonatomic, retain)    TYVDirector         *director;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.MutableBuildings = nil;
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
    
    TYVWasher *washer = [TYVWasher object];
    TYVAccountant *accountant = [TYVAccountant object];
    TYVDirector *director = [TYVDirector object];
    
    [self.employees addEmployee:washer];
    [self.employees addEmployee:accountant];
    self.director = director;
    
    TYVRoom *adminRoom = [[[TYVRoom alloc] initWithHumanCount:2] autorelease];
    TYVCarwashRoom *carwashRoom = [[[TYVCarwashRoom alloc] initWithHumanCount:1 carCount:1] autorelease];
    
    [adminRoom addHuman:director];
    [adminRoom addHuman:accountant];
    
    [carwashRoom addHuman:washer];
    
    NSMutableArray *buildings = self.MutableBuildings;
    [buildings[0] addRoom:adminRoom];
    [buildings[1] addRoom:carwashRoom];
}

- (void)work {
    TYVCar *car = [TYVCar object];
    
    TYVWasher *washer = [self.employees freeEmployeeWithClass:[TYVWasher class]];
    [washer washCar:car];
    [washer takeMoney:washer.price fromMoneykeeper:car];
    
    TYVAccountant *accountant = [self.employees freeEmployeeWithClass:[TYVAccountant class]];
    [accountant takeMoney:washer.money fromMoneykeeper:washer];
    [accountant count];
    
    TYVDirector *director = self.director;
    [director takeMoney:accountant.capital fromMoneykeeper:accountant];
    [director profit];
}

#pragma mark -
#pragma mark Private Methods

@end