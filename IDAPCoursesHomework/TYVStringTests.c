//
//  TYVStringTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStringTests.h"
#include "TYVString.h"
#include "assert.h"

static
void TYVStringCreateTest();

static
void TYVStringRetainTest();

static
void TYVStringReleaseTest();

void TYVStringTestsPerfom(){
    printf("\nTASK 5\n");
    TYVStringCreateTest();
    TYVStringRetainTest();
    TYVStringReleaseTest();
}

void TYVStringCreateTest(){
    char name[] = "Vasy Pupkin";
    TYVString *string = TYVStringCreate(name, 8);
    printf("Length = %d\n",TYVStringGetLength(string));
    printf("Name = %s\n",TYVStringGetData(string));
    assert(TYVStringGetLength(string) == 8);
}

void TYVStringRetainTest(){
    char name[] = "Vasy Pupkin";
    TYVString *string = TYVStringCreate(name, 8);
    TYVStringRetain(string);
    printf("Reference = %zu\n", string->_referenceCount);
    assert(string->_referenceCount == 2);
}

void TYVStringReleaseTest(){
    char name[] = "Vasy Pupkin";
    TYVString *string = TYVStringCreate(name, 8);
    TYVStringRetain(string);
    TYVStringRelease(string);
    printf("Reference = %zu\n", string->_referenceCount);
    assert(string->_referenceCount == 1);
}