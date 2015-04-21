//
//  TYVEmployeeAccountant.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployeeAccountant.h"

@interface TYVEmployeeAccountant ()
@property (nonatomic, retain)   NSDecimalNumber    *money;

@end

@implementation TYVEmployeeAccountant

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.money = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.money = self.money = [NSDecimalNumber decimalNumberWithString:@"0"];
    }
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)count {
    
}

- (void)giveMoneyToDirector:(TYVEmployeeDirector *)aDirector {
    [[aDirector retain] autorelease];
    [aDirector takeMoney:[[self.money copy] autorelease]];
    self.money = [NSDecimalNumber decimalNumberWithString:@"0"];
}

- (void)takeMoney:(NSDecimalNumber *)money {
    [self.money decimalNumberByAdding:money];
}

@end
