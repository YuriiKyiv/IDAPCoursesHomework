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
#include "TYVString.h"

void TYVLinkedListCreateTest();

void TYVLinkedListContainsTest();

void TYVLinkedlistBehaviorTest();

void TYVLinkedlistBehaviorTest() {
//    after creating a list
    TYVLinkedList *list =  TYVLinkedListCreate();
    
//    list count equals 0
    assert(TYVLinkedListGetCount(list) == 0);
    
//    the firt object of list equals NULL
    assert(TYVLinkedListGetFirstObject(list) == NULL);
    
    TYVObject *object1 = TYVObjectCreate(TYVObject);
    
//    after adding TYVObject object1 into the list
    TYVLinkedListAddObject(list, object1);
    
//    The list count equals 1
    assert(TYVLinkedListGetCount(list) == 1);
    
//    The first object of list equals object1
    assert(TYVLinkedListGetFirstObject(list) == object1);
    
//    the object1 reference count equals 2
    assert(TYVObjectGetReferenceCount(object1) == 2);
    
//    the list contains object1
    assert(TYVLinkedListContainsObject(list, object1));
    
//    after adding 5 times objects
    for (int i = 0; i < 5; i++) {
        TYVLinkedListAddObject(list, object1);
    }
    
//    the object reference count equals 7
    assert(TYVObjectGetReferenceCount(object1) == 7);
    
//    the list count equals 6
    assert(TYVLinkedListGetCount(list) == 6);
    
    TYVString *string = TYVStringCreate("ONE");
    
//    after inserting string after object1
    TYVLinkedListInsertAfterObject(list, object1, (TYVObject *)string);
    
//    the string reference count equals 2
    assert(TYVObjectGetReferenceCount((TYVObject *)string) == 2);
    
//    the list contains object
    assert(TYVLinkedListContainsObject(list, (TYVObject *)string));
    
//    the list count equals 7
    assert(TYVLinkedListGetCount(list) == 7);
    
//    after removing a firt objectin a list
    TYVLinkedListRemoveFirstObject(list);
    
//    the list count equals 6
    assert(TYVLinkedListGetCount(list) == 6);
    
//    the first object have to be string
    assert(TYVLinkedListGetFirstObject(list) == (TYVObject *)string);
    
//    the object1 reference count equals 6
    assert(TYVObjectGetReferenceCount(object1));
    
//    after inserting object1 before string
    TYVLinkedListInsertBeforeObject(list, (TYVObject *)string, object1);
    
//    the list count equals 7
    assert(TYVLinkedListGetCount(list) == 7);
    
//    the first object have to be object1
    assert(TYVLinkedListGetFirstObject(list) == object1);
    
//    after removing string
    TYVLinkedListRemoveObject(list, (TYVObject *)string);
    
//    sting reference count equals 1
    assert(TYVObjectGetReferenceCount((TYVObject *)string) == 1);
    
//    the list doesnt contain string
    assert(!TYVLinkedListContainsObject(list, (TYVObject *)string));
    
//    the list count equals 6
    assert(TYVLinkedListGetCount(list) == 6);
    
//    after removing all objects
    TYVLinkedListRemoveAllObjects(list);
    
//    the list count equals 0
    assert(TYVLinkedListGetCount(list) == 0);
    
//    the first object equals NULL
    assert(TYVLinkedListGetFirstObject(list) == NULL);
    
//    the object reference count equals 1
    assert(TYVObjectGetReferenceCount(object1) == 1);
    
    TYVObjectRelease(string);
    TYVObjectRelease(object1);
    TYVObjectRelease(list);
}

void TYVLinkedListPerfomTest() {
    printf("TASK 6 LinkedList PERFOM TEST\n");
    TYVLinkedlistBehaviorTest();
    TYVLinkedListCreateTest();
    TYVLinkedListContainsTest();
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

void TYVLinkedListContainsTest() {
    TYVObject *object = TYVObjectCreate(TYVObject);
    TYVLinkedList *list =  TYVLinkedListCreate();
    assert(!TYVLinkedListContainsObject(list, object));
    TYVLinkedListAddObject(list, object);
    assert(TYVLinkedListContainsObject(list, object));
    
    TYVObjectRelease(list);
    TYVObjectRelease(object);
}
