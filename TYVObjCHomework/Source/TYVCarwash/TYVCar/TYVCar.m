//
//  TYVCar.m
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVCar.h"

@interface TYVCar ()
@property (nonatomic, assign, getter=isClear)  BOOL        clear;
@property (nonatomic, assign)                                   NSDecimal   money;

@end

@implementation TYVCar

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithMoney:(NSDecimal)money isClear:(BOOL)isClear {
    self = [super init];
    if (self) {
        self.money = money;
        self.clear = isClear;
    }
    
    return self;
}

@end
