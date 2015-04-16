//
//  TYVCarwashRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashRoom.h"

@interface TYVCarwashRoom ()
@property (nonatomic, retain)  NSMutableArray  *mutableCarsArray;
@property (nonatomic, assign)  uint8_t         carCount;

@end

@implementation TYVCarwashRoom

@dynamic humanCount;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {

    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithHumanCount:0 carCount:0];
}

- (instancetype)initWithHumanCount:(uint8_t)humanCount carCount:(uint8_t)carCount {
    self = [super initWithHumanCount:humanCount];
    if (self) {
        self.carCount = carCount;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFull {
    return ([[self humans] count] >= self.humanCount) || ([[self mutableCarsArray] count] >= self.carCount);
}

- (NSArray *)getCars {
    return [[[self mutableCarsArray] copy] autorelease];
}


#pragma mark -
#pragma mark Public Methods

- (void)addCar:(TYVCar *)aCar {
    [self.mutableCarsArray addObject:aCar];
}

- (void)removeCar:(TYVCar *)aCar {
    [self.mutableCarsArray  removeObject:aCar];
}

@end
