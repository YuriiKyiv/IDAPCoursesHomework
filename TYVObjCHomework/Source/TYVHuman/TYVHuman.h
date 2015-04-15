//
//  TYVHuman.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYVHuman : NSObject
@property (nonatomic, copy, readonly)   NSString    *duty;

@property (nonatomic, assign, readonly) float       salary;
@property (nonatomic, assign, readonly) uint8_t     experience;

@end
