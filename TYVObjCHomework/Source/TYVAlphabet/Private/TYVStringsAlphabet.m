//
//  TYVStringsAlphabet.m
//  IDAPCoursesHomework
//
//  Created by YURII on 09.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVStringsAlphabet.h"

@interface TYVStringsAlphabet ()
@property (nonatomic, retain)   NSArray *strings;

@end

@implementation TYVStringsAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.strings = nil;
    
    [super dealloc];
}

- (instancetype)initWithStrings:(NSArray *)strings {
    self = [super init];
    if (self) {
        self.strings = strings;
    }
    
    return self;
}

@end
