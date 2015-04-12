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

- (instancetype) initWithName:(NSString *)name age:(uint8_t)age {
    self = [super init];
    if (self) {
        [self name];
        [self age];
    }
    
    return self;
}

- (void) dealloc {
    [self setName:NULL];
    [self setChidren:NULL];
    
    [super dealloc];
}

- (void)fight {
    [self sayMessage:@"fight"];
}

- (TYVBeing *)giveBirth {
    return [[[TYVBeing alloc] init] autorelease];
}

- (void)addChild:(TYVBeing *)aChild {
    if (self == aChild) {
        return;
    }
    
    NSMutableArray *array = [[[NSMutableArray alloc] initWithArray:[self chidren]]autorelease];
    [array addObject:aChild];
    self.chidren = [[array copy] autorelease];
    [self sayMessage:@"add"];
}

- (void)removeChild:(TYVBeing *)aChild {
    NSMutableArray *array = [[[NSMutableArray alloc] initWithArray:[self chidren]]autorelease];
    [array removeObject:aChild];
    self.chidren = [[array copy] autorelease];
    [self sayMessage:@"remove"];
}

- (void)sayHi {
    [self sayMessage:@"Hi"];
    for (TYVBeing * child in [self chidren]) {
        [child sayHi];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)sayMessage:(NSString *)aMessage {
    NSLog(@"%@", aMessage);
}

@end
