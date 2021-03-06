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
    
    TYVLinkedListMutate(list);
    
    TYVLinkedListNode *rootNode = TYVLinkedListGetRootNode(list);
    TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, rootNode);
    TYVLinkedListSetRootNode(list, newNode);
    
    list->_count++;
    
    TYVObjectRelease(newNode);
    
}

void TYVLinkedListRemoveObject(TYVLinkedList *list, TYVObject *object) {
    if (NULL == list || NULL == object) {
        return;
    }
    
    TYVLinkedListMutate(list);
    
    TYVContext context = TYVLinkedListGetContextForObject(list, object);
    if (NULL == context.currentNode && NULL == context.previousNode) {
        return;
    }
    
    if (NULL == context.previousNode && NULL != context.currentNode) {
        TYVLinkedListRemoveFirstObject(list);
    } else {
        TYVLinkedListNodeSetNextNode(context.previousNode, TYVLinkedListNodeGetNextNode(context.currentNode));
        list->_count--;
    }
}

void TYVLinkedListRemoveFirstObject(TYVLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    TYVLinkedListMutate(list);
    
    TYVLinkedListNode *rootNode = TYVLinkedListGetRootNode(list);
    TYVLinkedListNode *node = TYVLinkedListNodeGetNextNode(rootNode);
    TYVLinkedListSetRootNode(list, node);
    
    list->_count--;
}

void TYVLinkedListRemoveAllObjects(TYVLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    TYVLinkedListMutate(list);
    
    TYVLinkedListSetRootNode(list, NULL);
    list->_count = 0;
}

bool TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object) {
    if (NULL == list || NULL == object) {
        return false;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, object);
    
    return (NULL != context.currentNode);
}

void TYVLinkedListInsertBeforeObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object) {
    if (NULL == list || NULL == insertionPoint || NULL == object) {
        return;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, insertionPoint);
    if (NULL == context.currentNode && NULL == context.previousNode) {
        return;
    }
    
    if (TYVLinkedListGetRootNode(list) == context.currentNode) {
        TYVLinkedListAddObject(list, object);
    } else {
        TYVLinkedListMutate(list);
        TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, context.currentNode);
        TYVLinkedListNodeSetNextNode(context.previousNode, newNode);
        TYVObjectRelease(newNode);
        list->_count++;
    }
    
}

void TYVLinkedListInsertAfterObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object) {
    if (NULL == list || NULL == insertionPoint || NULL == object) {
        return;
    }
    
    TYVContext context = TYVLinkedListGetContextForObject(list, insertionPoint);
    if (NULL == context.currentNode && NULL == context.previousNode) {
        return;
    }
    
    TYVLinkedListMutate(list);
    
    TYVLinkedListNode *newNode = TYVLinkedListNodeCreateWithObjectAndNextNode(object, context.currentNode);
    TYVLinkedListNodeSetNextNode(newNode, TYVLinkedListNodeGetNextNode(context.currentNode));
    TYVLinkedListNodeSetNextNode(context.currentNode, newNode);
    
    list->_count++;
    
    TYVObjectRelease(newNode);
    
}

TYVContext TYVLinkedListGetContextForObject(TYVLinkedList *list, TYVObject *object) {
    TYVContext context;
    context.object = object;
    context.currentNode = NULL;
    context.previousNode = NULL;
    
    if (NULL == list || NULL == object) {
        return context;
    }
    
    TYVLinkedListNode *node = TYVLinkedListFindNodeWithObject(list, &TYVLinkedListNodeContainsObject, &context);
    if (NULL == node) {
        context.currentNode = NULL;
        context.previousNode = NULL;
    }
    
    return context;
}

TYVObject *TYVLinkedListGetFirstObject(TYVLinkedList *list) {
    return (NULL != list) ? TYVLinkedListNodeGetObject(TYVLinkedListGetRootNode(list)) : NULL;
}

uint64_t TYVLinkedListGetCount(TYVLinkedList *list) {
    return (NULL != list) ? list->_count : 0;
}

void TYVLinkedListMutate(TYVLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    list->_mutationCount++;
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

TYVLinkedListNode *TYVLinkedListFindNodeWithObject(TYVLinkedList *list, TYVComparisonFunction *function, TYVContext *context) {
    if (NULL == list || NULL == function || NULL == context || NULL == context->object) {
        return NULL;
    }
    
    TYVLinkedListNode *result = NULL;
    TYVLinkedListEnumerator *enumerator = TYVLinkedListEnumeratorCreateWithList(list);
    while (TYVLinkedListEnumeratorIsValid(enumerator)) {
        TYVLinkedListEnumeratorNextObject(enumerator);
        if (function(TYVLinkedListEnumeratorGetNode(enumerator), context)) {
            result = context->currentNode;
            break;
        }
    }
    
    TYVObjectRelease(enumerator);
    
    return result;
}

void TYVLinkedListCutToNode(TYVLinkedList *list, TYVLinkedListNode *node, uint64_t emptyStackCount) {
    if (NULL == list || NULL == node) {
        return;
    }
    
    TYVLinkedListMutate(list);
    TYVLinkedListSetRootNode(list, node);
    list->_count -= emptyStackCount - 1;
}

#pragma mark -
#pragma mark Comparators

bool TYVLinkedListNodeContainsObject(TYVLinkedListNode *node, TYVContext *context) {
    if (NULL == node || NULL == context || NULL == context->object) {
        return false;
    }
    
    context->previousNode = context->currentNode;
    context->currentNode = node;
    
    return TYVLinkedListNodeGetObject(node) == context->object;
}
