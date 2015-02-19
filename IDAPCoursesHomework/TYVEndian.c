//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"

TYVEndian TYVByteOrder() {
    int a = 1;
    char *c = (char *)&a;
    TYVEndian endian = TYVlitleEndian;
    return 1 == *c ? endian : endian;
}
