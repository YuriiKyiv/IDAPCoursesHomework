//
//  TYVValueBitOutputTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutputTests.h"
#include "TYVValueBitOutput.h"

void TYVValueBitOutputTest(){
    char zero = '\0';
    char one = 1;
    char a = 'A';
    int value = 1000;
    TYVValueBitOutput(&zero, sizeof(zero), TYVlitleEndian);
    TYVValueBitOutput(&one, sizeof(one), TYVlitleEndian);
    TYVValueBitOutput(&a, sizeof(a), TYVlitleEndian);
    TYVValueBitOutput(&value, sizeof(value), TYVlitleEndian);
}
