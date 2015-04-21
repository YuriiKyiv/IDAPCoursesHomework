//
//  TYVRoom.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVRoom.h"

@interface TYVRoom ()
@property (nonatomic, retain)  NSMutableArray   *mutableHumansArray;
@property (nonatomic, assign)  NSUInteger       humanCount;

@end

@implementation TYVRoom

@dynamic full;
@dynamic humans;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableHumansArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithHumanCount:0];
}

- (instancetype)initWithHumanCount:(NSUInteger)count {
    self = [super init];
    if (self) {
        self.humanCount = count;
        self.mutableHumansArray = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isFull {
    return [self.mutableHumansArray count] >= self.humanCount;
}

- (NSArray *)humans {
    return [[self.mutableHumansArray copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addHuman:(TYVEmployee *)aHuman {
    if (!self.isFull) {
        [self.mutableHumansArray addObject:(id)aHuman];
    }
}

- (void)removeHuman:(TYVEmployee *)aHuman {
    [self.mutableHumansArray removeObject:(id)aHuman];
}

@end
