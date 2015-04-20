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

@interface TYVCarwashEnterprise ()

@property (nonatomic, retain)    TYVCarwashBuilding    *carwashBuilding;
@property (nonatomic, retain)    TYVBuilding           *building;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.carwashBuilding = [TYVCarwashBuilding object];
        self.building = [TYVBuilding object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hirePersonal {
    TYVEmployeeWasher *washer = [TYVEmployeeWasher object];
    TYVEmployeeAccountant *accountant = [TYVEmployeeAccountant object];
    TYVEmployeeDirector *director = [TYVEmployeeDirector object];
    
    TYVRoom *room = [[[TYVRoom alloc] initWithHumanCount:2] autorelease];
    [room addHuman:accountant];
    [room addHuman:director];
    
    TYVCarwashRoom *carwashRoom = [[[TYVCarwashRoom alloc] initWithHumanCount:1 carCount:1] autorelease];
    [carwashRoom addHuman:washer];
    
    [self.carwashBuilding addCarwashRoom:carwashRoom];
    [self.building addRoom:room];
}

@end
