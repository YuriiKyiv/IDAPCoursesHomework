//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVWasher.h"
#import "TYVCar.h"

@implementation TYVWasher

@dynamic price;

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)price {
    return [NSDecimalNumber number:@"100"];
}


#pragma mark -
#pragma mark Public Methods

- (void)washCar:(TYVCar *)aCar {
    self.free = NO;
    aCar.isClear = YES;
    self.free = YES;
}

@end
