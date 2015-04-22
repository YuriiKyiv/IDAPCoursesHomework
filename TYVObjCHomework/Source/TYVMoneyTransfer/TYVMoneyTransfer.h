//
//  TYVMoneyTransfer.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TYVMoneyTransfer <NSObject>
@property (nonatomic, retain)    NSDecimalNumber    *privateMoney;

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper;

@optional
- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper;

@end
