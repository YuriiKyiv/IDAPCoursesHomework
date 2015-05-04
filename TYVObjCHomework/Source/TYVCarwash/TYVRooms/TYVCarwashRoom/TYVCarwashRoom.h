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
@property (nonatomic, readonly)                           NSSet         *cars;
@property (nonatomic, readonly)                           NSUInteger    carCapacity;
@property (nonatomic, readonly, getter=isFullForHuman)    BOOL          fullForHuman;
@property (nonatomic, readonly, getter=isFullForCar)      BOOL          fullForCar;

- (instancetype)initWithHumanCapacity:(NSUInteger)humanCapacity carCapacity:(NSUInteger)carCapacity;

- (void)addCar:(TYVCar *)aCar;

- (void)removeCar:(TYVCar *)aCar;

@end
