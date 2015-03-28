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

#pragma mark -
#pragma mark Public Implementations

TYVLinkedListEnumerator *TYVLinkedListEnumeratorCreate(TYVLinkedList *list) {
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
    if (NULL == enumerator || !TYVLinkedListEnumeratorIsValid(enumerator) || !TYVLinkedListEnumeratorCheckMutation(enumerator)) {
        return NULL;
    }
    
    return NULL;
}

extern
bool TYVLinkedListEnumeratorIsValid(TYVLinkedListEnumerator *enumerator) {
    if (NULL == enumerator ||TYVLinkedListEnumeratorNextObject(enumerator) == NULL) {
        return false;
    }
    
    return true;
}

#pragma mark -
#pragma mark Private Implementations

void TYVLinkedListEnumeratorSetList(TYVLinkedListEnumerator *enumerator, TYVLinkedList *list) {
    if (NULL == enumerator) {
        return;
    }
    
    TYVPropertySetRetain(enumerator->_list, list);
}

TYVLinkedList *TYVLinkedListEnumeratorGetList(TYVLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_list : NULL;
}

void TYVLinkedListEnumeratorSetNode(TYVLinkedListEnumerator *enumerator, TYVLinkedList *node) {
    if (NULL == enumerator) {
        return;
    }
    
    TYVPropertySetRetain(enumerator->_node, node);
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
