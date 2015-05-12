//
//  TYVObservableObject.m
//  IDAPCoursesHomework
//
//  Created by YURII on 11.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVObservableObject.h"

typedef void(^TYVNotificationHandler)(id observer);

@interface TYVObservableObject ()

@property (nonatomic, retain) NSHashTable   *observersHashTable;

- (void)notifyWithSelector:(SEL)selector;
- (void)notifyWithSelector:(SEL)selector withObject:(id)object;
- (void)notifyWithSelector:(SEL)selector notificationHandler:(TYVNotificationHandler)handler;

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

- (void)setState:(NSUInteger)state withObject:(id)object {
    
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

- (void)addObserver:(id)observer withHendler:(TYVStateChangeHandler)handler {
    
}
- (void)removeObserver:(id)observer withHendler:(TYVStateChangeHandler)handler {
    
}

#pragma mark -
#pragma mark Private Methods

- (void)notifyWithSelector:(SEL)selector {
    [self notifyWithSelector:selector notificationHandler:^(id observer) {
        [observer performSelector:selector withObject:self];
    }];
}

- (void)notifyWithSelector:(SEL)selector withObject:(id)object {
    [self notifyWithSelector:selector notificationHandler:^(id observer) {
        [observer performSelector:selector withObject:self withObject:object];
    }];
}

- (void)notifyWithSelector:(SEL)selector notificationHandler:(TYVNotificationHandler)handler {
    if (!handler) {
        return;
    }
    
    NSHashTable *observers = self.observersHashTable;
    for (id observer in observers) {
        if ([observer respondsToSelector:selector]) {
            handler(observer);
        }
    }
}

@end
