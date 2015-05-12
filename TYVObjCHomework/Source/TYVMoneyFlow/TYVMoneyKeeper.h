//
//  TYVMoneyKeeper.h
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVMoneyKeeper : NSObject

@property (nonatomic, readonly)   NSDecimalNumber    *money;

- (instancetype)initWithMoney:(NSDecimalNumber *)money;

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(TYVMoneyKeeper *)moneykeeper;

- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(TYVMoneyKeeper *)moneykeeper;

@end
