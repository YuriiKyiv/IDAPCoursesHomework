//
//  TYVAutoreleasePool.h
//  IDAPCoursesHomework
//
//  Created by YURII on 02.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVAutoreleasePool__
#define __IDAPCoursesHomework__TYVAutoreleasePool__

#include <stdio.h>

typedef struct TYVLinkedList TYVLinkedList;
typedef struct TYVLinkedListNode TYVLinkedListNode;
typedef struct TYVAutoReleaseStack TYVAutoReleaseStack;
typedef struct TYVAutoreleasePool TYVAutoreleasePool;
typedef struct TYVObject TYVObject;

struct TYVAutoreleasePool {
    TYVLinkedList *_list;
    
    TYVAutoReleaseStack *_currentStack;
    TYVLinkedListNode *_previousStackNode;
    uint64_t _emptyStackCount;
    uint64_t _deflatingCount;
};

extern
TYVAutoreleasePool *TYVAutoreleasePoolCreate();

extern
void __TYVAutoreleasePoolDeallocate(TYVAutoreleasePool * pool);

extern
void TYVAutoreleasePoolAddObject(TYVAutoreleasePool *pool, TYVObject *object);

extern
void TYVAutoreleasePoolDrain(TYVAutoreleasePool *pool);

extern
TYVAutoreleasePool *TYVAutoreleasePoolGetPool();

#endif /* defined(__IDAPCoursesHomework__TYVAutoreleasePool__) */
