//
//  TYVEmployeeObserverProtocol.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVEmployee;

@protocol TYVEmployeeObserverProtocol <NSObject>

@optional
- (void)employeeDidBecomeFree:(TYVEmployee *)employee;

- (void)employeeDidBecomeBusy:(TYVEmployee *)employee;

- (void)employeeDidPerformWork:(TYVEmployee *)employee;

@end
