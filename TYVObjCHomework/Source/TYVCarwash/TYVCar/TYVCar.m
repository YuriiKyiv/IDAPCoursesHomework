//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"
#import "NSObject+TYVNSObjectExtensions.h"

@interface TYVCar ()
@property (nonatomic, retain)   NSDecimalNumber   *money;

@end

@implementation TYVCar

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.money = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self initWithMoney:0 isClear:false];
    }
    return self;
}

- (instancetype)initWithMoney:(NSDecimalNumber *)money isClear:(BOOL)isClear {
    self = [super init];
    if (self) {
        self.money = [[money copy] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)giveMoney:(NSDecimalNumber *)money {
    self.money = [self.money decimalNumberBySubtracting:money];
}


@end
