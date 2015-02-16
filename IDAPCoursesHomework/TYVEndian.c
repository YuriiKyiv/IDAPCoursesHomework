//
//  TYVEndian.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVEndian.h"
#include "stdbool.h"

bool TYVByteOrder() {
    int a = 1;
    char *c = (char *)&a;
    if (1 == *c) {
        return 1;
    }
    
    else {
        return 0;
    }
}
