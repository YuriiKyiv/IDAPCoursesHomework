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
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)price {
    return [NSDecimalNumber number:@"100"];
}

#pragma mark -
#pragma mark Public Methods

- (void)perfomWorkWithObject:(TYVCar *)aCar {
    self.free = NO;
    [self takeMoney:self.price fromMoneykeeper:aCar];
    [self washCar:aCar];
    [self notifyWithSelector:[self selectorForState:TYVEmployeeDidPerfomWorkWithObject]];
}

#pragma mark -
#pragma mark Private Methods

- (void)washCar:(TYVCar *)aCar {
    aCar.clean = YES;
    NSLog(@"Washer has cleaned a car");
}

@end
