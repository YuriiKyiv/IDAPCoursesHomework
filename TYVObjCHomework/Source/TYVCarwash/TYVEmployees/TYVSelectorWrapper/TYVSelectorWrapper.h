//
//  TYVSelectorWrapper.h
//  IDAPCoursesHomework
//
//  Created by YURII on 13.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVSelectorWrapper : NSObject
@property (nonatomic, readonly) NSString *selector;

+ (instancetype)selectorWrapperWithselector:(SEL)selector;

- (instancetype)initWithSelector:(SEL)selector;

@end
