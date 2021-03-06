//
//  TYVEmployeeDirector.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVDirector.h"
#import "TYVAccountant.h"

@interface TYVDirector ()
@property (atomic, retain)   NSDecimalNumber *capital;

- (void)profit;

@end

@implementation TYVDirector

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.capital = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.capital = [NSDecimalNumber zero];
    }
    
    return self;
}

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money
                     capital:(NSDecimalNumber *)capital
{
    self = [super initWithDuty:duty salary:salary money:money];
    if (self) {
        self.capital = capital;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)processWithObject:(TYVAccountant *)accountant {
    [self takeMoney:accountant.money fromObject:accountant];
    [self profit];
}

- (void)finalizeProcessWithObjectOnMainThread:(TYVAccountant *)object {
    [super finalizeProcessWithObjectOnMainThread:object];
    self.state = TYVEmployeeDidBecomeFree;
}

#pragma mark -
#pragma mark Private Methods

- (void)profit {
    usleep(arc4random_uniform(1000));
    NSDecimalNumber *capital = self.capital;
    capital = [capital decimalNumberByAdding:self.money];
    
    NSLog(@"Director capital is %@", self.money);
}

@end
