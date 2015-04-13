//
//  TYVBeing.m
//  IDAPCoursesHomework
//
//  Created by YURII on 10.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVBeing.h"

@interface TYVBeing ()

@property (nonatomic, copy)   NSString          *name;
@property (nonatomic, copy)   NSMutableArray    *mutableChildrenArray;

@property (nonatomic, assign) TYVGender         gender;
@property (nonatomic, assign) uint8_t           weight;
@property (nonatomic, assign) uint8_t           age;

- (void)sayMessage:(NSString *)aMessage;

@end

@implementation TYVBeing

@dynamic children;

#pragma mark -
#pragma mark Public Methods

- (instancetype) initWithName:(NSString *)name age:(uint8_t)age gender:(TYVGender)gender {
    self = [super init];
    if (self) {
        [self setName:name];
        [self setAge:age];
        [self setGender:gender];
    }
    
    return self;
}

- (void) dealloc {
    [self setName:NULL];
    [self setMutableChildrenArray:NULL];
    
    [super dealloc];
}

- (NSArray *) children {
    return [[[self mutableChildrenArray] copy] autorelease];
}

- (void)fight {
    [self sayMessage:@"fight"];
}

- (TYVBeing *)giveBirth {
    [self sayMessage:@"giveBirth"];
    return [[[TYVBeing alloc] init] autorelease];
}

- (void)addChild:(TYVBeing *)aChild {
    [[self mutableChildrenArray] addObject:aChild];
    [self sayMessage:@"add"];
}

- (void)removeChild:(TYVBeing *)aChild {
    [[self mutableChildrenArray] removeObject:aChild];
    [self sayMessage:@"remove"];
}

- (void)sayHi {
    [self sayMessage:@"Hi"];
    for (TYVBeing * child in [self mutableChildrenArray]) {
        [child sayHi];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)sayMessage:(NSString *)aMessage {
    NSLog(@"%@", aMessage);
}

@end
