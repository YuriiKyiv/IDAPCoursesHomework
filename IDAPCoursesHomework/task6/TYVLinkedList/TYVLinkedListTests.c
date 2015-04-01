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
//  after creating a list
    TYVLinkedList *list =  TYVLinkedListCreate();
    
//  list count equals 0
    assert(0 == TYVLinkedListGetCount(list));
    
//  the firt object of list equals NULL
    assert(NULL == TYVLinkedListGetFirstObject(list));
    
    TYVObject *object = TYVObjectCreate(TYVObject);
    
//      after adding TYVObject object into the list
    TYVLinkedListAddObject(list, object);
    
//      The list count equals 1
    assert(1 == TYVLinkedListGetCount(list));
    
//      The first object of list equals object
    assert(TYVLinkedListGetFirstObject(list) == object);
    
//      the object reference count equals 2
    assert(2 == object->_referenceCount);
    
//      the list contains object
    assert(TYVLinkedListContainsObject(list, object));
    
//          after adding 5 times object
    for (int i = 0; i < 5; i++) {
        TYVLinkedListAddObject(list, object);
    }
    
//          the object reference count equals 7
    assert(7 == object->_referenceCount);
    
//          the list count equals 6
    assert(6 == TYVLinkedListGetCount(list));
    
    TYVString *string = TYVStringCreate("mamaPapa");
    
//          after inserting string after object
    TYVLinkedListInsertAfterObject(list, object, (TYVObject *)string);
    
//              the string reference count equals 2
    assert(2 == TYVObjectGetReferenceCount((TYVObject *)string));
    
//              the list contains object
    assert(TYVLinkedListContainsObject(list, (TYVObject *)string));
    
//              after removing a firt objectin a list
    TYVLinkedListRemoveFirstObject(list);
    
//                  the list count equals 5
    assert(5 == TYVLinkedListGetCount(list));

//                  the first object have to be string
    assert(TYVLinkedListGetFirstObject(list) == (TYVObject *)string);

//                  after inserting object before string
    TYVLinkedListInsertBeforeObject(list, (TYVObject *)string, object);
    
//                      the list count equals 6
    assert(6 == TYVLinkedListGetCount(list));
 
//                      the first object have to be object
    assert(TYVLinkedListGetFirstObject(list) == object);

//                      after removing string
    TYVLinkedListRemoveObject(list, (TYVObject *)string);
    
//                          sting reference count equals 1
    assert(TYVObjectGetReferenceCount((TYVObject *)string) == 1);
    
//                          the list doesnt contain string
    assert(!TYVLinkedListContainsObject(list, (TYVObject *)string));
    
//                          the list count equals 5
    assert(5 == TYVLinkedListGetCount(list));

//                          after removing all objects
    TYVLinkedListRemoveAllObjects(list);
    
//                              the list count equals 0
    assert(TYVLinkedListGetCount(list) == 0);
    
//                              the first object equals NULL
    assert(TYVLinkedListGetFirstObject(list) == NULL);
    
//                              the object reference count equals 1
    assert(TYVObjectGetReferenceCount(object) == 1);
    
    
    TYVObjectRelease(string);
    TYVObjectRelease(object);
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
