//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVEngine.h"

static
const uint8_t TYVDoorMaxCount = 20;

@interface TYVCar : NSObject {
    @private
    BOOL doors[TYVDoorMaxCount];
}

@property (nonatomic, retain) TYVEngine* engine;

- (void)openDoorAtIndex:(uint8) doorIndex;

- (void)closeDoorAtIndex:(uint8) doorIndex;

- (BOOL)isOpenedDoorAtIndex: (uint8) doorIndex;


@end
