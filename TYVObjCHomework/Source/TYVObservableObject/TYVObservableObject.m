//
//  TYVObservableObject.m
//  IDAPCoursesHomework
//
//  Created by YURII on 11.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVObservableObject.h"

@interface TYVObservableObject ()

@property (nonatomic, retain) NSHashTable   *observersHashTable;

@end

@implementation TYVObservableObject

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.observersHashTable = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.observersHashTable = [NSHashTable weakObjectsHashTable];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observersSet {
    return self.observersHashTable.setRepresentation;
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    [self.observersHashTable addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.observersHashTable removeObject:observer];
}

- (BOOL)containsObserver:(id)observer {
    return [self.observersHashTable containsObject:observer];
    
}

- (SEL)selectorForState:(NSUInteger)state {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

#pragma mark -
#pragma mark Private Methods

- (void)notifyWithSelector:(SEL)selector {
    NSHashTable *observers = self.observersHashTable;
    for (id observer in observers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:self];
        }
    }
}

@end
