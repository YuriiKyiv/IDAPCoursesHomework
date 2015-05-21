//
//  TYVMoneyTransfer.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVEmployee;

@protocol TYVMoneyTransfer <NSObject>

@property (atomic, retain)   NSDecimalNumber *money;

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransfer>)object;
- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransfer>)object;

- (void)takeMoney:(NSDecimalNumber *)money;
- (void)giveMoney:(NSDecimalNumber *)money;

@end
