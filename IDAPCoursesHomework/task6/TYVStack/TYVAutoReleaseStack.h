//
//  TYVAutoReleaseStack.h
//  IDAPCoursesHomework
//
//  Created by YURII on 25.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVAutoReleaseStack__
#define __IDAPCoursesHomework__TYVAutoReleaseStack__

#include <stdio.h>
#include "TYVObject.h"
#include <stdbool.h>

typedef struct TYVAutoReleaseStack TYVAutoReleaseStack;
struct TYVAutoReleaseStack {
    TYVObject _super;
    
    TYVObject **_data;
    
    size_t _size;
    uint64_t _count;
};

extern
TYVAutoReleaseStack *TYVStackCreate();

extern
TYVAutoReleaseStack *TYVAutoReleaseStackCreateWithSize(size_t size);

extern
void __TYVAutoReleaseStackDeallocate(TYVAutoReleaseStack *stack);

extern
void TYVAutoReleaseStackPushItem(TYVAutoReleaseStack *stack, TYVObject *item);

extern
void TYVAutoReleaseStackPopItem(TYVAutoReleaseStack *stack);

extern
bool TYVAutoReleaseStackIsFull(TYVAutoReleaseStack *stack);

extern
bool TYVAutoReleaseStackIsEmpty(TYVAutoReleaseStack *stack);

#endif /* defined(__IDAPCoursesHomework__TYVAutoReleaseStack__) */
