//
//  TYVEmployeeAccountant.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAccountant.h"

@interface TYVAccountant ()
@property (nonatomic, retain)   NSDecimalNumber    *capital;

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

- (void)count {
    self.free = NO;
    self.capital = [self.capital decimalNumberByAdding:self.money];
    self.free = YES;
}

@end
