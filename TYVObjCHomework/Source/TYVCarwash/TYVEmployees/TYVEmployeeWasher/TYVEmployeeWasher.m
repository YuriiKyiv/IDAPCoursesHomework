//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeeWasher.h"

@interface TYVEmployeeWasher ()
@property (nonatomic, readonly)    NSString    *price;

@end

@implementation TYVEmployeeWasher

@dynamic price;


#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.car = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (NSString *)price {
    return @"100";
}

#pragma mark -
#pragma mark Public Methods

- (void)wash {
    self.car.isClear = true;
}

- (void)takeMoney {
    [self.car giveMoney:[NSDecimalNumber decimalNumberWithString:self.price]];
    self.car = nil;
}

- (void)giveMoneyToAccountant:(TYVEmployeeAccountant *)accountant {
    [[accountant retain] autorelease];
    
}

@end
