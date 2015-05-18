//
//  _TYVObserverableState.h
//  IDAPCoursesHomework
//
//  Created by Yurii Trokhymchuk on 5/12/15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVObservableObject.h"

typedef NS_ENUM(NSUInteger, TYVObservationType) {
    TYVProtocolObservation,
    TYVHandlerObservation
};

@interface _TYVObserverableState : NSObject
@property (nonatomic, readonly) id                  observer;
@property (nonatomic, readonly) TYVObservableObject *observableObject;
@property (nonatomic, readonly) TYVObservationType  observationType;
@property (nonatomic, readonly) NSMapTable          *handlers;

- (instancetype)initWithObserver:(id)obsrver;

- (void)setHandler:(TYVStateChangeHandler)handler forState:(NSUInteger)state;
- (void)removeHendlerForState:(NSUInteger)state;
- (TYVStateChangeHandler)handlerForState:(NSUInteger)state;
- (BOOL)containsHandlerForState:(NSUInteger)state;

- (void)notifyWithState:(NSUInteger)state;
- (void)notifyWithState:(NSUInteger)state withObject:(id)object;

@end
