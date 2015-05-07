//
//  TYVWasher.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVEmployee.h"

@interface TYVWasher : TYVEmployee
@property (nonatomic, readonly) NSDecimalNumber         *price;

@property (nonatomic, assign)   id<TYVEmployeeDelegate> delegateOfState;

@end
