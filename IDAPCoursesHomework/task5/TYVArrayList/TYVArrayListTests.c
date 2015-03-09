//
//  TYVArrayListTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArrayListTests.h"
#include "TYVArrayList.h"
#include "assert.h"
#include "stdlib.h"

void TYVArrayListCreateTest();

void TYVArrayListResizeTest();

void TYVArrayListPerfomTests(){
    printf("\nArrayList Tests\n");
    TYVArrayListCreateTest();
    TYVArrayListResizeTest();
}

void TYVArrayListCreateTest(){
    TYVArrayList *array = TYVArrayListCreate(2);
    assert(0 == TYVArrayListGetCount(array));
    assert(2 == TYVArrayListGetSize(array));
}

void TYVArrayListResizeTest(){
    TYVArrayList *array = TYVArrayListCreate(1);
    void *one = calloc(1, sizeof(char));
    TYVArrayListAddItem(array, one);
    assert(1 == TYVArrayListGetCount(array));
    TYVArrayListAddItem(array, one);
    assert(2 == TYVArrayListGetCount(array));
    assert(2 == TYVArrayListGetSize(array));
}