//
//  TYVAutoreleasePool.c
//  IDAPCoursesHomework
//
//  Created by YURII on 02.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>

#include "TYVAutoreleasePool.h"
#include "TYVObject.h"
#include "TYVLinkedList.h"
#include "TYVAutoReleaseStack.h"
#include "TYVPropertySetters.h"

static
const uint64_t TYVAutoreleasingStackMaxCount = 512;

#pragma mark -
#pragma mark Private Declarations

TYVAutoreleasePool *TYVAutoreleasePoolGetPool();

void TYVAutoreleasePoolSetPool(TYVAutoreleasePool * pool);

void TYVAutoreleasePoolSetList(TYVAutoreleasePool *pool, TYVLinkedList *list);

TYVLinkedList *TYVAutoreleasePoolGetList(TYVAutoreleasePool *pool);

void TYVAutoreleasePoolInsertObject(TYVAutoreleasePool *pool, TYVObject *object);

void TYVAutoreleasePoolSetCurrentStack(TYVAutoreleasePool *pool, TYVAutoReleaseStack *stack);

TYVAutoReleaseStack *TYVAutoreleasePoolGetCurrentStack(TYVAutoreleasePool *pool);

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
    free(pool);
}

void TYVAutoreleasePoolAddObject(TYVAutoreleasePool *pool, TYVObject *object) {
    if (NULL == pool) {
        return;
    }
    
    assert(NULL == object);
    
    TYVAutoreleasePoolInsertObject(pool, object);
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

TYVLinkedList *TYVAutoreleasePoolGetList(TYVAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_list : NULL;
}

void TYVAutoreleasePoolInsertObject(TYVAutoreleasePool *pool, TYVObject *object) {
    if (NULL == pool || NULL == object) {
        return;
    }
    
    uint64_t size = TYVAutoreleasingStackMaxCount;
    
    TYVLinkedList *list = TYVAutoreleasePoolGetList(pool);
    TYVAutoReleaseStack *stack = TYVAutoreleasePoolGetCurrentStack(pool);
    if (NULL == stack || TYVAutoReleaseStackIsFull(stack)) {
        TYVAutoReleaseStack *newStack = TYVAutoReleaseStackCreateWithSize(size);
        TYVLinkedListAddObject(list, (TYVObject *)newStack);
        TYVAutoreleasePoolSetCurrentStack(pool, newStack);
        
        TYVObjectRelease(newStack);
    }
    
    TYVAutoReleaseStackPushItem(stack, object);
}

void TYVAutoreleasePoolSetCurrentStack(TYVAutoreleasePool *pool, TYVAutoReleaseStack *stack) {
    if (NULL == pool || NULL == stack) {
        return;
    }
    
    TYVPropertySetRetain(&pool->_currentStack, stack);
}

TYVAutoReleaseStack *TYVAutoreleasePoolGetCurrentStack(TYVAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_currentStack : NULL;
}