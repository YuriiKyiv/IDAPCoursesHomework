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

void TYVArrayListAddTest();

void TYVArrayListPerfomTests(){
    printf("\nArrayList Tests\n");
    TYVArrayListCreateTest();
    TYVArrayListAddTest();
    TYVArrayListResizeTest();
    printf("ArrayList has been finished\n");
}

void TYVArrayListCreateTest(){
    TYVArrayList *arrayOne = TYVArrayListCreate(2);
    assert(0 == TYVArrayListGetCount(arrayOne));
    
    TYVArrayList *arrayTwo = TYVArrayListCreate(0);
    assert(0 == TYVArrayListGetCount(arrayTwo));
    
    TYVObjectRelease(arrayTwo);
    TYVObjectRelease(arrayOne);
}

void TYVArrayListAddTest(){
    TYVArrayList *array = TYVArrayListCreate(2);
    TYVObject *objectOne = TYVObjectCreate(TYVObject);
    TYVObject *objectTwo = TYVObjectCreate(TYVObject);
    
    TYVArrayListAddItem(array, objectOne);
    assert(1 == TYVArrayListGetCount(array));
    assert(2 == objectOne->_referenceCount);
    assert(TYVArrayListContains(array, objectOne));
    assert(0 == TYVArrayListGetIndexOfItem(array, objectOne));
    assert(objectOne == TYVArrayListGetItemAtIndex(array, 0));
    
    TYVArrayListAddItem(array, objectTwo);
    assert(2 == TYVArrayListGetCount(array));
    assert(2 == objectTwo->_referenceCount);
    assert(TYVArrayListContains(array, objectTwo));
    assert(1 == TYVArrayListGetIndexOfItem(array, objectTwo));
    assert(objectTwo == TYVArrayListGetItemAtIndex(array, 1));
    
    TYVObjectRelease(objectTwo);
    TYVObjectRelease(objectOne);
    TYVObjectRelease(array);
}

void TYVArrayListResizeTest(){
    TYVArrayList *array = TYVArrayListCreate(1);
    TYVObject *objectOne = TYVObjectCreate(TYVObject);
    TYVObject *objectTwo = TYVObjectCreate(TYVObject);
    
    TYVArrayListAddItem(array, objectOne);
    TYVArrayListAddItem(array, objectTwo);
    assert(TYVArrayListContains(array, objectOne));
    assert(TYVArrayListContains(array, objectTwo));
    
    TYVObjectRelease(objectTwo);
    TYVObjectRelease(objectOne);
    TYVObjectRelease(array);
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