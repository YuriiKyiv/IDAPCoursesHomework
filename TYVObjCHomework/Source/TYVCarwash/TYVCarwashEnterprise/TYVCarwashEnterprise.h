//
//  TYVCarwashEnterprise.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVCarwashBuilding;
@class TYVBuilding;
@class TYVEmployeesPool;

@interface TYVCarwashEnterprise : NSObject
//@property (nonatomic, readonly)    NSArray             *Buildings;
//@property (nonatomic, readonly)    TYVEmployeesPool    *employees;

- (void)hireStaff;

- (void)prepareBuildings;

- (void)work;

@end
