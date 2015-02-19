//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"

TYVEndian TYVGetByteOrder() {
    int a = 1;
    char *c = (char *)&a;
    return 1 == *c ? TYVLitleEndian : TYVBigEndian;
}
