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
#include "TYVLinkedListEnumerator.h"
#include "TYVLinkedListEnumeratorPrivate.h"

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
    
    TYVContext context;
    context.comparable = object;
    context.currentNode = NULL;
    context.prevNode = NULL;
    
    TYVLinkedListNode *node = TYVLinkedListFindNodeWithObject(list, TYVComparing, &context);
    if (NULL == node) {
        return;
    }
    
    if (NULL == context.prevNode && NULL != context.currentNode) {
        // remove a first object
    } else {
        TYVLinkedListNodeSetNextNode(context.prevNode, TYVLinkedListNodeGetNextNode(context.currentNode));
        TYVLinkedListNodeSetNextNode(context.currentNode, NULL);
        TYVLinkedListNodeSetObject(context.currentNode, NULL);
        list->_count--;
    }
}

extern
void TYVLinkedListRemoveAllObjects(TYVLinkedList *list);

extern
bool TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object) {
    TYVLinkedListEnumerator *enumerator = TYVLinkedListEnumeratorCreateWithList(list);
    while (TYVLinkedListEnumeratorIsValid(enumerator)) {
        if (TYVLinkedListEnumeratorNextObject(enumerator) == object) {
            TYVObjectRelease(enumerator);
            return true;
        }
    }
    
    TYVObjectRelease(enumerator);
    return false;
}

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

TYVLinkedListNode *TYVLinkedListFindNodeWithObject(TYVLinkedList *list, TYVCompare function, TYVContext *context) {
    if (NULL == list || NULL == function || NULL == context || NULL == context->comparable) {
        return NULL;
    }
    
    TYVLinkedListEnumerator *enumerator = TYVLinkedListEnumeratorCreateWithList(list);
    while (TYVLinkedListEnumeratorIsValid(enumerator)) {
        TYVLinkedListEnumeratorNextObject(enumerator);
        if (function(TYVLinkedListEnumeratorGetNode(enumerator), context)) {
            return context->currentNode;
        }
    }
    
    return NULL;
}

#pragma mark -
#pragma mark Comparators

bool TYVComparing(TYVLinkedListNode *node, TYVContext *context) {
    if (NULL == node || NULL == context || NULL == context->comparable) {
        return false;
    }
    
    context->prevNode = context->currentNode;
    context->currentNode = node;
    
    return TYVLinkedListNodeGetObject(node) == context->comparable;
}
