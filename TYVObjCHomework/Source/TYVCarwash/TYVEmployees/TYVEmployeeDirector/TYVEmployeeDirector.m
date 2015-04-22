//
//  TYVEmployeeDirector.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeeDirector.h"

@interface TYVEmployeeDirector ()

@end

@implementation TYVEmployeeDirector

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.money = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.money = [NSDecimalNumber decimalNumberWithString:@"0"];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)takeMoney:(NSDecimalNumber *)money {
    self.money = [self.money decimalNumberBySubtracting:money];
}

- (void)profit {
    NSLog(@"%@\n", self.money);
}

@end
