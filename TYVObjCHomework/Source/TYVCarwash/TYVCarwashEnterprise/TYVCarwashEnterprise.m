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

#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)    TYVCarwashBuilding         *carwashBuilding;
@property (nonatomic, retain)    TYVBuilding                *building;

@property (nonatomic, retain)    NSMutableArray             *mutableWashers;
@property (nonatomic, retain)    NSMutableArray             *mutableAccountants;

@property (nonatomic, retain)    TYVDirector                *director;

- (TYVEmployee *)getFreeEmployee:(NSMutableArray *)array;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.carwashBuilding = nil;
    self.building = nil;
    self.mutableAccountants = nil;
    self.mutableWashers = nil;
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
    self.carwashBuilding = [TYVCarwashBuilding object];
    self.building = [TYVBuilding object];
    
    TYVRoom *room = [[[TYVRoom alloc] initWithHumanCount:2] autorelease];
    TYVCarwashRoom *carwashRoom = [[[TYVCarwashRoom alloc] initWithHumanCount:1 carCount:1] autorelease];
    
    [self.carwashBuilding addCarwashRoom:carwashRoom];
    [self.building addRoom:room];
}

- (void)hireStaff {
    self.mutableAccountants = [NSMutableArray array];
    self.mutableWashers = [NSMutableArray array];
    
    TYVWasher *washer = [TYVWasher object];
    [self.mutableWashers addObject:washer];
    TYVAccountant *accountant = [TYVAccountant object];
    [self.mutableAccountants addObject:accountant];
    TYVDirector *director = [TYVDirector object];
    self.director = director;
    
    NSArray *rooms = self.building.rooms;
    [rooms[0] addHuman:accountant];
    [rooms[0] addHuman:director];
    
    NSArray *carwashRooms = self.carwashBuilding.rooms;
    [carwashRooms[0] addHuman:washer];
}

- (void)work {
//    TYVCar *car = [TYVCar object];
//    NSArray * carwashrooms = self.carwashBuilding.carwashrooms;
//    [[carwashrooms lastObject] addCar:car];
//    
//    TYVWasher *washer = (TYVWasher *)[self getFreeEmployee:self.mutableWashers];
//    washer.car = car;
//    [washer wash];
//    washer.car = nil;
//    
//    TYVAccountant * accountant = self.mutableAccountants[0];
//    [accountant takeMoney:washer.money fromMoneykeeper:washer];
//    [accountant count];
//    
//    TYVDirector *director = self.director;
//    [director takeMoney:accountant.money fromMoneykeeper:accountant];
//    [director profit];
}

#pragma mark -
#pragma mark Private Methods

- (TYVEmployee *)getFreeEmployee:(NSMutableArray *)array {
    for (TYVEmployee *employee in array) {
        if (employee.isFree) {
            return employee;
        }
    }
    
    return nil;
}

@end
