//
//  TYVCarwashRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashRoom.h"

@interface TYVCarwashRoom ()
@property (nonatomic, retain)  NSMutableSet   *mutableCarsSet;
@property (nonatomic, assign)  NSUInteger     carCount;

@end

@implementation TYVCarwashRoom

@dynamic fullForCar;
@dynamic fullForHuman;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableCarsSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithHumanCapacity:0 carCapacity:0];
}

- (instancetype)initWithHumanCapacity:(NSUInteger)humanCapacity carCapacity:(NSUInteger)carCapacity {
    self = [super initWithHumanCapacity:humanCapacity];
    if (self) {
        self.carCount = carCapacity;
        self.mutableCarsSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFullForCar {
    return [self.cars count] >= self.carCapacity;
}

- (BOOL)isFullForHuman {
    return [self.humans count] >= self.humanCapacity;
}

- (BOOL)isFull {
    return self.isFullForHuman && self.isFullForCar;
}

- (NSArray *)cars {
    return [[self.mutableCarsSet copy] autorelease];
}


#pragma mark -
#pragma mark Public Methods

- (void)addCar:(TYVCar *)aCar {
    if (!self.isFullForCar) {
        [self.mutableCarsSet addObject:aCar];
    }
}

- (void)removeCar:(TYVCar *)aCar {
    [self.mutableCarsSet  removeObject:aCar];
}

@end
