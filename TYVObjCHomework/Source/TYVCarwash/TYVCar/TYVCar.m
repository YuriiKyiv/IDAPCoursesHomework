//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"
#import "NSObject+TYVNSObjectExtensions.h"

@implementation TYVCar

@synthesize privateMoney = _privateMoney;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.privateMoney = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self initWithMoney:[NSDecimalNumber zero]];
    }
    return self;
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money {
    self = [super init];
    if (self) {
        self.privateMoney = money;
    }
    
    return self;
}

#pragma mark -
#pragma mark TYVMoneyTransfer Methods

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
    self.privateMoney = [self.privateMoney decimalNumberByAdding:money];
    aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
    self.privateMoney = [self.privateMoney decimalNumberBySubtracting:money];
    aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberByAdding:money];
}


@end
