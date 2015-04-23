//
//  TYVEmployeeAccountant.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAccountant.h"

@interface TYVAccountant ()
@property (nonatomic, retain)                   NSDecimalNumber    *capital;
@property (nonatomic, assign, getter=isFree)    BOOL               free;

@end

@implementation TYVAccountant

@synthesize free;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.capital = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.capital = [NSDecimalNumber number:@"0"];
    }
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)count {
    self.free = NO;
    self.capital = [self.capital decimalNumberByAdding:self.privateMoney];
    self.free = YES;
}

@end
