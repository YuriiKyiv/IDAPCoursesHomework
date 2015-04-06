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
#include "TYVLinkedListEnumerator.h"
#include "TYVLinkedListPrivate.h"
#include "TYVLinkedListNode.h"
#include "TYVLinkedListEnumeratorPrivate.h"

static
const uint64_t TYVAutoreleasingStackMaxCount = 512;

static
const uint64_t TYVAutoreleasingStackDeflatingCount = 2;

#pragma mark -
#pragma mark Private Declarations

void TYVAutoreleasePoolSetPool(TYVAutoreleasePool * pool);

void TYVAutoreleasePoolSetList(TYVAutoreleasePool *pool, TYVLinkedList *list);

TYVLinkedList *TYVAutoreleasePoolGetList(TYVAutoreleasePool *pool);

void TYVAutoreleasePoolInsertObject(TYVAutoreleasePool *pool, TYVObject *object);

void TYVAutoreleasePoolSetCurrentStack(TYVAutoreleasePool *pool, TYVAutoReleaseStack *stack);

TYVAutoReleaseStack *TYVAutoreleasePoolGetCurrentStack(TYVAutoreleasePool *pool);

void TYVAutoreleasePoolDeflateIfNeeded(TYVAutoreleasePool *pool);

void TYVAutoreleasePoolDeflating(TYVAutoreleasePool *pool);

void TYVAutoreleasePoolValidate(TYVAutoreleasePool *pool);

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
    
    assert(NULL != object);
    
    TYVAutoreleasePoolValidate(pool);
    
    TYVAutoreleasePoolInsertObject(pool, object);
}

void TYVAutoreleasePoolDrain(TYVAutoreleasePool *pool) {
    if (NULL == pool) {
        return;
    }
    
    TYVLinkedList *list = TYVAutoreleasePoolGetList(pool);
    TYVAutoReleaseStack *stack = TYVAutoreleasePoolGetCurrentStack(pool);
    TYVAutoReleaseStackPopType popType;
    TYVLinkedListEnumerator *enumerator = TYVLinkedListEnumeratorCreateWithList(list);

    while (TYVLinkedListEnumeratorIsValid(enumerator)
           && TYVLinkedListEnumeratorNextObject(enumerator) != (TYVObject *)stack)
    {
    }
    
    do {
        popType = TYVAutoReleaseStackPopItems(stack);
        if (TYVAutoReleaseStackIsEmpty(stack)) {
            pool->_previousStackNode = TYVLinkedListEnumeratorGetNode(enumerator);
            stack = (TYVAutoReleaseStack *)TYVLinkedListEnumeratorNextObject(enumerator);
            TYVAutoreleasePoolSetCurrentStack(pool, stack);
            pool->_emptyStackCount++;
        }
        
    } while (TYVAutoReleaseStackIsEmpty((TYVAutoReleaseStack *)TYVLinkedListNodeGetObject(pool->_previousStackNode))
             && popType == TYVAutoReleaseStackPopObject);
    
    TYVObjectRelease(enumerator);
    
    
    TYVAutoreleasePoolDeflateIfNeeded(pool);
    
}

TYVAutoreleasePool *TYVAutoreleasePoolGetPool() {
    return __TYVAutoreleasePool;
}

#pragma mark -
#pragma mark Private Implementations

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
    if (NULL == pool) {
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
    
    TYVAutoReleaseStackPushItem(TYVAutoreleasePoolGetCurrentStack(pool), object);
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

void TYVAutoreleasePoolDeflateIfNeeded(TYVAutoreleasePool *pool) {
    if (NULL == pool) {
        return;
    }
    
    uint64_t deflatingCount = TYVAutoreleasingStackDeflatingCount;
    if (deflatingCount < pool->_emptyStackCount) {
        TYVAutoreleasePoolDeflating(pool);
    }
}

void TYVAutoreleasePoolDeflating(TYVAutoreleasePool *pool) {
    if (NULL == pool || pool->_previousStackNode == NULL) {
        return;
    }
    
    TYVLinkedList *list = TYVAutoreleasePoolGetList(pool);
    list->_mutationCount++;
    TYVLinkedListSetRootNode(list, pool->_previousStackNode);
#warning is a count correct?
    list->_count -= pool->_emptyStackCount - 1;
    pool->_emptyStackCount = 1;
    pool->_previousStackNode = NULL;
}

void TYVAutoreleasePoolValidate(TYVAutoreleasePool *pool) {
    if (NULL == pool) {
        return;
    }
    
    uint64_t deflatingCount = TYVAutoreleasingStackDeflatingCount;
    TYVLinkedList *list = TYVAutoreleasePoolGetList(pool);
    if (TYVLinkedListGetCount(list) <= deflatingCount) {
        TYVLinkedListEnumerator *enumerator = TYVLinkedListEnumeratorCreateWithList(list);
        TYVAutoReleaseStack *stack = NULL;
        while (TYVLinkedListEnumeratorIsValid(enumerator)) {
            stack = (TYVAutoReleaseStack *)TYVLinkedListEnumeratorNextObject(enumerator);
        }
        
        TYVObjectRelease(enumerator);
        assert(!TYVAutoReleaseStackIsEmpty(stack));
    }
}
