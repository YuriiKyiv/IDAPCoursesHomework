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

#pragma mark -
#pragma mark Private Declarations

void TYVAutoReleaseStackSetSize(TYVAutoReleaseStack *stack, size_t size);

TYVObject **TYVAutoReleaseStackGetHead(TYVAutoReleaseStack *stack);

#pragma mark -
#pragma mark Public Implementations

TYVAutoReleaseStack *TYVAutoReleaseStackCreate(){
    TYVAutoReleaseStack *stack = TYVObjectCreate(TYVAutoReleaseStack);
    
    return stack;
}

TYVAutoReleaseStack *TYVAutoReleaseStackCreateWithSize(size_t size) {
    TYVAutoReleaseStack *stack = TYVObjectCreate(TYVAutoReleaseStack);
    TYVAutoReleaseStackSetSize(stack, size);
    
    return stack;
}

void __TYVAutoReleaseStackDeallocate(TYVAutoReleaseStack *stack) {
    TYVAutoReleaseStackSetSize(stack, 0);
    __TYVObjectDeallocate(stack);
}

void TYVAutoReleaseStackPushItem(TYVAutoReleaseStack *stack, TYVObject *item) {
    if (NULL == stack) {
        return;
    }
    
    if (TYVAutoReleaseStackIsFull(stack)){
        return;
    }
    
    TYVObject **head = stack->_data + stack->_count;
    *head = item;
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
    
    TYVObject **head = stack->_data + stack->_count - 1;
    if (NULL != *head) {
        TYVObjectRelease(*head);
        result = TYVAutoReleaseStackPopObject;
    }
    
     stack->_count--;
    
    return result;
    
}

void TYVAutoReleaseStackPopItems(TYVAutoReleaseStack *stack) {
    if (NULL == stack) {
        return;
    }
    
    while (!TYVAutoReleaseStackIsEmpty(stack)
           || (TYVAutoReleaseStackPopObject == TYVAutoReleaseStackPopItem(stack)))
    {
        
    }
}

void TYVAutoReleaseStackPopAllItem(TYVAutoReleaseStack *stack) {
    if (NULL == stack) {
        return;
    }
    
    while (!TYVAutoReleaseStackIsEmpty(stack)) {
        TYVAutoReleaseStackPopItem(stack);
    }
}

bool TYVAutoReleaseStackIsFull(TYVAutoReleaseStack *stack) {
    return (NULL != stack) ? stack->_size == stack->_count : false;
}

bool TYVAutoReleaseStackIsEmpty(TYVAutoReleaseStack *stack) {
    return (NULL != stack) ? 0 == stack->_count : false;
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
        //Pop all elements
        free(stack->_data);
        stack->_data = NULL;
        stack->_count = 0;
        stack->_size = 0;
        return;
    }
    
    if (stack->_size > size) {
        // release object which which are between size and stack->_size
        // make pop while count != size
    }
    
    stack->_data = realloc(stack->_data, size * sizeof(*stack->_data));
    
    if (stack->_size < size) {
        // check pointer and size in memset
        memset(stack->_data + stack->_size, 0, size - stack->_size);
    }
    
    stack->_size = size;
}