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

TYVStack *TYVStackCreateWithSize(size_t size){
    TYVStack *stack = TYVObjectCreate(TYVStack);
    TYVStackSetSize(stack, size);
    
    return stack;
}

void __TYVStackDeallocate(TYVStack *stack){
    TYVStackSetSize(stack, 0);
    __TYVObjectDeallocate(stack);
}

extern
void TYVStackPushItem(TYVStack *stack, TYVObject *data);

extern
TYVObject *TYVStackPopItem(TYVStack *stack);

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
        free(stack->_data);
    }
    
    if (stack->_size > size) {
        // release object which which are between size and stack->_size
        // make pop while count != size
    }
    
    stack->_data = calloc(stack->_size, sizeof(*stack->_data));
    
    if (stack->_size < size) {
        // check pointer and size
        memset(stack->_data + size, 0, stack->_size - size);
    }
    
    stack->_size = size;
}