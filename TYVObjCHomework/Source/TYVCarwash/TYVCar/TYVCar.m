//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"
#import "NSObject+TYVNSObjectExtensions.h"

@implementation TYVCar

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.privateMoney = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self initWithMoney:[NSDecimalNumber zero]];
    }
    return self;
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money {
    self = [super init];
    if (self) {
        self.privateMoney = money;
    }
    
    return self;
}

@end
