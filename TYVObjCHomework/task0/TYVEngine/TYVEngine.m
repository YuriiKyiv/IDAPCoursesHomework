//
//  TYVEngine.m
//  IDAPCoursesHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEngine.h"

@implementation TYVEngine

+ (instancetype)newEngineWithType:(TYVTypeOfEngine)engineType {
    id object = [[[self alloc] init] autorelease];
    [object setType:engineType];
    return object;
}

- (void)start {
    if (false == [self isWorking]) {
        [self setIsWorking:true];
    }
}

- (void)stop {
    [self setIsWorking:false];
}

@end
