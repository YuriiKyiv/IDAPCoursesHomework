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

void TYVArrayListCreateTest();

void TYVArrayListPerfomTests(){
    printf("\nArrayList Tests\n");
    TYVArrayListCreateTest();
}

void TYVArrayListCreateTest(){
    TYVArrayList *array = TYVArrayListCreate(2);
    assert(0 == TYVArrayListGetCount(array));
    assert(2 == TYVArrayListGetSize(array));
}