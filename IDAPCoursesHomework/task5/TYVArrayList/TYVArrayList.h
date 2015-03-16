//
//  TYVArrayList.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVArrayList__
#define __IDAPCoursesHomework__TYVArrayList__

#include <stdio.h>
#include "TYVObject.h"
#include "stdbool.h"

typedef struct TYVArrayList TYVArrayList;
struct TYVArrayList {
    TYVObject _object;
    
    TYVObject **_data;
    
    uint64_t _count;
    size_t _size;
};

TYVArrayList *TYVArrayListCreate(size_t size);

void __TYVArrayListDeallocate(TYVArrayList *arrayList);

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item);

void TYVArrayListRemoveItem(TYVArrayList *array, TYVObject *item);

void TYVArrayListRemoveItems(TYVArrayList *array);

bool TYVArrayListIsContain(TYVArrayList *array, TYVObject *item);

uint64_t TYVArrayListGetCount(TYVArrayList *array);

#endif /* defined(__IDAPCoursesHomework__TYVArrayList__) */
