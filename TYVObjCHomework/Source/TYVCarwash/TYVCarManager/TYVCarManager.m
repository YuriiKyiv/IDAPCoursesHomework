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

- (void)addCarInEnterprise;

@end

@implementation TYVCarManager

@dynamic running;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
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

- (void)setTimer:(NSTimer *)timer {
    if (timer != _timer) {
        if ([_timer isValid]) {
            [_timer invalidate];
        }
        
        [_timer release];
        _timer = timer;
        if (timer) {
            [timer retain];
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)start {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:self.delay
                                                  target:self
                                                selector:@selector(work)
                                                userInfo:nil
                                                 repeats:YES];
    [self.timer fire];
}

- (void)stop {
    [self.timer invalidate];
}

#pragma mark -
#pragma mark Private Methods

- (void)work {
//    [self performSelectorInBackground:@selector(addCarInEnterprise) withObject:nil];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [self addCarInEnterprise];
    });
}

- (void)addCarInEnterprise {
    TYVCarwashEnterprise *enterprise = self.enterprise;
    for (int i = 0; i < self.carCapacity; i++) {
        [enterprise washCar:[TYVCar object]];
    }
}

@end
