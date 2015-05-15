//
//  TYVMoneyKeeper.h
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyTransfer.h"

@interface TYVMoneyKeeper : NSObject <TYVMoneyTransfer>

- (instancetype)initWithMoney:(NSDecimalNumber *)money;

@end
