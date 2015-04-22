//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"
#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCar ()

@end

@implementation TYVCar

@synthesize money = _money;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.money = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self initWithMoney:0 isClear:false];
    }
    return self;
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money isClear:(BOOL)isClear {
    self = [super init];
    if (self) {
        self.money = [[money copy] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

#pragma mark -
#pragma mark TYVMoneyTransfer Methods

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
    self.money = [self.money decimalNumberByAdding:money];
    aMoneykeeper.money = [aMoneykeeper.money decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
    self.money = [self.money decimalNumberBySubtracting:money];
    aMoneykeeper.money = [aMoneykeeper.money decimalNumberByAdding:money];
}


@end
