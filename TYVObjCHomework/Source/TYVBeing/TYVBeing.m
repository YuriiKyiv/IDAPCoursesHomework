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
#pragma mark Initializations and Deallocations

- (instancetype) initWithName:(NSString *)name age:(uint8_t)age {
    self = [super init];
    if (self) {
        self.name = name;
        self.age = age;
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    self.mutableChildrenArray = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)children {
    return [[[self mutableChildrenArray] copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

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

- (void)performGenderSpecificOperation {
    
}

#pragma mark -
#pragma mark Private Methods

- (void)sayMessage:(NSString *)aMessage {
    NSLog(@"%@", aMessage);
}

@end
