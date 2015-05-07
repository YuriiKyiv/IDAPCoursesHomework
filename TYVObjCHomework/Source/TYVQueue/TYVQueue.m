//
//  TYVQueue.m
//  IDAPCoursesHomework
//
//  Created by YURII on 06.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVQueue.h"

@interface TYVQueue ()
@property (nonatomic, retain)   NSMutableArray  *queue;

@end

@implementation TYVQueue

@dynamic empty;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isEmpty {
    return ([self.queue count] == 0);
}

#pragma mark -
#pragma mark Public Methods

- (void)enqueueObject:(id)object {
    [self.queue addObject:object];
}

- (id)dequeueObject {
    NSMutableArray *array = self.queue;
    id result = array[0];
    [array removeObjectAtIndex:0];
    
    return result;
}

- (NSUInteger)count {
    return [self.queue count];
}

@end
