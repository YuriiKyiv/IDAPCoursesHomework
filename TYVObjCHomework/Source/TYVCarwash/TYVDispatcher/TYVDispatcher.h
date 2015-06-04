//
//  TYVDispatcher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 26.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TYVEmployeeObserverProtocol.h"

@class TYVQueue;
@class TYVEmployeesPool;
@class TYVEmployee;

@interface TYVDispatcher : NSObject <TYVEmployeeObserverProtocol>

- (void)addProcessingObject:(id)object;

- (void)addHandler:(TYVEmployee *)handler;
- (void)removeHandler:(TYVEmployee *)handler;

@end
