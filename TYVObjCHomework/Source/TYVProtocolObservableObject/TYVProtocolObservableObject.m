//
//  TYVProtocolObservableObject.m
//  IDAPCoursesHomework
//
//  Created by Yurii Trokhymchuk on 5/14/15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVProtocolObservableObject.h"
#import "TYVSelector.h"

@interface TYVProtocolObservableObject ()
@property (nonatomic, retain) NSHashTable   *observersHashTable;

@end

@implementation TYVProtocolObservableObject

@synthesize state = _state;

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
    @synchronized(self) {
        return self.observersHashTable.setRepresentation;
    }
}

- (void)setState:(NSUInteger)state {
    @synchronized(self) {
        if (_state != state) {
            _state = state;
            BOOL isNoMainThread = ([NSThread isMainThread]) ? YES : NO;
            [self performSelectorOnMainThread:@selector(notify)
                                   withObject:nil
                                waitUntilDone:isNoMainThread];
        }
    }
}

- (NSUInteger)state {
    @synchronized (self) {
        return _state;
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    @synchronized(self) {
        [self.observersHashTable addObject:observer];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self) {
        [self.observersHashTable removeObject:observer];
    }
}

- (BOOL)containsObserver:(id)observer {
    @synchronized(self) {
        return [self.observersHashTable containsObject:observer];
    }
    
}

- (SEL)selectorForState:(NSUInteger)state {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (void)notifyWithSelector:(SEL)selector {
    @synchronized(self) {
        NSHashTable *observers = self.observersHashTable;
        for (id observer in observers) {
            if ([observer respondsToSelector:selector]) {
                [observer performSelector:selector withObject:self];
            }
        }
    }
}

- (void)notify {
    [self notifyWithSelector:[self selectorForState:self.state]];
}

@end
