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
    
    list->_mutationCount++;
    
    TYVContext context;
    context.comparable = object;
    context.currentNode = NULL;
    context.prevNode = NULL;
    
    TYVLinkedListNode *node = TYVLinkedListFindNodeWithObject(list, &TYVComparing, &context);
    if (NULL == node) {
        return;
    }
    
    if (NULL == context.prevNode && NULL != context.currentNode) {
        TYVLinkedListRemoveFirstObject(list);
    } else {
        TYVLinkedListNodeSetNextNode(context.prevNode, TYVLinkedListNodeGetNextNode(context.currentNode));
        list->_count--;
    }
}

void TYVLinkedListRemoveFirstObject(TYVLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    list->_mutationCount++;
    
    TYVLinkedListNode *rootNode = TYVLinkedListGetRootNode(list);
    TYVLinkedListNode *node = TYVLinkedListNodeGetNextNode(rootNode);
    TYVLinkedListSetRootNode(list, node);
    
    list->_count--;
}

void TYVLinkedListRemoveAllObjects(TYVLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    list->_mutationCount++;
    
    while (TYVLinkedListGetCount(list) > 0) {
        TYVLinkedListRemoveFirstObject(list);
    }
}

bool TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object) {
    if (NULL == list || NULL == object) {
        return false;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, object);
    if (NULL == context.currentNode && NULL == context.prevNode) {
        return false;
    } else {
        return true;
    }
}

void TYVLinkedListInsertBeforeObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object) {
    if (NULL == list || NULL == insertionPoint || NULL == object) {
        return;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, object);
    if (NULL == context.currentNode && NULL == context.prevNode) {
        return;
    }
    
    if (TYVLinkedListGetRootNode(list) == context.currentNode) {
        TYVLinkedListAddObject(list, object);
    } else {
        TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, context.currentNode);
        TYVLinkedListNodeSetNextNode(context.prevNode, newNode);
        TYVObjectRelease(newNode);
        list->_mutationCount++;
    }
    
}

void TYVLinkedListInsertAfterObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object) {
    if (NULL == list || NULL == insertionPoint || NULL == object) {
        return;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, object);
    if (NULL == context.currentNode && NULL == context.prevNode) {
        return;
    }
    
    TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, context.currentNode);
    TYVLinkedListNodeSetNextNode(newNode, TYVLinkedListNodeGetNextNode(context.currentNode));
    TYVLinkedListNodeSetNextNode(context.currentNode, newNode);
    list->_mutationCount++;
    
}

TYVContext TYVLinkedListGetContextForObject(TYVLinkedList *list, TYVObject *object) {
    TYVContext context;
    context.comparable = object;
    context.currentNode = NULL;
    context.prevNode = NULL;
    
    if (NULL == list || NULL == object) {
        context.comparable = object;
        return context;
    }
    
    TYVLinkedListNode *node = TYVLinkedListFindNodeWithObject(list, &TYVComparing, &context);
    if (NULL == node) {
        context.currentNode = NULL;
        context.prevNode = NULL;
    }
    
    return context;
}

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

TYVLinkedListNode *TYVLinkedListFindNodeWithObject(TYVLinkedList *list, TYVCompare *function, TYVContext *context) {
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
