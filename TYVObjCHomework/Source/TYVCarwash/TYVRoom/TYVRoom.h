//
//  TYVRoom.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVEmployee.h"

@interface TYVRoom : NSObject
@property (nonatomic, readonly)                   NSArray  *humans;

@property (nonatomic, readonly, getter=isFull)    BOOL     full;
@property (nonatomic, readonly)                   uint8_t  humanCount;

- (instancetype)initWithHumanCount:(uint8_t)count;

- (void)addHuman:(TYVEmployee *)aHuman;

- (void)removeHuman:(TYVEmployee *)aHuman;

@end
