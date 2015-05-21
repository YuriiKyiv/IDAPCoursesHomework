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

#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCarManager ()
@property (nonatomic, retain)   TYVCarwashEnterprise    *enterprise;
@property (atomic, assign, getter=isCancel)      BOOL    cancel;

- (void)work;

@end

@implementation TYVCarManager

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.enterprise = nil;
    
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

#pragma mark -
#pragma mark Private Methods

- (void)work {
    TYVCarwashEnterprise *enterprise = self.enterprise;
    for (int i = 0; i < self.carCapacity; i++) {
        [enterprise addCar:[TYVCar object]];
    }
}

@end
