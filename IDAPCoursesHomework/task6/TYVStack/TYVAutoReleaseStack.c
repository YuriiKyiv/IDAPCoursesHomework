//
//  TYVAutoReleaseStack.c
//  IDAPCoursesHomework
//
//  Created by YURII on 25.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVAutoReleaseStack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma mark -
#pragma mark Private Declarations

void TYVAutoReleaseStackSetSize(TYVAutoReleaseStack *stack, size_t size);

TYVObject **TYVAutoReleaseStackGetHead(TYVAutoReleaseStack *stack);

#pragma mark -
#pragma mark Public Implementations

TYVAutoReleaseStack *TYVAutoReleaseStackCreateWithSize(size_t size) {
    assert(0 != size);
    TYVAutoReleaseStack *stack = TYVObjectCreate(TYVAutoReleaseStack);
    TYVAutoReleaseStackSetSize(stack, size);
    
    return stack;
}

void __TYVAutoReleaseStackDeallocate(TYVAutoReleaseStack *stack) {
    TYVAutoReleaseStackSetSize(stack, 0);
    __TYVObjectDeallocate(stack);
}

uint64_t TYVAutoReleaseStackGetCount(TYVAutoReleaseStack *stack){
    return stack->_count;
}

void TYVAutoReleaseStackPushItem(TYVAutoReleaseStack *stack, TYVObject *item) {
    if (NULL == stack) {
        return;
    }
    
    if (TYVAutoReleaseStackIsFull(stack)){
        return;
    }
    
    TYVObject **newHead = TYVAutoReleaseStackGetHead(stack) + 1;
    *newHead = item;
    stack->_count++;
}

TYVAutoReleaseStackPopType TYVAutoReleaseStackPopItem(TYVAutoReleaseStack *stack) {
    TYVAutoReleaseStackPopType result = TYVAutoReleaseStackPopNULL;
    if (NULL == stack) {
        return result;
    }
    
    if (TYVAutoReleaseStackIsEmpty(stack)){
        return result;
    }
    
    TYVObject **head = TYVAutoReleaseStackGetHead(stack);
    if (NULL != *head) {
        TYVObjectRelease(*head);
        result = TYVAutoReleaseStackPopObject;
    }
    
     stack->_count--;
    
    return result;
    
}

TYVAutoReleaseStackPopType TYVAutoReleaseStackPopItems(TYVAutoReleaseStack *stack) {
    if (NULL == stack) {
        return TYVAutoReleaseStackPopNULL;
    }

    while (TYVAutoReleaseStackPopObject == TYVAutoReleaseStackPopItem(stack)) {
        if (TYVAutoReleaseStackIsEmpty(stack)) {
            return TYVAutoReleaseStackPopObject;
        }
    }
    
    return TYVAutoReleaseStackPopNULL;
}

void TYVAutoReleaseStackPopAllItems(TYVAutoReleaseStack *stack) {
    if (NULL == stack) {
        return;
    }
    
    while (!TYVAutoReleaseStackIsEmpty(stack)) {
        TYVAutoReleaseStackPopItem(stack);
    }
}

bool TYVAutoReleaseStackIsFull(TYVAutoReleaseStack *stack) {
    return ((NULL != stack) && (stack->_size == stack->_count));
}

bool TYVAutoReleaseStackIsEmpty(TYVAutoReleaseStack *stack) {
    return ((NULL != stack) && (0 == stack->_count));
}

#pragma mark -
#pragma mark Private Implementations

TYVObject **TYVAutoReleaseStackGetHead(TYVAutoReleaseStack *stack) {
    if (NULL == stack) {
        return NULL;
    }
    
    return stack->_data + stack->_count - 1;
}

void TYVAutoReleaseStackSetSize(TYVAutoReleaseStack *stack, size_t size) {
    if (NULL == stack || stack->_size == size) {
        return;
    }
    
    if (0 == size && NULL != stack->_data) {
        TYVAutoReleaseStackPopAllItems(stack);
        free(stack->_data);
        stack->_data = NULL;
    } else {
        stack->_data = calloc(size, sizeof(*stack->_data));
        assert(NULL != stack->_data);
    }
    
    stack->_size = size;
}
