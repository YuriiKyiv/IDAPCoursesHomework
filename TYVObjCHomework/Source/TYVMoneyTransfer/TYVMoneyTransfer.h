//
//  TYVMoneyTransfer.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TYVMoneyTransfer <NSObject>
- (void)takeMoney:(NSDecimalNumber *)money From:(id)aMoneykeeper;

@optional
- (void)giveMoney:(NSDecimalNumber *)money To:(id)aMoneykeeper;

@end
