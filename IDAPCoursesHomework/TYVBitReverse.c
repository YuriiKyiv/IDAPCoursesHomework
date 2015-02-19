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

void TYVBitReverse(char number, bool reverse){
    TYVEndian endian = TYVGetByteOrder();
    reverse ?
        TYVValueBitOutput(&number, sizeof(number), endian++):
        TYVValueBitOutput(&number, sizeof(number), endian);
}