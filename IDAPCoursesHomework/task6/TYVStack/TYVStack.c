//
//  TYVStack.c
//  IDAPCoursesHomework
//
//  Created by YURII on 24.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStack.h"
#include <stdlib.h>
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

void TYVStackSetSize(TYVStack *stack, size_t size);

#pragma mark -
#pragma mark Public Implementations

TYVStack *TYVStackCreate(){
    TYVStack *stack = TYVObjectCreate(TYVStack);
    
    return stack;
}

TYVStack *TYVStackCreateWithSize(size_t size) {
    TYVStack *stack = TYVObjectCreate(TYVStack);
    TYVStackSetSize(stack, size);
    
    return stack;
}

void __TYVStackDeallocate(TYVStack *stack) {
    TYVStackSetSize(stack, 0);
    __TYVObjectDeallocate(stack);
}

void TYVStackPushItem(TYVStack *stack, TYVObject *item) {
    if (NULL == stack) {
        return;
    }
    
    if (TYVStackIsFull(stack)){
        return;
    }
    
    TYVObject **head = stack->_data + stack->_count;
    *head = item;
    stack->_count++;
}

TYVObject *TYVStackPopItem(TYVStack *stack) {
    if (NULL == stack) {
        return NULL;
    }
    
    if (TYVStackIsEmpty(stack)){
        return NULL;
    }
    
    TYVObject **head = stack->_data + stack->_count - 1;
    TYVObjectRelease(*head);
    stack->_count--;
    
    // if needed ?
    return *head;
}

bool TYVStackIsFull(TYVStack *stack) {
    return (NULL != stack) ? stack->_size == stack->_count : false;
}

bool TYVStackIsEmpty(TYVStack *stack) {
    return (NULL != stack) ? 0 == stack->_count : false;
}

#pragma mark -
#pragma mark Private Implementations

void TYVStackSetSize(TYVStack *stack, size_t size) {
    if (NULL == stack || stack->_size == size) {
        return;
    }
    
    if (0 == size && NULL != stack->_data) {
        //Pop all elements
        free(stack->_data);
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