//
//  TYVStack.c
//  IDAPCoursesHomework
//
//  Created by YURII on 24.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStack.h"
#include <stdlib.h>

#pragma mark -
#pragma mark Private Declarations


#pragma mark -
#pragma mark Public Implementations

TYVStack *TYVStackCreate(){
    TYVStack *stack = TYVObjectCreate(TYVStack);
    return stack;
}

TYVStack *TYVStackCreateWithSize(size_t size){
    TYVStack *stack = TYVObjectCreate(TYVStack);
    stack->_size = size;
    stack->_data = calloc(stack->_size, sizeof(*stack->_data));
    return stack;
}

void __TYVStackDeallocate(TYVStack *stack){
    
}

extern
void TYVStackPushItem(TYVStack *stack, TYVObject *data);

extern
TYVObject *TYVStackPopItem(TYVStack *stack);

bool TYVStackIsFull(TYVStack *stack) {
    return (NULL != stack) ? stack->_size == stack->_currentSize : false;
}

bool TYVStackIsEmpty(TYVStack *stack) {
    return (NULL != stack) ? 0 == stack->_currentSize : false;
}

#pragma mark -
#pragma mark Private Implementations