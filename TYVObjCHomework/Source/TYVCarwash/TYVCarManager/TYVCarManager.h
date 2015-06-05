//
//  TYVCarManager.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVCarwashEnterprise;
@class TYVWasher;

@interface TYVCarManager : NSObject
@property (atomic, assign)  NSUInteger      carCapacity;
@property (atomic, assign)  NSTimeInterval  delay;

@property (atomic, assign, getter=isRunning) BOOL   running;

- (instancetype)initWithEnterprise:(TYVCarwashEnterprise *)enterprise
                       carCapacity:(NSUInteger)carCapacity
                             delay:(NSTimeInterval)delay;

- (void)start;

@end
