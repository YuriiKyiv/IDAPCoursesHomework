//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVWasher.h"
#import "TYVCar.h"

@interface TYVWasher ()
@property (nonatomic, assign, getter=isFree)    BOOL    free;

@end

@implementation TYVWasher

@synthesize free;
@dynamic price;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.car = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)price {
    return [NSDecimalNumber number:@"100"];
}


#pragma mark -
#pragma mark Public Methods

- (void)wash {
    self.free = NO;
    self.car.isClear = true;
    self.free = YES;
}

@end
