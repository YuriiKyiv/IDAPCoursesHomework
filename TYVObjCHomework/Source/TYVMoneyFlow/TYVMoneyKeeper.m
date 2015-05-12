//
//  TYVMoneyFlow.m
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVMoneyKeeper.h"

@interface TYVMoneyKeeper ()
@property (nonatomic, retain)   NSDecimalNumber    *money;

@end

@implementation TYVMoneyKeeper

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.money = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithMoney:[NSDecimalNumber zero]];
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money {
    self = [super init];
    if (self) {
        self.money = money;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(TYVMoneyKeeper *)moneykeeper {
    self.money = [self.money decimalNumberByAdding:money];
    moneykeeper.money = [moneykeeper.money decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(TYVMoneyKeeper *)moneykeeper {
    self.money = [self.money decimalNumberBySubtracting:money];
    moneykeeper.money = [moneykeeper.money decimalNumberByAdding:money];
}

@end
