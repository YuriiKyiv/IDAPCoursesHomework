//
//  NSSet+TYVExtentions.m
//  IDAPCoursesHomework
//
//  Created by YURII on 10.06.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "NSSet+TYVExtentions.h"

@implementation NSSet (TYVExtentions)

#pragma mark -
#pragma mark Public Methods

- (id)findObjectWithBlock:(TYVFindObjectBlock)block {
    @synchronized(self) {
        __block id object = nil;
        [self enumerateObjectsUsingBlock:^(id obj, BOOL *stop) {
            object = obj;
            if (block(object)) {
                *stop = YES;
            } else {
                object = nil;
            }
        }];
        
        return object;
    }
}

- (NSSet *)findObjectsWithBlock:(TYVFindObjectBlock)block {
    @synchronized (self) {
        NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary *bindings) {
            return block(evaluatedObject);
        }];
        
        return [self filteredSetUsingPredicate:predicate];
    }
}

@end
