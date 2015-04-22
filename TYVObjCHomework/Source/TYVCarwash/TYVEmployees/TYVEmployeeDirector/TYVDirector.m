//
//  TYVEmployeeDirector.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVDirector.h"

@interface TYVDirector ()
@property (nonatomic, retain)    NSDecimalNumber    *capital;

@end

@implementation TYVDirector

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.capital = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.capital = [NSDecimalNumber zero];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)profit {
    self.capital = [self.capital decimalNumberByAdding:self.privateMoney];
}

@end
