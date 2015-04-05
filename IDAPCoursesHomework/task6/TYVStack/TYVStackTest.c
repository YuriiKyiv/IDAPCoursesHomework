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
void TYVAutoReleaseStackBehaviorTest();

void TYVStackTestPerfom(){
    printf("THE STACK TESTS\n");
    TYVStackCreateTest();
    TYVStackPopTest();
    TYVStackPushTest();
    TYVStackIsFullTest();
    TYVAutoReleaseStackBehaviorTest();
}

//  after creating TYVAutoReleaseStack with size equals 3
//      The stack is empty
//          after adding TYVObject object1
//              count equals 1
//              reference count of object equals 1
//              stack should not be empty
//              after adding TYVObject object1 15 times
//                  it has count 16
//                  after addinh NULL
//                      it has count 17
//                      after adding TYVObject object1 10 times
//                          it has count 27



void TYVAutoReleaseStackBehaviorTest(){
    TYVAutoReleaseStack *stack = TYVAutoReleaseStackCreateWithSize(100);
    assert(TYVAutoReleaseStackIsEmpty(stack));
    
    TYVObject *object1 = TYVObjectCreate(TYVObject);
    TYVObjectRetain(object1);
    TYVAutoReleaseStackPushItem(stack, object1);
    assert(TYVAutoReleaseStackGetCount(stack) == 1);
    assert(TYVObjectGetReferenceCount(object1) == 2);
    assert(!TYVAutoReleaseStackIsEmpty(stack));
    
    for (int i = 0; i < 15; i++) {
        TYVObjectRetain(object1);
        TYVAutoReleaseStackPushItem(stack, object1);
    }
    assert(TYVObjectGetReferenceCount(object1) == 17);
    assert(TYVAutoReleaseStackGetCount(stack) == 16);
    
    TYVAutoReleaseStackPushItem(stack, NULL);
    assert(TYVAutoReleaseStackGetCount(stack) == 17);
    for (int i = 0; i < 10; i++) {
        TYVObjectRetain(object1);
        TYVAutoReleaseStackPushItem(stack, object1);
    }
    assert(TYVAutoReleaseStackGetCount(stack) == 27);
    assert(TYVObjectGetReferenceCount(object1) == 27);
    
    TYVAutoReleaseStackPopType type =  TYVAutoReleaseStackPopItem(stack);
    assert(TYVAutoReleaseStackPopObject == type);
    assert(TYVAutoReleaseStackGetCount(stack) == 26);
    
    type =  TYVAutoReleaseStackPopItems(stack);
    assert(TYVAutoReleaseStackPopNULL == type);
    assert(TYVAutoReleaseStackGetCount(stack) == 16);
    
    type =  TYVAutoReleaseStackPopItems(stack);
    assert(TYVAutoReleaseStackPopObject == type);
    assert(TYVAutoReleaseStackGetCount(stack) == 0);
    assert(TYVAutoReleaseStackIsEmpty(stack));
    
    for (int i = 0; i < 10; i++) {
        TYVObjectRetain(object1);
        TYVAutoReleaseStackPushItem(stack, object1);
    }
    assert(TYVObjectGetReferenceCount(object1) == 11);
    assert(TYVAutoReleaseStackGetCount(stack) == 10);
    TYVAutoReleaseStackPopAllItems(stack);
    assert(TYVAutoReleaseStackGetCount(stack) == 0);
    assert(TYVAutoReleaseStackIsEmpty(stack));
    assert(TYVObjectGetReferenceCount(object1) == 1);
    
    
    TYVObjectRelease(object1);
    TYVObjectRelease(stack);
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
