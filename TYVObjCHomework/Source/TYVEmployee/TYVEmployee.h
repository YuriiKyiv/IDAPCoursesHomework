//
//  TYVEmployee.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum TYVEmployeeType {
    TYVEmployeeWasher,
    TYVEmployeeAccountant,
    TYVEmployeeDirector
} TYVEmployeeType;

@interface TYVEmployee : NSObject
@property (nonatomic, copy, readonly)   NSString        *duty;

@property (nonatomic, readonly)         TYVEmployeeType employeeType;
@property (nonatomic, readonly)         float           salary;
@property (nonatomic, readonly)         uint8_t         experience;

@end
