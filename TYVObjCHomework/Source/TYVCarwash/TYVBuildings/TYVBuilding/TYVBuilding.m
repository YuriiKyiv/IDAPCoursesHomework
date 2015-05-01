//
//  TYVBuilding.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVBuilding.h"
#import "TYVRoom.h"

@interface TYVBuilding ()
@property (nonatomic, copy)   NSMutableSet *mutableRoomsSet;

@end

@implementation TYVBuilding

@dynamic rooms;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableRoomsSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableRoomsSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)rooms {
    return [[self.mutableRoomsSet copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addRoom:(TYVRoom *)aRoom {
    [self.mutableRoomsSet addObject:aRoom];
}

- (void)removeRoom:(TYVRoom *)aRoom {
    [self.mutableRoomsSet removeObject:aRoom];
}

@end
