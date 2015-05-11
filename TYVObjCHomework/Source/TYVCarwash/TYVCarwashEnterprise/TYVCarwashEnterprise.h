//
//  TYVCarwashEnterprise.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TYVWasher.h"

@interface TYVCarwashEnterprise : NSObject <TYVEmployeeObserver>

- (void)hireStaff;

- (void)prepareBuildings;

- (void)work;

@end
