//
//  TYVLinkedListNodeTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListNodeTests.h"
#include "TYVLinkedListNode.h"
#include <assert.h>

void TYVLinkedListNodeCreateTest();

void TYVLinkedListNodePerfomTest() {
    printf("TASK 6 NODE PERFOM TEST\n");
    TYVLinkedListNodeCreateTest();
}

void TYVLinkedListNodeCreateTest() {
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVLinkedListNode *node = TYVLinkedListNodeCreateWithObject(object);
    assert(2 == object->_referenceCount);
    
    TYVObjectRelease(node);
    TYVObjectRelease(object);
}