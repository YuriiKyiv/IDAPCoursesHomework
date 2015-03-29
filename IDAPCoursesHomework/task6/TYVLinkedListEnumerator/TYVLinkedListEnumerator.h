//
//  TYVLinkedListEnumerator.h
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVLinkedListEnumerator__
#define __IDAPCoursesHomework__TYVLinkedListEnumerator__

#include <stdio.h>
#include "TYVObject.h"
#include <stdbool.h>

typedef struct TYVLinkedList TYVLinkedList;
typedef struct TYVLinkedListNode TYVLinkedListNode;

typedef struct TYVLinkedListEnumerator TYVLinkedListEnumerator;
struct TYVLinkedListEnumerator {
    TYVObject _super;
    
    TYVLinkedList *_list;
    TYVLinkedListNode *_node;
    
    uint64_t _mutationCount;
    bool _valid;
};

extern
TYVLinkedListEnumerator *TYVLinkedListEnumeratorCreateWithList(TYVLinkedList *list);

extern
void __TYVLinkedListEnumeratorDeallocate(TYVLinkedListEnumerator *enumerator);

extern
TYVObject *TYVLinkedListEnumeratorNextObject(TYVLinkedListEnumerator *enumerator);

extern
bool TYVLinkedListEnumeratorIsValid(TYVLinkedListEnumerator *enumerator);

#endif /* defined(__IDAPCoursesHomework__TYVLinkedListEnumerator__) */
