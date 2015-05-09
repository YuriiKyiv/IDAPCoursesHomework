//
//  TYVRange.h
//  IDAPCoursesHomework
//
//  Created by YURII on 04.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVRange : NSObject
@property (nonatomic, readonly) NSUInteger  origin;
@property (nonatomic, readonly) NSUInteger  end;
@property (nonatomic, readonly) NSUInteger  length;

+ (instancetype)rangeWithOrigin:(NSUInteger)origin length:(NSUInteger)length;
+ (instancetype)rangeWithOrigin:(NSUInteger)origin end:(NSUInteger)end;

- (instancetype)initWithOrigin:(NSUInteger)origin length:(NSUInteger)length;
- (instancetype)initWithOrigin:(NSUInteger)origin end:(NSUInteger)end;

@end
