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
    
    return enumerator;
}

void __TYVLinkedListEnumeratorDeallocate(TYVLinkedListEnumerator *enumerator) {
    TYVLinkedListEnumeratorSetList(enumerator, NULL);
    TYVLinkedListEnumeratorSetNode(enumerator, NULL);
    
    __TYVObjectDeallocate(enumerator);
}

extern
TYVObject *TYVLinkedListEnumeratorNextObject(TYVLinkedListEnumerator *enumerator);

extern
bool TYVLinkedListEnumeratorIsValid(TYVLinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Private Implementations

void TYVLinkedListEnumeratorSetList(TYVLinkedListEnumerator *enumerator, TYVLinkedList *list) {
    if (NULL == enumerator) {
        return;
    }
    
    TYVPropertySetRetain(enumerator->_list, list);
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
