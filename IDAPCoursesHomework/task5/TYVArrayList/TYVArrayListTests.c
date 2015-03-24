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

void TYVArrayListRemoveTest();

void TYVArrayListPerfomTests(){
    printf("\nArrayList Tests\n");
    //TYVArrayListCreateTest();
    //TYVArrayListAddTest();
    TYVArrayListResizeTest();
    TYVArrayListRemoveTest();
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
    assert(TYVArrayListContainsItem(array, objectOne));
    assert(0 == TYVArrayListGetIndexOfItem(array, objectOne));
    assert(objectOne == TYVArrayListGetItemAtIndex(array, 0));
    
    TYVArrayListAddItem(array, objectTwo);
    assert(2 == TYVArrayListGetCount(array));
    assert(2 == objectTwo->_referenceCount);
    assert(TYVArrayListContainsItem(array, objectTwo));
    assert(1 == TYVArrayListGetIndexOfItem(array, objectTwo));
    assert(objectTwo == TYVArrayListGetItemAtIndex(array, 1));
    
    TYVObjectRelease(objectTwo);
    TYVObjectRelease(objectOne);
    TYVObjectRelease(array);
}

void TYVArrayListRemoveTest(){
    TYVArrayList *array = TYVArrayListCreate(2);
    TYVObject *objectOne = TYVObjectCreate(TYVObject);
    TYVObject *objectTwo = TYVObjectCreate(TYVObject);
    
    TYVArrayListAddItem(array, objectOne);
    TYVArrayListAddItem(array, objectTwo);
    
    TYVArrayListRemoveItem(array, objectOne);
    assert(false == TYVArrayListContainsItem(array, objectOne));
    assert(1 == objectOne->_referenceCount);
    assert(1 == TYVArrayListGetCount(array));
    
    TYVArrayListRemoveItemAtIndex(array, 0);
    assert(false == TYVArrayListContainsItem(array, objectTwo));
    assert(1 == objectTwo->_referenceCount);
    assert(0 == TYVArrayListGetCount(array));
    
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
    assert(TYVArrayListContainsItem(array, objectOne));
    assert(TYVArrayListContainsItem(array, objectTwo));
    
    TYVArrayList *arrayMega = TYVArrayListCreate(1);
    TYVObject *object = TYVObjectCreate(TYVObject);
    for (size_t iter = 0; iter < 1000; iter++){
        TYVArrayListAddItem(arrayMega, object);
        assert(iter + 1 == TYVArrayListGetCount(arrayMega));
    }
    assert(1000 == TYVArrayListGetCount(arrayMega));
    
    for (size_t iter = 0; iter < 1000; iter++){
        TYVArrayListRemoveItem(arrayMega, object);
        assert(1000 - iter - 1 == TYVArrayListGetCount(arrayMega));
    }
    
    TYVObjectRelease(object);
    TYVObjectRelease(arrayMega);
    TYVObjectRelease(objectTwo);
    TYVObjectRelease(objectOne);
    TYVObjectRelease(array);
}

//  after creating array with size equls 0
//      count equls 0
//      array doesnt contain any objects
//      get item at index return NULL
//      get index of object equls 0
//          after adding TYVObject object1
//                count equls 1
//                array contains object1
//                get index of object1 equls 0
//                get item at zero index equls object1
//                      after adding TYVObject object2
//                          count equls 2
//                          array contains object2
//                          get index of object2 equals 1
//                          get item at first index equls object2
//                              after removing item at zero index
//                                  count equls 1
//                                  get item at zero index equls object2
//                                  array doesnt contain object1
//                                  array contains object2
//                                      after removing all items
//                                          count equls 0
//                                          array doesnt contain any objects
