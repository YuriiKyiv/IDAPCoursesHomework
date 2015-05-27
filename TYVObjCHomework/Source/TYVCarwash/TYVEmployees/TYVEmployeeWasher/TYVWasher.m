//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVWasher.h"
#import "TYVCar.h"
#import "TYVSelector.h"

@interface TYVWasher ()

- (void)washCar:(TYVCar *)car;

@end

@implementation TYVWasher

@dynamic price;

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)price {
    return [NSDecimalNumber number:@"1000"];
}

#pragma mark -
#pragma mark Public Methods

- (void)proccesWithObject:(id<TYVMoneyTransferProtocol> )object {
    [self takeMoney:self.price fromObject:object];
    [self washCar:object];
}

- (void)finalizeProccesingWithObjectOnMainThread:(TYVCar *)object {
    
}

#pragma mark -
#pragma mark Private Methods

- (void)washCar:(TYVCar *)car {
    usleep(arc4random_uniform(1000 * 10));
    car.clean = YES;
    NSLog(@"Clean a car");
}

@end
