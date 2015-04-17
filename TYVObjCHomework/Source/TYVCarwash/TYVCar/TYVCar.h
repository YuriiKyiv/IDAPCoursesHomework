//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVCar : NSObject
@property (nonatomic, assign)      BOOL               isClear;
@property (nonatomic, readonly)    NSDecimalNumber    *money;

- (instancetype)initWithMoney:(NSDecimalNumber *)money isClear:(BOOL)isClear;

- (void)takeMoney:(NSDecimalNumber *)money;

@end
