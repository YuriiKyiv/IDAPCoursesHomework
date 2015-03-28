//
//  TYVLinkedList.c
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedList.h"
#include "TYVLinkedListNode.h"
#include "TYVLinkedListPrivate.h"
#include "TYVPropertySetters.h"

#pragma mark -
#pragma mark Public Implementations

TYVLinkedList *TYVLinkedListCreate(){
    return TYVObjectCreate(TYVLinkedList);
}

void __TYVLinkedListDeallocate(TYVLinkedList *list){
    if (NULL == list) {
        return;
    }
    
    TYVLinkedListSetRootNode(list, NULL);
    
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
    list->_mutationCount++;
    
    TYVObjectRelease(newNode);
    
}

void TYVLinkedListRemoveObject(TYVLinkedList *list, TYVObject *object) {
    if (NULL == list || NULL == object) {
        return;
    }
}

extern
void TYVLinkedListRemoveAllObjects(TYVLinkedList *list);

extern
void TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListInsertBeforeObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

extern
void TYVLinkedListInsertAfterObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

TYVObject *TYVLinkedListGetFirstObject(TYVLinkedList *list) {
    return (NULL != list) ? TYVLinkedListNodeGetObject(TYVLinkedListGetRootNode(list)) : NULL;
}

uint64_t TYVLinkedListGetCount(TYVLinkedList *list) {
    return (NULL != list) ? list->_count : 0;
}

#pragma mark -
#pragma mark Private Implementations

void TYVLinkedListSetRootNode(TYVLinkedList *list, TYVLinkedListNode *node) {
    if (NULL == list) {
        return;
    }
    
    TYVPropertySetRetain(&list->_rootNode, node);
}

TYVLinkedListNode *TYVLinkedListGetRootNode(TYVLinkedList *list) {
    return (NULL != list) ? list->_rootNode : NULL;
}

uint64_t TYVLinkedListGetMutationCount(TYVLinkedList *list) {
    return (NULL != list) ? list->_mutationCount : 0;
}
