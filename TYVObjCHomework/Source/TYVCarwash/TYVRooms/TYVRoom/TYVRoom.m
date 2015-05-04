//
//  TYVRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRoom.h"

@interface TYVRoom ()
@property (nonatomic, retain)  NSMutableSet   *mutableHumansSet;
@property (nonatomic, assign)  NSUInteger     humanCapacity;

@end

@implementation TYVRoom

@dynamic full;
@dynamic humans;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableHumansSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithHumanCapacity:0];
}

- (instancetype)initWithHumanCapacity:(NSUInteger)capacity {
    self = [super init];
    if (self) {
        self.humanCapacity = capacity;
        self.mutableHumansSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFull {
    return [self.mutableHumansSet count] >= self.humanCapacity;
}

- (NSArray *)humans {
    return [[self.mutableHumansSet copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addHuman:(TYVEmployee *)aHuman {
    if (!self.isFull) {
        [self.mutableHumansSet addObject:(id)aHuman];
    }
}

- (void)removeHuman:(TYVEmployee *)aHuman {
    [self.mutableHumansSet removeObject:(id)aHuman];
}

@end
