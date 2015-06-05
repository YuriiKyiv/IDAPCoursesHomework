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
@property (nonatomic, retain)   NSTimer                 *timer;

- (void)work;

@end

@implementation TYVCarManager

@dynamic running;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    if ([self.timer isValid]) {
        [self.timer invalidate];
    }
    
    self.timer = nil;
    self.enterprise = nil;
    
    [super dealloc];
}

- (instancetype)initWithEnterprise:(TYVCarwashEnterprise *)enterprise
                       carCapacity:(NSUInteger)carCapacity
                              delay:(NSTimeInterval)delay
{
    self = [super init];
    if (self) {
        self.enterprise = enterprise;
        self.carCapacity = carCapacity;
        self.delay = delay;
        
        self.timer = [NSTimer scheduledTimerWithTimeInterval:delay
                                                      target:self
                                                    selector:@selector(work)
                                                    userInfo:nil
                                                     repeats:YES];
    }
    
    return self;
}

- (instancetype)init {
    [self doesNotRecognizeSelector:_cmd];
    [self release];
    
    return nil;
}

#pragma mark -
#pragma mark Accessors

- (BOOL)isRunning {
    return [self.timer isValid];
}

#pragma mark -
#pragma mark Public Methods

- (void)start {
    [self.timer fire];
}

- (void)stop {
    [self.timer invalidate];
}

#pragma mark -
#pragma mark Private Methods

- (void)work {
    [self performSelectorInBackground:@selector(workInBackground) withObject:nil];
}

- (void)workInBackground {
    TYVCarwashEnterprise *enterprise = self.enterprise;
    for (int i = 0; i < self.carCapacity; i++) {
        [enterprise washCar:[TYVCar object]];
    }
}

@end
