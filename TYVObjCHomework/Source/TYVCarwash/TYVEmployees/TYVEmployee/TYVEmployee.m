//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()
@property (nonatomic, retain)    NSString           *duty;
@property (nonatomic, retain)    NSDecimalNumber    *salary;
@property (nonatomic, assign)    NSUInteger         experience;

@end

@implementation TYVEmployee

@dynamic money;
@dynamic free;

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
        self.privateMoney = [NSDecimalNumber zero];
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSDecimalNumber *)money {
    return [[self.privateMoney copy] autorelease];
}

- (BOOL)isFree {
    return true;
}


#pragma mark -
#pragma mark Public Methods

- (void)work {
    
}

@end
