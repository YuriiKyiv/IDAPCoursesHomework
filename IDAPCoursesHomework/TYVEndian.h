//
//  TYVEndian.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVEndian__
#define __IDAPCoursesHomework__TYVEndian__

#include <stdio.h>

enum TYVEndian {TYVBigEndian, TYVLitleEndian};
typedef enum TYVEndian TYVEndian;

extern
TYVEndian TYVGetByteOrder();

extern
TYVEndian TYVEndianGetReverse(TYVEndian endian);

#endif /* defined(__IDAPCoursesHomework__TYVEndian__) */
