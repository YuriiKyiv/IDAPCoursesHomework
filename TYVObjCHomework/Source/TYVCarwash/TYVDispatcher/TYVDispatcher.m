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
@property (nonatomic, retain) TYVQueue          *processingObjectsQueue;
@property (nonatomic, retain) TYVEmployeesPool  *handlersPool;

- (void)removeConnections;

@end

@implementation TYVDispatcher

@dynamic handlersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeConnections];
    
    self.processingObjectsQueue = nil;
    self.handlersPool = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.processingObjectsQueue = [TYVQueue queue];
        self.handlersPool = [TYVEmployeesPool pool];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)handlersSet {
    return [self.handlersPool employeesSet];
}

#pragma mark -
#pragma Public Methods

- (void)addProcessingObject:(id)object {
    [self.processingObjectsQueue enqueueObject:object];
    [self giveWorkForHandler:[self.handlersPool freeEmployee]];
}

- (void)addHandler:(TYVEmployee *)handler {
#warning synchronized?
    @synchronized (handler) {
        [self.handlersPool addEmployee:handler];
        [handler addObserver:self];
    }
    
    [self giveWorkForHandler:handler];
}

- (void)removeHandler:(TYVEmployee *)handler {
    @synchronized (handler) {
        if (TYVEmployeeDidBecomeFree == handler.state) {
            [handler removeObserver:self];
            [self.handlersPool removeEmployee:handler];
        }
    }
}

- (void)giveWorkForHandler:(TYVEmployee *)handler {
    @synchronized (handler) {
        if (TYVEmployeeDidBecomeFree == handler.state) {
            [handler performWorkWithObject:[self.processingObjectsQueue dequeueObject]];
        }
    }
}

#pragma mark -
#pragma Private Methods

- (void)removeConnections {
    NSSet *handlersSet = self.handlersSet;
    for (TYVEmployee *handler in handlersSet) {
        [handler removeObserver:self];
    }
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidBecomeFree:(TYVEmployee *)employee {
    [self giveWorkForHandler:employee];
}

@end
