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

@end

@implementation TYVDispatcher

@dynamic handlersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
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
    [self performSelectorInBackground:@selector(perfomProcess) withObject:nil];
}

- (void)perfomProcess{
    @synchronized (self) {
        TYVEmployee  *handler = [self.handlersPool freeEmployee];
        if (handler) {
            [handler performWorkWithObject:[self.processingObjectsQueue dequeueObject]];
        }
    }
}

- (void)addHandler:(TYVEmployee *)handler {
    @synchronized (self) {
        [self.handlersPool addEmployee:handler];
        [handler addObserver:self];
        TYVQueue *queue = self.processingObjectsQueue;
        if (TYVEmployeeDidBecomeFree == handler.state && !queue.isEmpty) {
            [handler performWorkWithObject:[queue dequeueObject]];
        }
    }
}

- (void)removeHandler:(id<TYVEmployeeObserverProtocol>)handler {
    
}

- (void)giveWorkForHandler:(id)handler {
    if (TYVEmployeeDidBecomeFree == handler) {
        [handler performWorkWithObject:[self.processingObjectsQueue dequeueObject]];
    }
}

#pragma mark -
#pragma mark TYVEmployeeObserver

- (void)employeeDidPerformWork:(TYVEmployee *)employee {
    [self performSelectorInBackground:@selector(giveWorkForHandler:) withObject:employee];
}

@end
