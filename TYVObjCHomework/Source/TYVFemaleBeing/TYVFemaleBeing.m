//
//  TYVFemaleBeing.m
//  IDAPCoursesHomework
//
//  Created by YURII on 13.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVFemaleBeing.h"

@implementation TYVFemaleBeing

- (TYVBeing *)giveBirth {
    NSLog(@"giveBirth");
    return [[[TYVBeing alloc] init] autorelease];
}

- (void)performGenderSpecificOperation {
    [self giveBirth];
}

@end
