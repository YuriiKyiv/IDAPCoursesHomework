//
//  TYVCarwashBuilding.m
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarwashBuilding.h"

@interface TYVCarwashBuilding ()
@property (nonatomic, retain)    NSMutableArray    *mutableCarwashrooms;

@end

@implementation TYVCarwashBuilding

@dynamic carwashrooms;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableCarwashrooms = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableCarwashrooms = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)carwashrooms {
    return [[self.mutableCarwashrooms copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addCarwashRoom:(TYVCarwashRoom *)aCarwashRoom {
    [self.mutableCarwashrooms addObject:aCarwashRoom];
}

- (void)removeCarwashRoom:(TYVCarwashRoom *)aCarwashRoom {
    [self.mutableCarwashrooms removeObject:aCarwashRoom];
}

@end
