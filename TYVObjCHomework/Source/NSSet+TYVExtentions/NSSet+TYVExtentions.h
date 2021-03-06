//
//  NSSet+TYVExtentions.h
//  IDAPCoursesHomework
//
//  Created by YURII on 10.06.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef BOOL(^TYVFindObjectBlock)(id);

@interface NSSet (TYVExtentions)

- (id)objectWithBlock:(TYVFindObjectBlock)block;

- (NSSet *)objectsWithBlock:(TYVFindObjectBlock)block;

@end
