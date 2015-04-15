//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVCar : NSObject
@property (nonatomic, assign, readonly, getter=isClear)     BOOL        clear;
@property (nonatomic, assign, readonly)                     uint8_t     money;

@end
