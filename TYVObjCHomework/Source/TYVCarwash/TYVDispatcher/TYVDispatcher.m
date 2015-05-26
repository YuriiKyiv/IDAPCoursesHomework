//
//  TYVDispatcher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 26.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVDispatcher.h"
#import "TYVQueue.h"
#import "TYVEmployeesPool.h"
#import "TYVWasher.h"

@interface TYVDispatcher ()
@property (nonatomic, retain) TYVQueue          *proccesingObjectsQueue;
@property (nonatomic, retain) TYVEmployeesPool  *handlersPool;

@end

@implementation TYVDispatcher

@dynamic handlersSet;
@dynamic proccesingObjects;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.proccesingObjectsQueue = nil;
    self.handlersPool = nil;
    
    [super dealloc];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.proccesingObjectsQueue = [TYVQueue queue];
        self.handlersPool = [TYVEmployeesPool pool];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)handlersSet {
    return self.handlersPool.employeesSet;
}

- (TYVQueue *)proccesingObjects {
    return [[self.proccesingObjectsQueue copy] autorelease];
}

#pragma mark -
#pragma Public Methods

- (void)addProccesingObject:(id)object {
    TYVWasher *washer = [self.handlersPool freeEmployeeWithClass:[TYVWasher class]];
    if (washer) {
        [washer performWorkWithObject:object];
    } else {
        [self.proccesingObjectsQueue enqueueObject:object];
    }
}


- (void)addHandler:(TYVEmployee *)handler {
    [self.handlersPool addEmployee:handler];
    [handler addObserver:self];
    
    if (TYVEmployeeDidBecomeFree == handler.state) {
        [handler performWorkWithObject:[self.proccesingObjectsQueue dequeueObject]];
    }
}

- (void)removeHandler:(id<TYVEmployeeObserverProtocol>)handler {
    
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    [employee performWorkWithObject:[self.proccesingObjectsQueue dequeueObject]];
}

@end
