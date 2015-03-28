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
    TYVLinkedListNode *nodeNext = TYVLinkedListNodeCreateWithObject(object);
    assert(3 == object->_referenceCount);
    assert(TYVLinkedListNodeGetObject(node) == object);
    assert(TYVLinkedListNodeGetNextNode(node) == NULL);
    TYVLinkedListNodeSetNextNode(node, nodeNext);
    assert(TYVLinkedListNodeGetNextNode(node) == nodeNext);
    
    TYVObjectRelease(nodeNext);
    TYVObjectRelease(node);
    TYVObjectRelease(object);
}