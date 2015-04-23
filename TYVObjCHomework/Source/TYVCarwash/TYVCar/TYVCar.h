//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyFlow.h"

@interface TYVCar : TYVMoneyFlow
@property (nonatomic, assign)   BOOL    isClear;

- (instancetype)initWithMoney:(NSDecimalNumber *)money;

@end
