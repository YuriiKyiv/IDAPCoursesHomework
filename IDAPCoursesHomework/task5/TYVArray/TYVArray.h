//
//  TYVArray.h
//  IDAPCoursesHomework
//
//  Created by YURII on 02.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVArray__
#define __IDAPCoursesHomework__TYVArray__

#include <stdio.h>
#include "TYVObject.h"

#endif /* defined(__IDAPCoursesHomework__TYVArray__) */

typedef struct TYVArray TYVArray;
struct TYVArray {
    TYVObject _object;
    
    void *_array[20];
    uint8_t _count;
};

void TYVArrayAdd(TYVArray *array, void *);

void TYVArrayRemove(TYVArray *array, void *);

void __TYVArrayDeallocate(TYVArray *array);
