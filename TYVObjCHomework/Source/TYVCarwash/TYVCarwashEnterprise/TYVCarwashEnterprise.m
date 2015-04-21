//
//  TYVCarwashEnterprise.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashEnterprise.h"
#import "NSObject+TYVNSObjectExtensions.h"
#import "TYVEmployeeWasher.h"
#import "TYVEmployeeAccountant.h"
#import "TYVEmployeeDirector.h"
#import "TYVRoom.h"
#import "TYVCarwashRoom.h"
#import "TYVCar.h"

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)    TYVCarwashBuilding         *carwashBuilding;
@property (nonatomic, retain)    TYVBuilding                *building;

@property (nonatomic, retain)    NSMutableArray             *mutableWashers;
@property (nonatomic, retain)    NSMutableArray             *mutableAccountants;

@property (nonatomic, retain)    TYVEmployeeDirector        *director;

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
        self.carwashBuilding = [TYVCarwashBuilding object];
        self.building = [TYVBuilding object];
        self.mutableAccountants = [NSMutableArray array];
        self.mutableWashers = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hirePersonal {
    TYVEmployeeWasher *washer = [TYVEmployeeWasher object];
    [self.mutableWashers addObject:washer];
    TYVEmployeeAccountant *accountant = [TYVEmployeeAccountant object];
    [self.mutableAccountants addObject:accountant];
    TYVEmployeeDirector *director = [TYVEmployeeDirector object];
    self.director = director;
    
    TYVRoom *room = [[[TYVRoom alloc] initWithHumanCount:2] autorelease];
    [room addHuman:accountant];
    [room addHuman:director];
    
    TYVCarwashRoom *carwashRoom = [[[TYVCarwashRoom alloc] initWithHumanCount:1 carCount:1] autorelease];
    [carwashRoom addHuman:washer];
    
    [self.carwashBuilding addCarwashRoom:carwashRoom];
    [self.building addRoom:room];
}

- (void)work {
    TYVCar *car = [TYVCar object];
    NSArray * carwashrooms = self.carwashBuilding.carwashrooms;
    [[carwashrooms lastObject] addCar:car];
}

@end
