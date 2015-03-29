//
//  TYVLinkedList.h
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVLinkedList__
#define __IDAPCoursesHomework__TYVLinkedList__

#include <stdio.h>
#include "TYVObject.h"
#include <stdbool.h>

typedef struct TYVLinkedListNode TYVLinkedListNode;

typedef struct TYVLinkedList TYVLinkedList;
struct TYVLinkedList {
    TYVObject _super;
    
    TYVLinkedListNode *_rootNode;
    
    uint64_t _count;
    uint64_t _mutationCount;
};

extern
TYVLinkedList *TYVLinkedListCreate();

extern
void __TYVLinkedListDeallocate(TYVLinkedList *list);

extern
void TYVLinkedListAddObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListRemoveObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListRemoveAllObjects(TYVLinkedList *list);

extern
bool TYVLinkedListContainsObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListInsertBeforeObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

extern
void TYVLinkedListInsertAfterObject(TYVLinkedList *list, TYVObject *insertionPoint, TYVObject *object);

extern
TYVObject *TYVLinkedListGetFirstObject(TYVLinkedList *list);

extern
uint64_t TYVLinkedListGetCount(TYVLinkedList *list);

#endif /* defined(__IDAPCoursesHomework__TYVLinkedList__) */
