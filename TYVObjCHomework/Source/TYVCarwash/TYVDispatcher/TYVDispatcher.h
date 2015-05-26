//
//  TYVDispatcher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 26.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVQueue;
@protocol TYVEmployeeObserverProtocol;

@interface TYVDispatcher : NSObject
@property (nonatomic, readonly) TYVQueue    *proccesingObjectsQueue;
@property (nonatomic, readonly) NSSet       *handlersSet;

- (void)addProccesingObject:(id)object;
- (void)removeProccesingObject:(id)object;

- (void)addHandler:(id<TYVEmployeeObserverProtocol>)handler;
- (void)removeHandler:(id<TYVEmployeeObserverProtocol>)handler;

@end
