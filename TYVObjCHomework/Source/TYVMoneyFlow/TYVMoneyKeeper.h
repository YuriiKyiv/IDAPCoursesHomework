//
//  TYVMoneyKeeper.h
//  IDAPCoursesHomework
//
//  Created by YURII on 23.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyTransferProtocol.h"

@interface TYVMoneyKeeper : NSObject <TYVMoneyTransferProtocol>

- (instancetype)initWithMoney:(NSDecimalNumber *)money;

@end
