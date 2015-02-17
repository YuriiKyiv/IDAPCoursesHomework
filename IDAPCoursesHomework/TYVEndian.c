//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"
#include "stdbool.h"

enum endian {litleEndian = 1, bigEndian = 0};

bool TYVByteOrder() {
    int a = 1;
    char *c = (char *)&a;
    
    return 1 == *c ? litleEndian  : bigEndian;
}
