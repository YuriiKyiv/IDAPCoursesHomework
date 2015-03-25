//
//  TYVStackTest.c
//  IDAPCoursesHomework
//
//  Created by YURII on 24.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStackTest.h"
#include "TYVAutoReleaseStack.h"
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
    TYVAutoReleaseStack *stack = TYVAutoReleaseStackCreateWithSize(100);
    assert(TYVAutoReleaseStackIsEmpty(stack));
    assert(100 == stack->_size);
    assert(0 == stack->_count);
    
    TYVObjectRelease(stack);
}

void TYVStackPushTest(){
    TYVAutoReleaseStack *stack = TYVAutoReleaseStackCreateWithSize(100);
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVAutoReleaseStackPushItem(stack, object);
    assert(!TYVAutoReleaseStackIsEmpty(stack));
    assert(1 == stack->_count);

    TYVObjectRelease(object);
    TYVObjectRelease(stack);
}


void TYVStackPopTest(){
    TYVAutoReleaseStack *stack = TYVAutoReleaseStackCreateWithSize(100);
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVObjectRetain(stack);
    TYVAutoReleaseStackPushItem(stack, object);
    assert(1 == stack->_count);
    
    TYVAutoReleaseStackPopType popObject = TYVAutoReleaseStackPopItem(stack);
    assert(popObject == TYVAutoReleaseStackPopObject);
    assert(TYVAutoReleaseStackIsEmpty(stack));
    
    TYVObjectRelease(object);
    TYVObjectRelease(stack);
}

void TYVStackIsFullTest(){
    TYVAutoReleaseStack *stack = TYVAutoReleaseStackCreateWithSize(100);
    while (!TYVAutoReleaseStackIsFull(stack)) {
        TYVObject *object = TYVObjectCreate(TYVObject);
        TYVAutoReleaseStackPushItem(stack, object);
    }
    assert(100 == stack->_count);
    
    while (!TYVAutoReleaseStackIsEmpty(stack)) {
        TYVAutoReleaseStackPopItem(stack);
    }
}
