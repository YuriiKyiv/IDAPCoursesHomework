//
//  TYVCarwashRoom.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRoom.h"
#import "TYVCar.h"

@interface TYVCarwashRoom : TYVRoom
@property (nonatomic, readonly)                           NSArray  *cars;
@property (nonatomic, readonly)                           uint8_t  carCount;
@property (nonatomic, readonly, getter=isFullForHuman)    BOOL     fullForHuman;
@property (nonatomic, readonly, getter=isFullForCar)      BOOL     fullForCar;

- (instancetype)initWithHumanCount:(uint8_t)humanCount carCount:(uint8_t)carCount;

- (void)addCar:(TYVCar *)aCar;

- (void)removeCar:(TYVCar *)aCar;

@end
