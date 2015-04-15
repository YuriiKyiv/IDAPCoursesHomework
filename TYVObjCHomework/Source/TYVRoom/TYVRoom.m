//
//  TYVRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRoom.h"

@interface TYVRoom ()
@property   (nonatomic, copy, readwrite)    NSMutableArray  *mutableHumansArray;

@property   (nonatomic, assign, readwrite)  uint8_t         maxHumanCount;

@end

@implementation TYVRoom
@dynamic full;
@dynamic humans;

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithMaxHumanCount:(uint8_t)count {
    self = [super init];
    if (self) {
        self.maxHumanCount = count;
    }
    
    return self;
}

- (void)dealloc
{
    self.mutableHumansArray = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFull {
    return [[self mutableHumansArray] count] >= self.maxHumanCount;
}

- (NSArray *)getHumans {
    return [[[self mutableHumansArray] copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addHuman:(TYVHuman *)aHuman {
    if (!self.isFull) {
        [[self mutableHumansArray] addObject:aHuman];
    }
}

- (void)removeHuman:(TYVHuman *)aHuman {
    [[self mutableHumansArray] removeObject:aHuman];
}

@end
