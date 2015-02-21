//
//  TYVBitReverse.c
//  IDAPCoursesHomework
//
//  Created by YURII on 19.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVBitReverse.h"
#include "stdbool.h"
#include "TYVValueBitOutput.h"

void TYVByteReverse(void *number, size_t size, bool reverse){
    TYVEndian endian = TYVGetByteOrder();
    reverse ?
        TYVValueBitOutput(number, size, TYVGetReverseEndian(endian)):
        TYVValueBitOutput(number, size, endian);
}