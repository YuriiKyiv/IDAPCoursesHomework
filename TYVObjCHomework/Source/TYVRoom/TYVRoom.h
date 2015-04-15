//
//  TYVRoom.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVHuman.h"

@interface TYVRoom : NSObject
@property   (nonatomic, copy, readonly)             NSArray  *humans;

@property   (nonatomic, readonly, getter=isFull)    BOOL     full;
@property   (nonatomic, readonly)                   uint8_t  maxHumanCount;

- (instancetype)initWithMaxHumanCount:(uint8_t)count;

- (void)addHuman:(TYVHuman *)aHuman;

- (void)removeHuman:(TYVHuman *)aHuman;

@end
