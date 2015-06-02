//
//  TYVMoneyTransferProtocol.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVEmployee;

@protocol TYVMoneyTransferProtocol <NSObject>

@property (atomic, retain)   NSDecimalNumber *money;

- (void)takeMoney:(NSDecimalNumber *)money fromObject:(id<TYVMoneyTransferProtocol>)object;
- (void)giveMoney:(NSDecimalNumber *)money toObject:(id<TYVMoneyTransferProtocol>)object;

- (void)takeMoney:(NSDecimalNumber *)money;
- (void)giveMoney:(NSDecimalNumber *)money;

@end
