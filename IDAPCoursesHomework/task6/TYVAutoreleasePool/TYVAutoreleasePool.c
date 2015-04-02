//
//  TYVAutoreleasePool.c
//  IDAPCoursesHomework
//
//  Created by YURII on 02.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdlib.h>

#include "TYVAutoreleasePool.h"
#include "TYVObject.h"
#include "TYVLinkedList.h"
#include "TYVAutoReleaseStack.h"
#include "TYVPropertySetters.h"

#pragma mark -
#pragma mark Private Declarations

TYVAutoreleasePool *TYVAutoreleasePoolGetPool();

void TYVAutoreleasePoolSetPool(TYVAutoreleasePool * pool);

void TYVAutoreleasePoolSetList(TYVAutoreleasePool *pool, TYVLinkedList *list);

void TYVAutoreleasePoolInsertObject(TYVAutoreleasePool *pool, TYVObject *object);

void TYVAutoreleasePoolSetCurrentStack(TYVAutoreleasePool *pool, TYVAutoReleaseStack *stack);

#pragma mark -
#pragma mark Public Implementations

static TYVAutoreleasePool *__TYVAutoreleasePool = NULL;

TYVAutoreleasePool *TYVAutoreleasePoolCreate() {
    TYVAutoreleasePool *pool = TYVAutoreleasePoolGetPool();
    
    if (NULL == pool) {
        pool = calloc(1, sizeof(*pool));
        TYVAutoreleasePoolSetPool(pool);
        
        TYVLinkedList *list = TYVLinkedListCreate();
        TYVAutoreleasePoolSetList(pool, list);
        
        TYVObjectRelease(list);
    }
    
    TYVAutoreleasePoolInsertObject(pool, NULL);
    
    return pool;
}

void __TYVAutoreleasePoolDeallocate(TYVAutoreleasePool * pool) {
    if (NULL == pool) {
        return;
    }
    
    TYVAutoreleasePoolSetList(pool, NULL);
    TYVAutoreleasePoolSetCurrentStack(pool, NULL);
    pool->_emptyStackCount = 0;
}

void TYVAutoreleasePoolAddObject(TYVAutoreleasePool *pool, TYVObject *object) {
    if (NULL == pool || NULL == object) {
        return;
    }
}

extern
void TYVAutoreleasePoolDrain(TYVAutoreleasePool *pool);

#pragma mark -
#pragma mark Private Implementations

TYVAutoreleasePool *TYVAutoreleasePoolGetPool() {
    return __TYVAutoreleasePool;
}

void TYVAutoreleasePoolSetPool(TYVAutoreleasePool * pool) {
    if (NULL == pool) {
        return;
    }
    
    __TYVAutoreleasePool = pool;
}

void TYVAutoreleasePoolSetList(TYVAutoreleasePool *pool, TYVLinkedList *list) {
    if (NULL == pool || NULL == list) {
        return;
    }
        
    TYVPropertySetRetain(&pool->_list, list);
}

void TYVAutoreleasePoolInsertObject(TYVAutoreleasePool *pool, TYVObject *object);

void TYVAutoreleasePoolSetCurrentStack(TYVAutoreleasePool *pool, TYVAutoReleaseStack *stack) {
    if (NULL == pool || NULL == stack) {
        return;
    }
    
    TYVPropertySetRetain(&pool->_currentStack, stack);
}