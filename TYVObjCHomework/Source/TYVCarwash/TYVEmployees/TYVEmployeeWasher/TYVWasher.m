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

- (void)washCar:(TYVCar *)aCar;

@end

@implementation TYVWasher

@dynamic price;

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)price {
    return [NSDecimalNumber number:@"100"];
}

#pragma mark -
#pragma mark Public Methods

- (void)perfomWorkWithObject:(TYVCar *)aCar {
    [self takeMoney:aCar.money fromMoneykeeper:aCar];
    [self washCar:aCar];
}

#pragma mark -
#pragma mark Private Methods

- (void)washCar:(TYVCar *)aCar {
    self.free = NO;
    aCar.isClear = YES;
    self.free = YES;
}

@end
