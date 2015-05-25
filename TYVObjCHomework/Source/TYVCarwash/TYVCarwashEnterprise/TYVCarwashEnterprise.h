//
//  TYVCarwashEnterprise.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TYVEmployeeObserverProtocol.h"

@class TYVCar;

@interface TYVCarwashEnterprise : NSObject <TYVEmployeeObserverProtocol>

- (void)hireStaff;

- (void)prepareBuildings;

- (void)prepareCars;

- (void)work;

- (void)addCar:(TYVCar *)car;

@end
