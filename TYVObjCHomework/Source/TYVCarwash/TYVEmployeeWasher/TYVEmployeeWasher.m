//
//  TYVEmployeeWasher.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeeWasher.h"

@implementation TYVEmployeeWasher

- (void)wash {
    self.car.isClear = true;
}

- (void)takeMoney {
    [self.car takeMoney:[NSDecimalNumber decimalNumberWithString:@"100"]];
}

- (void)giveMoneyToAccountant:(TYVEmployeeAccountant *)accountant {
    
}

@end
