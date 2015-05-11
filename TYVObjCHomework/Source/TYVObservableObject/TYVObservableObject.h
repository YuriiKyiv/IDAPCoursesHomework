//
//  TYVObservableObject.h
//  IDAPCoursesHomework
//
//  Created by YURII on 11.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVObservableObject : NSObject

@property (nonatomic, readonly) NSSet   *observersSet;

- (void)addObserver:(id)observer;

- (void)removeObserver:(id)observer;

- (BOOL)containsObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

@end
