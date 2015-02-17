//
//  TYVValueBitOutput.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVValueBitOutput__
#define __IDAPCoursesHomework__TYVValueBitOutput__

#include <stdio.h>
#include "stdbool.h"

enum TYVendian {litleEndian = 1, bigEndian = 0};

extern
void TYVValueBitOutput(void *valueRef, size_t size, bool endian);

#endif /* defined(__IDAPCoursesHomework__TYVValueBitOutput__) */
