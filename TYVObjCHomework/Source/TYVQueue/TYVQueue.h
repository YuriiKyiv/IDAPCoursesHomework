//
//  TYVQueue.h
//  IDAPCoursesHomework
//
//  Created by YURII on 06.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVQueue : NSObject
@property (nonatomic, readonly, getter=isEmpty) BOOL    empty;

+ (instancetype)queue;

- (void)enqueueObject:(id)object;

- (id)dequeueObject;

- (BOOL)containsObject:(id)object;

@end
