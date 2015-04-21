//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyTransfer.h"

@interface TYVEmployee : NSObject <TYVMoneyTransfer>
@property (nonatomic, readonly)    NSString     *duty;

@property (nonatomic, readonly)    float        salary;
@property (nonatomic, readonly)    NSUInteger   experience;

- (void)work;

@end
