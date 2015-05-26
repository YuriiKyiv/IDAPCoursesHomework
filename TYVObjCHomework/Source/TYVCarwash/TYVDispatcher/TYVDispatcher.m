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

#import "TYVEmployeeObserverProtocol.h"

@interface TYVDispatcher ()
@property (nonatomic, retain) TYVQueue          *proccesingObjectsQueue;
@property (nonatomic, retain) TYVEmployeesPool  *handlersSet;

@end

@implementation TYVDispatcher

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.proccesingObjectsQueue = nil;
    self.handlersSet = nil;
    
    [super dealloc];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.proccesingObjectsQueue = [TYVQueue queue];
        self.handlersSet = [TYVEmployeesPool pool];
    }
    
    return self;
}

#pragma mark -
#pragma Public Methods

- (void)addProccesingObject:(id)object {
    
}

- (void)removeProccesingObject:(id)object {
    
}

- (void)addHandler:(id<TYVEmployeeObserverProtocol>)handler {
    
}

- (void)removeHandler:(id<TYVEmployeeObserverProtocol>)handler {
    
}

@end
