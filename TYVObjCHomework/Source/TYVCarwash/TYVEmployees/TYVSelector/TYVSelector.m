//
//  TYVSelector.m
//  IDAPCoursesHomework
//
//  Created by YURII on 13.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVSelector.h"

@interface TYVSelector ()
@property (nonatomic, assign) SEL selector;

@end

@implementation TYVSelector

+ (instancetype)selectorWithSelector:(SEL)selector {
    return [[[TYVSelector alloc] initWithSelector:selector] autorelease];
}

#pragma mark -
#pragma Initiliazetion and Deallocation

- (instancetype)initWithSelector:(SEL)selector {
    self = [super init];
    if (self) {
        self.selector = selector;
    }
    
    return self;
}

@end
