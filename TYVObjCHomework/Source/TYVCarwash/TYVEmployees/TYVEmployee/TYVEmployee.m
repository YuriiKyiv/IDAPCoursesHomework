//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

#import "NSDecimalNumber+TYVNSDecimalNumberExtensions.h"

@interface TYVEmployee ()
@property (nonatomic, retain)    NSString           *duty;
@property (nonatomic, retain)    NSDecimalNumber    *salary;
@property (nonatomic, assign)    NSUInteger         experience;

@end

@implementation TYVEmployee

@dynamic money;

@synthesize privateMoney = _privateMoney;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.privateMoney = nil;
    self.duty = nil;
    self.salary = nil;
    
    [super dealloc];
}

- (instancetype)initWithDuty:(NSString *)duty salary:(NSDecimalNumber *)salary {
    self = [super init];
    if (self) {
        self.duty = duty;
        self.salary = salary;
        self.privateMoney = [NSDecimalNumber number:@"0"];
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)money {
    return [[self.privateMoney copy] autorelease];
}


#pragma mark -
#pragma mark Public Methods

- (void)work {
    
}

#pragma mark -
#pragma mark TYVMoneyTransfer Methods

- (void)takeMoney:(NSDecimalNumber *)money fromMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
        self.privateMoney = [self.privateMoney decimalNumberByAdding:money];
        aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberBySubtracting:money];
}


- (void)giveMoney:(NSDecimalNumber *)money toMoneykeeper:(id<TYVMoneyTransfer>)aMoneykeeper {
    self.privateMoney = [self.privateMoney decimalNumberBySubtracting:money];
    aMoneykeeper.privateMoney = [aMoneykeeper.privateMoney decimalNumberByAdding:money];
}

@end
