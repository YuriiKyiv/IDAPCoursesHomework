//
//  TYVWasher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@class TYVCar;
@class TYVWasher;
@class TYVMoneyKeeper;

@protocol TYVWasherDelegate <NSObject>

- (void)washer:(TYVWasher *)washer didWashCar:(TYVCar *)car;

- (void)washer:(TYVWasher *)washer didTakeMoney:(NSDecimalNumber *)money FromMoneyKeeper:(TYVMoneyKeeper *)moneykeeper;

@optional
- (void)washer:(TYVWasher *)washer didPerfomWorkWithObject:(TYVCar *)car;

@end

@interface TYVWasher : TYVEmployee
@property (nonatomic, readonly)     NSDecimalNumber    *price;

@end
