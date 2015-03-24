//
//  TYVStackTest.c
//  IDAPCoursesHomework
//
//  Created by YURII on 24.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStackTest.h"
#include "TYVStack.h"
#include <assert.h>

void TYVStackCreateTest();
void TYVStackPopTest();
void TYVStackPushTest();
void TYVStackIsFullTest();

void TYVStackTestPerfom(){
    printf("THE STACK TESTS\n");
    TYVStackCreateTest();
    TYVStackPopTest();
    TYVStackPushTest();
    TYVStackIsFullTest();
}

void TYVStackCreateTest(){
    TYVStack *stack = TYVStackCreateWithSize(100);
    assert(TYVStackIsEmpty(stack));
    assert(100 == stack->_size);
    assert(0 == stack->_count);
    
    TYVObjectRelease(stack);
}

void TYVStackPopTest(){
    TYVStack *stack = TYVStackCreateWithSize(100);
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVStackPushItem(stack, object);
    assert(!TYVStackIsEmpty(stack));
    assert(1 == stack->_count);

    TYVObjectRelease(object);
    TYVObjectRelease(stack);
}


void TYVStackPushTest(){
    TYVStack *stack = TYVStackCreateWithSize(100);
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVObjectRetain(stack);
    TYVStackPushItem(stack, object);
    assert(1 == stack->_count);
    
    TYVObject *popObject = TYVStackPopItem(stack);
    assert(popObject == object);
    assert(TYVStackIsEmpty(stack));
    
    TYVObjectRelease(object);
    TYVObjectRelease(stack);
}

void TYVStackIsFullTest(){
    TYVStack *stack = TYVStackCreateWithSize(100);
    while (!TYVStackIsFull(stack)) {
        TYVObject *object = TYVObjectCreate(TYVObject);
        TYVStackPushItem(stack, object);
    }
    assert(100 == stack->_count);
    
    //Release
}
