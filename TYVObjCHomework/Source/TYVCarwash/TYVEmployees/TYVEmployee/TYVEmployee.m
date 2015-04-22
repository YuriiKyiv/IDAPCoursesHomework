//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()

@end

@implementation TYVEmployee

@synthesize money = _money;

#pragma mark -
#pragma mark Initializations and Deallocations


#pragma mark -
#pragma mark Public Methods

- (void)work {
    
}

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
