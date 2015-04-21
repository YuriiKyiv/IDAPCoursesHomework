//
//  TYVCarwashRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashRoom.h"

@interface TYVCarwashRoom ()
@property (nonatomic, retain)  NSMutableArray   *mutableCarsArray;
@property (nonatomic, assign)  NSUInteger       carCount;

@end

@implementation TYVCarwashRoom

@dynamic fullForCar;
@dynamic fullForHuman;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableCarsArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithHumanCount:0 carCount:0];
}

- (instancetype)initWithHumanCount:(NSUInteger)humanCount carCount:(NSUInteger)carCount {
    self = [super initWithHumanCount:humanCount];
    if (self) {
        self.carCount = carCount;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFullForCar {
    return [self.cars count] >= self.carCount;
}

- (BOOL)isFullForHuman {
    return [self.humans count] >= self.humanCount;
}

- (BOOL)isFull {
    return self.isFullForHuman && self.isFullForCar;
}

- (NSArray *)cars {
    return [[self.mutableCarsArray copy] autorelease];
}


#pragma mark -
#pragma mark Public Methods

- (void)addCar:(TYVCar *)aCar {
    if (!self.isFullForCar) {
        [self.mutableCarsArray addObject:aCar];
    }
}

- (void)removeCar:(TYVCar *)aCar {
    [self.mutableCarsArray  removeObject:aCar];
}

@end
