//
//  TYVMoneyFlow.m
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVMoneyKeeper.h"

@interface TYVMoneyKeeper ()
@property (nonatomic, retain)   NSDecimalNumber    *privateMoney;

@end

@implementation TYVMoneyKeeper

@dynamic money;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.privateMoney = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithMoney:[NSDecimalNumber zero]];
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money {
    self = [super init];
    if (self) {
        self.privateMoney = money;
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)money {
    return self.privateMoney;
}

#pragma mark -
#pragma mark Public Methods

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(TYVMoneyKeeper *)aMoneykeeper {
    self.privateMoney = [self.privateMoney decimalNumberByAdding:money];
    aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(TYVMoneyKeeper *)aMoneykeeper {
    self.privateMoney = [self.privateMoney decimalNumberBySubtracting:money];
    aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberByAdding:money];
}

@end
