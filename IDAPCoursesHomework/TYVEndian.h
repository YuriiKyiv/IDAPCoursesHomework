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

enum TYVEndian {litleEndian = 1, bigEndian = 0};
typedef enum TYVEndian TYVEndian;

extern
TYVEndian TYVByteOrder();

#endif /* defined(__IDAPCoursesHomework__TYVEndian__) */
