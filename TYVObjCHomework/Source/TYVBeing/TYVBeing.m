//
//  TYVBeing.m
//  IDAPCoursesHomework
//
//  Created by YURII on 10.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVBeing.h"

@interface TYVBeing ()

@property (nonatomic, copy)   NSString    *name;
@property (nonatomic, copy)   NSArray     *chidren;

@property (nonatomic, assign) TYVGender   gender;
@property (nonatomic, assign) uint8_t     weight;
@property (nonatomic, assign) uint8_t     age;

- (void)sayMessage:(NSString *)aMessage;

@end

@implementation TYVBeing

#pragma mark -
#pragma mark Public Methods

- (void)fight {
    [self sayMessage:@"fight"];
}

- (TYVBeing *)giveBirth {
    return [[[TYVBeing alloc] init] autorelease];
}

- (void)addChild:(TYVBeing *)aChild {
    [self sayMessage:@"add"];
}

- (void)removeChild:(TYVBeing *)aChild {
    [self sayMessage:@"remove"];
}

- (void)sayHi {
    [self sayMessage:@"Hi"];
}

#pragma mark -
#pragma mark Private Methods

- (void)sayMessage:(NSString *)aMessage {
    NSLog(@"%@", aMessage);
}

@end
