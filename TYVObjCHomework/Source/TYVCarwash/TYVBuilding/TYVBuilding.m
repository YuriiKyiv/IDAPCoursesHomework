//
//  TYVBuilding.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVBuilding.h"

@interface TYVBuilding ()
@property (nonatomic, retain)   NSMutableArray *mutableRoomsArray;

@end

@implementation TYVBuilding
@dynamic rooms;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableRoomsArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableRoomsArray = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)getRooms {
    return [[[self mutableRoomsArray] copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addRoom:(TYVRoom *)aRoom {
    [[self mutableRoomsArray] addObject:aRoom];
}

- (void)removeRoom:(TYVRoom *)aRoom {
    [[self mutableRoomsArray] removeObject:aRoom];
}

@end
