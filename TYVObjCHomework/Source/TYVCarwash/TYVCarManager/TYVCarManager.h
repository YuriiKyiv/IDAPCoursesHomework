//
//  TYVCarManager.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVCarwashEnterprise;

@interface TYVCarManager : NSObject

@property (atomic, assign)  NSUInteger  carCapacity;
@property (atomic, assign)  uint  delay;

- (instancetype)initWithEnterprise:(TYVCarwashEnterprise *)enterprise carCapacity:(NSUInteger)carCapacity
                             delay:(uint)delay;

- (void)start;

@end
