//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyTransfer.h"

@interface TYVCar : NSObject <TYVMoneyTransfer>
@property (nonatomic, assign)      BOOL               isClear;

- (instancetype)initWithMoney:(NSDecimalNumber *)money isClear:(BOOL)isClear;

@end
