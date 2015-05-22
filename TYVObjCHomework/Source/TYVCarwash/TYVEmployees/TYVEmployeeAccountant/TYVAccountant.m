//
//  TYVEmployeeAccountant.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAccountant.h"
#import "TYVWasher.h"
#import "TYVSelector.h"

@interface TYVAccountant ()
@property (nonatomic, retain)   NSDecimalNumber    *capital;

- (void)count;

@end

@implementation TYVAccountant

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.capital = nil;
    
    [super dealloc];
}

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money
                     capital:(NSDecimalNumber *)capital
{
    self = [super initWithDuty:duty
                        salary:salary
                         money:money];
    if (self) {
        self.capital = capital;
    }
    
    return self;
}

- (instancetype)init
{
    return [self initWithDuty:@""
                       salary:[NSDecimalNumber zero]
                        money:[NSDecimalNumber zero]
                      capital:[NSDecimalNumber zero]];
}

#pragma mark -
#pragma mark Public Methods

- (void)proccesWithObject:(TYVWasher *)washer {
    [self takeMoney:washer.money fromObject:washer];
    [self count];
}

#pragma mark -
#pragma mark Private Methods

- (void)count {
    usleep(arc4random_uniform(1000));
    self.capital = [self.capital decimalNumberByAdding:[NSDecimalNumber decimalNumberWithString:@"1000"]];
    NSLog(@"Account capital is %@", self.capital);
}

@end;
