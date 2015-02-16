//
//  TYVValueBitOutputTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutputTests.h"
#include "TYVValueBitOutput.h"

enum endian {litleEndian = 1, bigEndian = 0};

void TYVValueBitOutputTest(){
    char zero = '\0';
    char one = 1;
    char a = 'A';
    int value = 1000;
    TYVValueBitOutput(&zero, sizeof(zero), litleEndian);
    TYVValueBitOutput(&one, sizeof(one), litleEndian);
    TYVValueBitOutput(&a, sizeof(a), litleEndian);
    TYVValueBitOutput(&value, sizeof(value), litleEndian);
}
