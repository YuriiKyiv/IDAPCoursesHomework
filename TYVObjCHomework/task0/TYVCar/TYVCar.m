//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"

@implementation TYVCar

- (void)openDoorAtIndex:(uint8) doorIndex {
    if (doorIndex < TYVDoorMaxCount) {
        doors[doorIndex] = true;
    }
}

- (void)closeDoorAtIndex:(uint8) doorIndex {
    if (doorIndex < TYVDoorMaxCount) {
        doors[doorIndex] = false;
    }
}

- (BOOL)isOpenedDoorAtIndex: (uint8) doorIndex {
    if (doorIndex < TYVDoorMaxCount) {
        return doors[doorIndex];
    }
    
    return false;
}

@end
