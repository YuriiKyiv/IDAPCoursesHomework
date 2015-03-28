//
//  TYVLinkedListTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListTests.h"
#include <assert.h>
#include "TYVLinkedList.h"
#include "TYVLinkedListNode.h"

void TYVLinkedListCreateTest();

void TYVLinkedListPerfomTest() {
    printf("TASK 6 LinkedList PERFOM TEST\n");
    TYVLinkedListCreateTest();
}

void TYVLinkedListCreateTest() {
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVLinkedList *list =  TYVLinkedListCreate();
    assert(0 == TYVLinkedListGetCount(list));
    assert(NULL == TYVLinkedListGetFirstObject(list));
    
    TYVLinkedListAddObject(list, object);
    assert(1 == TYVLinkedListGetCount(list));
    assert(TYVLinkedListGetFirstObject(list) == object);
    assert(2 == object->_referenceCount);
    
    TYVObjectRelease(list);
    TYVObjectRelease(object);
}