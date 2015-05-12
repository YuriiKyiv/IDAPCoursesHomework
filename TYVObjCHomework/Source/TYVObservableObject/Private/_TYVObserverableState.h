//
//  _TYVObserverableState.h
//  IDAPCoursesHomework
//
//  Created by Yurii Trokhymchuk on 5/12/15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TYVObservationType) {
    TYVProtocolObservation,
    TYVHandlerObservation
};

@interface _TYVObserverableState : NSObject
@property (nonatomic, readonly) id                  observer;
@property (nonatomic, readonly) TYVObservationType  observationType;
@property (nonatomic, readonly) NSMapTable          *handlers;

@end
