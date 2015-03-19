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
#include "TYVHuman.h"

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
}

void TYVArrayListResizeTest(){
    
}

// after creating 1-size arraylist
//      size of arraylist is 1
//      count of arraylist is 0
//      after adding not NULL object
//          count of arraylist is 1
//          after adding not NULL object
//              count of arraylist is 2
//              size of arraylist is 2
//              after adding not NULL object
//                  count of arraylist is 3
//                  size of arraylist is 4
//                  after removing not NULL object
//                      count of arraylist is 2
//                      size of arraylist is 4
//                      after removing not NULL object which is contained
//                          count of arraylist is 1
//                          size of arraylist is 2

// after creating 1-size arraylist
//      after adding NULL object
//      NOTHING

// after creating 1-size arraylist
//      after adding not NULL object
//      after removing NULL object
//      NOTHING