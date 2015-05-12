//
//  TYVObservableObject.h
//  IDAPCoursesHomework
//
//  Created by YURII on 11.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^TYVStateChangeHandler)(void);

@interface TYVObservableObject : NSObject
@property (nonatomic, readonly) NSSet       *observersSet;
@property (nonatomic, assign) NSUInteger    state;

- (void)setState:(NSUInteger)state withObject:(id)object;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (BOOL)containsObserver:(id)observer;

- (void)addObserver:(id)observer withHendler:(TYVStateChangeHandler)handler;

- (void)addObserver:(id)observer withHendler:(TYVStateChangeHandler)handler forState:(NSUInteger)state;
- (void)removeObserver:(id)observer forState:(NSUInteger)state;

- (SEL)selectorForState:(NSUInteger)state;

@end
