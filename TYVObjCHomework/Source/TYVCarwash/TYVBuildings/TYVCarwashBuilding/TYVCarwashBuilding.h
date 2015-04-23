//
//  TYVCarwashBuilding.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVBuilding.h"

@class TYVCarwashRoom;

@interface TYVCarwashBuilding : TYVBuilding
@property (nonatomic, readonly)    NSArray    *carwashrooms;

- (void)addCarwashRoom:(TYVCarwashRoom *)aCarwashRoom;

- (void)removeCarwashRoom:(TYVCarwashRoom *)aCarwashRoom;

@end
