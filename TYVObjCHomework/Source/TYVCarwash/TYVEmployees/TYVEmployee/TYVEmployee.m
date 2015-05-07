//
//  TYVEmployee.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVEmployee ()
@property (nonatomic, copy)     NSString                *duty;
@property (nonatomic, retain)   NSDecimalNumber         *salary;

@end

@implementation TYVEmployee

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.duty = nil;
    self.salary = nil;
    self.delegate = nil;
    self.delegatingObject = nil;
    
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

#pragma mark -
#pragma mark Accessors

- (void)setDelegatingObject:(id)object {
    if (_delegatingObject != object) {
        _delegatingObject.delegate = nil;
        
        [_delegatingObject release];
        _delegatingObject = [object retain];
        
        _delegatingObject.delegate = self;
    }
}

-(void)setFree:(BOOL)free {
    _free = free;
    if (free && [self.delegate respondsToSelector:@selector(employeeIsFree:)]) {
        [self.delegate employeeIsFree:self];
    }
}

#pragma mark -
#pragma mark TYVEmployeeDelegate

- (void)employee:(TYVEmployee *)employee didPerfomWorkWithObject:(id)object {
    [self perfomWorkWithObject:employee];
}

#pragma mark -
#pragma mark Comparison

- (NSUInteger)hash {
    return [self.duty hash] ^ [self.salary hash] ^ self.experience;
}

- (BOOL)isEqual:(id)object {
    return ([object isMemberOfClass:[self class]]
            && [self isEqualToObject:object]);
}

- (BOOL)isEqualToObject:(TYVEmployee *)object {
    return (self == object || ([self.duty isEqual:object.duty]
            && [self.salary isEqual:object.salary]
            && self.experience == object.experience));
}

#pragma mark -
#pragma mark Public Methods

- (void)perfomWorkWithObject:(TYVMoneyKeeper *)anObject {
    self.free = NO;
    [self takeMoney:anObject.money fromMoneykeeper:anObject];
}

@end
