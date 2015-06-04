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

static const NSUInteger kTYVMaxEmployeeCount = 23;

@interface TYVCarwashEnterprise ()
@property (nonatomic, retain)   TYVDirector         *director;

@property (nonatomic, retain)   TYVDispatcher       *washerDispatcher;
@property (nonatomic, retain)   TYVDispatcher       *accountantDispatcher;

- (void)hireAdminStaff;

- (void)hireWashers;

- (void)hireAccountants;

- (void)giveWorkToWasher:(TYVWasher *)washer;

- (void)hireEmployeesWithClass:(Class)class dispatcher:(TYVDispatcher *)dispatcher;

@end

@implementation TYVCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.director = nil;
    
    self.washerDispatcher = nil;
    self.accountantDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.washerDispatcher = [TYVDispatcher object];
        self.accountantDispatcher = [TYVDispatcher object];
        
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)hireStaff {
    [self hireAdminStaff];
    [self hireWashers];
    [self hireAccountants];
}

- (void)washCar:(TYVCar *)car {
    [self.washerDispatcher addProcessingObject:car];
}

#pragma mark -
#pragma mark Private Methods

- (void)hireAdminStaff {
    self.director = [TYVDirector object];
}

- (void)hireWashers {
    [self hireEmployeesWithClass:[TYVWasher class]
                      dispatcher:self.washerDispatcher];
}

- (void)hireAccountants {
    [self hireEmployeesWithClass:[TYVAccountant class]
                      dispatcher:self.accountantDispatcher];
}

- (void)hireEmployeesWithClass:(Class)class dispatcher:(TYVDispatcher *)dispatcher {
    NSUInteger randomWashersCount = arc4random_uniform(kTYVMaxEmployeeCount);
    NSLog(@"Accoutantscount = %lu", (unsigned long)randomWashersCount);
    for (NSUInteger index = 0; index < randomWashersCount; index++) {
        TYVEmployee *employee = [class object];
        employee.experience = index;
        [employee addObserver:self];
        [dispatcher addHandler:employee];
    }
}

- (void)giveWorkToWasher:(TYVWasher *)washer {

}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVWasher *)washer {
    
}

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    if ([employee isMemberOfClass:[TYVWasher class]]) {
        [self.accountantDispatcher addProcessingObject:employee];
    } else if ([employee isMemberOfClass:[TYVAccountant class]]) {
        [self.director performWorkWithObject:employee];
    }
}

@end
