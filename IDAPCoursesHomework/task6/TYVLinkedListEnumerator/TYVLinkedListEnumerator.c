//
//  TYVLinkedListEnumerator.c
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListEnumerator.h"

#pragma mark -
#pragma mark Private Declarations

void TYVLinkedListEnumeratorSetList(TYVLinkedListEnumerator *enumerator, TYVLinkedList *list);

void TYVLinkedListEnumeratorSetMurationCount(TYVLinkedListEnumerator *enumerator, uint64_t *mutationCount);

#pragma mark -
#pragma mark Public Implementations

TYVLinkedListEnumerator *TYVLinkedListEnumeratorCreate(TYVLinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    TYVLinkedListEnumerator *enumerator = TYVObjectCreate(TYVLinkedListEnumerator);
    TYVLinkedListEnumeratorSetList(enumerator, list);
//    TYVLinkedListEnumeratorSetMurationCount(enumerator, TYVLinkedList)
    
    return enumerator;
}

extern
void __TYVLinkedListEnumeratorDeallocate(TYVLinkedListEnumerator *enumerator);

extern
TYVObject *TYVLinkedListEnumeratorNextObject(TYVLinkedListEnumerator *enumerator);

extern
bool TYVLinkedListEnumeratorIsValid(TYVLinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Private Implementations
