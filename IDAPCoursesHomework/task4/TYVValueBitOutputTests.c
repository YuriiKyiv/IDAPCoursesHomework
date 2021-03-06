//
//  TYVValueBitOutputTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutputTests.h"
#include "TYVValueBitOutput.h"
#include "TYVBitReverse.h"

static
void TYVBitReverseTest();

static
void TYVValueBitOutputTests();

void TYVTests(){
    TYVValueBitOutputTests();
    TYVBitReverseTest();
}

void TYVValueBitOutputTests(){
    char zero = '\0';
    char one = 1;
    char a = 'A';
    int value = 1000;
    printf("TEST 1\n");
    TYVValueBitsOutput(&zero, sizeof(zero), TYVLitleEndian);
    printf("TEST 2\n");
    TYVValueBitsOutput(&one, sizeof(one), TYVLitleEndian);
    printf("TEST 3\n");
    TYVValueBitsOutput(&a, sizeof(a), TYVLitleEndian);
    printf("TEST 4\n");
    TYVValueBitsOutput(&value, sizeof(value), TYVLitleEndian);
}

void TYVBitReverseTest(){
    int number = 1000;
    printf("Reverse test 1\n");
    TYVByteReverse(&number, sizeof(number), 1);
    TYVValueBitsOutput(&number, sizeof(number), TYVLitleEndian);
}
