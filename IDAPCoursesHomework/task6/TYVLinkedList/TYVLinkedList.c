//
//  TYVLinkedList.c
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedList.h"
#include "TYVLinkedListNode.h"

#pragma mark -
#pragma mark Private Declarations

void TYVLinkedListSetRootNode(TYVLinkedList *list, TYVLinkedListNode *node);

TYVLinkedListNode *TYVLinkedListGetRootNode(TYVLinkedList *list);

#pragma mark -
#pragma mark Public Implementations

TYVLinkedList *TYVLinkedListCreate(){
    return TYVObjectCreate(TYVLinkedList);
}

void __TYVLinkedListDeallocate(TYVLinkedList *list){
    //add setters
    
    __TYVObjectDeallocate(list);
}

void TYVLinkedListAddObject(TYVLinkedList *list, TYVObject *object) {
    if (NULL == list || NULL == object) {
        return;
    }
    
    TYVLinkedListNode *rootNode = TYVLinkedListGetRootNode(list);
    TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, rootNode);
    TYVLinkedListSetRootNode(list, newNode);
    
    list->_count++;
    
    TYVObjectRelease(newNode);
    
}

extern
void TYVLinkedListRemoveObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListRemoveAllObjects(TYVLinkedList *list);

extern
void TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListInsertBeforeObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

extern
void TYVLinkedListInsertAfterObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

extern
TYVLinkedListNode *TYVLinkedListGetFirstObject(TYVLinkedList *list);

extern
uint64_t TYVLinkedListGetCount(TYVLinkedList *list);

#pragma mark -
#pragma mark Private Implementations
