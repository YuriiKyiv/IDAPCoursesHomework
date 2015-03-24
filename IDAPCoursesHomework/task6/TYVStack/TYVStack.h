//
//  TYVStack.h
//  IDAPCoursesHomework
//
//  Created by YURII on 24.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVStack__
#define __IDAPCoursesHomework__TYVStack__

#include <stdio.h>
#include "TYVObject.h"
#include <stdbool.h>

typedef struct TYVStack TYVStack;
struct TYVStack {
    TYVObject _super;
    
    TYVObject **_data;
    
    size_t _size;
    uint64_t _count;
};

extern
TYVStack *TYVStackCreate();

extern
void __TYVStackDeallocate(TYVStack *stack);

extern
void TYVStackPushItem(TYVStack *stack, TYVObject *data);

extern
TYVObject *TYVStackPopItem(TYVStack *stack);

extern
bool TYVStackIsFull(TYVStack *stack);

extern
bool TYVStackIsEmpty(TYVStack *stack);

#endif /* defined(__IDAPCoursesHomework__TYVStack__) */
