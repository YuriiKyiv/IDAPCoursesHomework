//
//  TYVSelector.h
//  IDAPCoursesHomework
//
//  Created by YURII on 13.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVSelector : NSObject
@property (nonatomic, readonly) SEL selector;

+ (instancetype)selectorWithSelector:(SEL)selector;

- (instancetype)initWithSelector:(SEL)selector;

@end
