//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"
#include "stdbool.h"

enum TYVEndian {litleEndian = 1, bigEndian = 0};
typedef enum TYVEndian TYVEndian;

TYVEndian TYVByteOrder() {
    int a = 1;
    char *c = (char *)&a;
    
    return 1 == *c ? litleEndian : bigEndian;
}
