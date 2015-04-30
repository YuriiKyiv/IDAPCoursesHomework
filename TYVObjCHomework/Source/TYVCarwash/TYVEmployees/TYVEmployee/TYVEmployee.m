//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()
@property (nonatomic, retain)   NSString           *duty;
@property (nonatomic, retain)   NSDecimalNumber    *salary;
@property (nonatomic, assign)   NSUInteger         experience;

@end

@implementation TYVEmployee

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    
    [super dealloc];
}

- (instancetype)init
{
    return [self initWithDuty:@""
                       salary:[NSDecimalNumber zero]
                        money:[NSDecimalNumber zero]];
}

- (instancetype)initWithDuty:(NSString *)duty
                      salary:(NSDecimalNumber *)salary
                       money:(NSDecimalNumber *)money
{
    self = [super initWithMoney:money];
    if (self) {
        self.duty = duty;
        self.salary = salary;
        self.free = YES;
    }
    
    return self;
}

@end