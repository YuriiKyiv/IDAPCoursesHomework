//
//  TYVSelectorWrapper.m
//  IDAPCoursesHomework
//
//  Created by YURII on 13.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVSelectorWrapper.h"

@interface TYVSelectorWrapper ()
@property (nonatomic, copy) NSString *selector;

@end

@implementation TYVSelectorWrapper

+ (instancetype)selectorWrapperWithselector:(SEL)selector {
    return [[[TYVSelectorWrapper alloc] initWithSelector:selector] autorelease];
}

#pragma mark -
#pragma Initiliazetion and Deallocation

- (void)dealloc {
    self.selector = nil;
    
    [super dealloc];
}

- (instancetype)initWithSelector:(SEL)selector {
    self = [super init];
    if (self) {
        self.selector = NSStringFromSelector(selector);
    }
    return self;
}

@end
