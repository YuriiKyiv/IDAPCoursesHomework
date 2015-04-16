//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVCar : NSObject
@property (nonatomic, readonly, getter=isClear)     BOOL        clear;
@property (nonatomic, readonly)                     NSDecimal   money;

- (instancetype)initWithMoney:(NSDecimal)money isClear:(BOOL)isClear;

@end
