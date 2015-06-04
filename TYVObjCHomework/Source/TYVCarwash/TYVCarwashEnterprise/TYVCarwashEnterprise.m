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

static const NSUInteger kTYVMaxWasharsCount = 23;

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)   TYVDirector         *director;

@property (nonatomic, retain)   TYVDispatcher       *washerDispatcher;

- (void)hireAdminStaff;

- (void)hireWashers;

- (void)removeEmployeesConnections;

- (void)giveWorkToWasher:(TYVWasher *)washer;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeEmployeesConnections];
    self.director = nil;
    
    self.washerDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.washerDispatcher = [TYVDispatcher object];
        
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hireStaff {
    [self hireAdminStaff];
    [self hireWashers];
}

- (void)washCar:(TYVCar *)car {
    [self.washerDispatcher addProcessingObject:car];
}

#pragma mark -
#pragma mark Private Methods

- (void)hireAdminStaff {
    
}

- (void)hireWashers {
    NSUInteger randomWashersCount = arc4random_uniform(kTYVMaxWasharsCount);
    NSLog(@"Washers count = %lu", (unsigned long)randomWashersCount);
    TYVDispatcher *dispatcher = self.washerDispatcher;
    for (NSUInteger index = 0; index < randomWashersCount; index++) {
        TYVWasher *washer = [TYVWasher object];
        washer.experience = index;
        [washer addObserver:self];
        [dispatcher addHandler:washer];
        
    }
}

- (void)removeEmployeesConnections {

}

- (void)giveWorkToWasher:(TYVWasher *)washer {

}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVWasher *)washer {
}

@end
