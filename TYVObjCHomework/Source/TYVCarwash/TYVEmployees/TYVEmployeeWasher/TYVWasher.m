//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVWasher.h"
#import "TYVCar.h"
#import "TYVSelectorWrapper.h"

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
    return [NSDecimalNumber number:@"1000"];
}

#pragma mark -
#pragma mark Public Methods

- (void)workWithObject:(id<TYVMoneyTransfer>)car {
    @autoreleasepool {
            self.state = TYVEmployeeDidBecomeBusy;
            NSLog(@"Washer starts to workwith experience %lu and money %@", (unsigned long)self.experience, self.money);
            [self takeMoney:self.price fromObject:car];
            [self washCar:car];
            self.state = TYVEmployeeDidPerfomWorkWithObject;
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)washCar:(TYVCar *)aCar {
    usleep(arc4random_uniform(1000));
    aCar.clean = YES;
    NSLog(@"Washer has cleaned a car with experience %lu and money %@", (unsigned long)self.experience, self.money);
}

@end
