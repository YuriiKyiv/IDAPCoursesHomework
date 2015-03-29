//
//  TYVLinkedListEnumerator.c
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListEnumerator.h"
#include "TYVLinkedListPrivate.h"
#include "TYVLinkedListEnumeratorPrivate.h"
#include "TYVPropertySetters.h"
#include "TYVLinkedListNode.h"

#pragma mark -
#pragma mark Public Implementations

TYVLinkedListEnumerator *TYVLinkedListEnumeratorCreateWithList(TYVLinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    TYVLinkedListEnumerator *enumerator = TYVObjectCreate(TYVLinkedListEnumerator);
    TYVLinkedListEnumeratorSetList(enumerator, list);
    TYVLinkedListEnumeratorSetMutationCount(enumerator, TYVLinkedListGetMutationCount(list));
    enumerator->_valid = true;
    
    return enumerator;
}

void __TYVLinkedListEnumeratorDeallocate(TYVLinkedListEnumerator *enumerator) {
    TYVLinkedListEnumeratorSetList(enumerator, NULL);
    TYVLinkedListEnumeratorSetNode(enumerator, NULL);
    
    __TYVObjectDeallocate(enumerator);
}

TYVObject *TYVLinkedListEnumeratorNextObject(TYVLinkedListEnumerator *enumerator) {
    if (NULL == enumerator) {
        return NULL;
    }
    
    return TYVLinkedListNodeGetObject(TYVLinkedListEnumeratorNextNode(enumerator));
}

bool TYVLinkedListEnumeratorIsValid(TYVLinkedListEnumerator *enumerator) {
    return ((NULL != enumerator) && enumerator->_valid);
}

#pragma mark -
#pragma mark Private Implementations

void TYVLinkedListEnumeratorSetList(TYVLinkedListEnumerator *enumerator, TYVLinkedList *list) {
    if (NULL == enumerator) {
        return;
    }
    
    TYVPropertySetRetain(&enumerator->_list, list);
}

TYVLinkedList *TYVLinkedListEnumeratorGetList(TYVLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_list : NULL;
}

void TYVLinkedListEnumeratorSetNode(TYVLinkedListEnumerator *enumerator, TYVLinkedListNode *node) {
    if (NULL == enumerator) {
        return;
    }
    
    TYVPropertySetRetain(&enumerator->_node, node);
}

TYVLinkedListNode *TYVLinkedListEnumeratorGetNode(TYVLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_node : NULL;
}

void TYVLinkedListEnumeratorSetMutationCount(TYVLinkedListEnumerator *enumerator, uint64_t mutationCount) {
    if (NULL == enumerator) {
        return;
    }
    
    enumerator->_mutationCount = mutationCount;
}

uint64_t TYVLinkedListEnumeratorGetMutationCount(TYVLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_mutationCount : 0;
}

bool TYVLinkedListEnumeratorCheckMutation(TYVLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? TYVLinkedListGetMutationCount(TYVLinkedListEnumeratorGetList(enumerator)) == TYVLinkedListEnumeratorGetMutationCount(enumerator) : false;
}

TYVLinkedListNode *TYVLinkedListEnumeratorNextNode(TYVLinkedListEnumerator *enumerator) {
    if (NULL == enumerator
        || !TYVLinkedListEnumeratorIsValid(enumerator)
        || !TYVLinkedListEnumeratorCheckMutation(enumerator))
    {
        return NULL;
    }
    
    TYVLinkedListNode *node = TYVLinkedListEnumeratorGetNode(enumerator);
    TYVLinkedListNode *nextNode = NULL;
    if (NULL == node) {
        nextNode = TYVLinkedListGetRootNode(TYVLinkedListEnumeratorGetList(enumerator));
    } else {
        nextNode = TYVLinkedListNodeGetNextNode(node);
    }
    
    TYVLinkedListEnumeratorSetNode(enumerator, nextNode);
    
    if (NULL == nextNode) {
        enumerator->_valid = false;
    }
    
    return nextNode;
}
