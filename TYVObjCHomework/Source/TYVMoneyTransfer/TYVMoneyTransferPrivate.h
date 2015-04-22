//
//  TYVMoneyTransferPrivate.h
//  IDAPCoursesHomework
//
//  Created by YURII on 22.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TYVMoneyTransferPrivate <NSObject>
@property (nonatomic, retain)    NSDecimalNumber    *money;

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper;

@optional
- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper;
@end
