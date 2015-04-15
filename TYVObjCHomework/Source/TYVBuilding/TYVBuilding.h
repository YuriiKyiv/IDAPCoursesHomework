//
//  TYVBuilding.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVRoom.h"

@interface TYVBuilding : NSObject
@property (nonatomic, copy, readonly)   NSArray *rooms;

- (void)addRoom:(TYVRoom *)aRoom;

- (void)removeRoom:(TYVRoom *)aRoom;

@end
