//
//  TYVFemaleBeing.m
//  IDAPCoursesHomework
//
//  Created by YURII on 13.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVFemaleBeing.h"

@implementation TYVFemaleBeing

#pragma mark -
#pragma mark Public Methods

- (TYVBeing *)giveBirth {
    NSLog(@"giveBirth");
    
    return [[self class] object];
}

- (void)performGenderSpecificOperation {
    [self giveBirth];
}

@end
