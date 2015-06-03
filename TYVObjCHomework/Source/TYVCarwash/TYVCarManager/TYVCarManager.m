//
//  TYVCarManager.m
//  IDAPCoursesHomework
//
//  Created by YURII on 21.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCarManager.h"
#import "TYVCarwashEnterprise.h"
#import "TYVCar.h"
#import "TYVWasher.h"

#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCarManager ()
@property (nonatomic, retain)   TYVCarwashEnterprise    *enterprise;
@property (nonatomic, retain)   TYVWasher               *washer;

- (void)work;

- (void)workWithWasher;

@end

@implementation TYVCarManager

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.enterprise = nil;
    self.washer = nil;
    
    [super dealloc];
}

- (instancetype)initWithEnterprise:(TYVCarwashEnterprise *)enterprise carCapacity:(NSUInteger)carCapacity
                              delay:(uint)delay
{
    self = [super init];
    if (self) {
        self.enterprise = enterprise;
        self.carCapacity = carCapacity;
        self.delay = delay;
    }
    
    return self;
}

- (instancetype)initWithWasher:(TYVWasher *)washer carCapacity:(NSUInteger)carCapacity
                         delay:(uint)delay
{
    self = [self initWithEnterprise:nil carCapacity:carCapacity delay:delay];
    if (self) {
        self.washer = washer;
    }
    
    return self;
}

-(instancetype)init {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

#pragma mark -
#pragma mark Public Methods

- (void)start {
    while (!self.isCancel) {
        [self performSelectorInBackground:@selector(work) withObject:nil];
        sleep(self.delay);
    }
    
}

- (void)startWithWasher {
    while (!self.isCancel) {
    [self performSelectorInBackground:@selector(workWithWasher) withObject:nil];
        sleep(self.delay);
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)work {
    TYVCarwashEnterprise *enterprise = self.enterprise;
    for (int i = 0; i < self.carCapacity; i++) {
        [enterprise washCar:[TYVCar object]];
    }
}

- (void)workWithWasher {
    TYVWasher *washer = self.washer;
    for (int i = 0; i < self.carCapacity; i++) {
        [washer performWorkWithObject:[TYVCar object]];
    }
}

@end
