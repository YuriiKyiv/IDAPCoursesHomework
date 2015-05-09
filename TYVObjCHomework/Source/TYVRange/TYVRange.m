//
//  TYVRange.m
//  IDAPCoursesHomework
//
//  Created by YURII on 04.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRange.h"

@interface TYVRange ()
@property (nonatomic, assign) NSUInteger  origin;
@property (nonatomic, assign) NSUInteger  end;
@property (nonatomic, assign) NSUInteger  length;

@end

@implementation TYVRange

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    return [self initWithOrigin:0 length:0];
}

- (instancetype)initWithOrigin:(NSUInteger)origin length:(NSUInteger)length {
    self = [super init];
    if (self) {
        self.origin = origin;
        self.length = length;
        self.end = origin + length;
    }
    
    return self;
}

- (instancetype)initWithOrigin:(NSUInteger)origin end:(NSUInteger)end {
    return [self initWithOrigin:origin length:(end - origin)];
}

#pragma mark -
#pragma mark Public Methods

+ (TYVRange *)rangeWithOrigin:(NSUInteger)origin length:(NSUInteger)length {
    return [[[TYVRange alloc] initWithOrigin:origin length:length] autorelease];
}

+ (TYVRange *)rangeWithOrigin:(NSUInteger)origin end:(NSUInteger)end {
    return [[[TYVRange alloc] initWithOrigin:origin end:end] autorelease];
}

@end
