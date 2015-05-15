//
//  TYVMoneyFlow.m
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVMoneyKeeper.h"

@implementation TYVMoneyKeeper
@synthesize money = _money;

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

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object {
    self.money = [self.money decimalNumberByAdding:money];
    object.money = [object.money decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object {
    self.money = [self.money decimalNumberBySubtracting:money];
    object.money = [object.money decimalNumberByAdding:money];
}

@end
