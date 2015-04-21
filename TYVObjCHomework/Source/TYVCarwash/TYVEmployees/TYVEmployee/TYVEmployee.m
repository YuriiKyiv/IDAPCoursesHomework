//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()
@property (nonatomic,  retain)   NSDecimalNumber    *money;

@end

@implementation TYVEmployee

#pragma mark -
#pragma mark Initializations and Deallocations


#pragma mark -
#pragma mark Public Methods

- (void)work {
    
}

- (void)takeMoney:(NSDecimalNumber *)money From:(TYVEmployee *)aMoneykeeper {
    self.money = [self.money decimalNumberByAdding:money];
    [aMoneykeeper.money decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money To:(TYVEmployee *)aMoneykeeper {
    self.money = [self.money decimalNumberBySubtracting:money];
    [aMoneykeeper.money decimalNumberByAdding:money];
}

@end
