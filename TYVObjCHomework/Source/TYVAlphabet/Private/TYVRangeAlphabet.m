//
//  TYVRangeAlphabet.m
//  IDAPCoursesHomework
//
//  Created by YURII on 09.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRangeAlphabet.h"
#import "TYVRange.h"

@interface TYVRangeAlphabet ()
@property (nonatomic, retain)   TYVRange    *range;

@end

@implementation TYVRangeAlphabet

#pragma mark - 
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(TYVRange *)range {
    self = [super init];
    if (self) {
        self.range = range;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (NSUInteger)count {
    return  self.range.length;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    TYVRange *range = self.range;
    
    NSAssert(index < range.length, NSRangeException);
    
    return [NSString stringWithFormat:@"%c", (unichar)(range.end)];
}

@end
