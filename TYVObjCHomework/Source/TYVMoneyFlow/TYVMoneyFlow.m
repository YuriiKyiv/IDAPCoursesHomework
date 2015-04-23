//
//  TYVMoneyFlow.m
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVMoneyFlow.h"

@implementation TYVMoneyFlow

@synthesize privateMoney = _privateMoney;

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
