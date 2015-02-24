//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"

TYVEndian TYVGetByteOrder() {
    unsigned int a = 1;
    return (1 == *(char *)&a) ? TYVLitleEndian : TYVBigEndian;
}

TYVEndian TYVGetReverseEndian(TYVEndian endian){
    return !endian;
}
