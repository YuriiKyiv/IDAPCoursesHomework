//
//  TYVAccountant.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@class TYVWasher;
@class TYVAccountant;

@protocol TYVAccountantDelegate <NSObject>

- (void)accountant:(TYVAccountant *)accountant
      didTakeMoney:(NSDecimalNumber *)money
   fromMoneyKeeper:(TYVMoneyKeeper *)moneykeeper;

- (void)accountant:(TYVAccountant *)accountant didCountMoney:(NSDecimalNumber *)money;

@end

@interface TYVAccountant : TYVEmployee
@property (nonatomic, readonly)    NSDecimalNumber    *capital;

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money
                     capital:(NSDecimalNumber *)capital;

@end
