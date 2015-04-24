//
//  TYVEmployeeAccountant.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAccountant.h"

@interface TYVAccountant ()
@property (nonatomic, retain)   NSDecimalNumber    *capital;

@end

@implementation TYVAccountant

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.capital = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super initWithDuty:@"Count"
                        salary:[NSDecimalNumber number:@"100"]
                         money:[NSDecimalNumber number:@"100"]];
    if (self) {
        self.capital = [NSDecimalNumber number:@"0"];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)count {
    self.free = NO;
    self.capital = [self.capital decimalNumberByAdding:self.money];
    self.free = YES;
}

@end
