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
#include "TYVRange.h"

extern
const uint64_t TYVNotFoundItem;

typedef struct TYVArrayList TYVArrayList;
struct TYVArrayList {
    TYVObject _object;
    
    TYVObject **_data;
    
    uint64_t _count;
    uint64_t _size;
};

TYVArrayList *TYVArrayListCreate();

void __TYVArrayListDeallocate(TYVArrayList *arrayList);

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item);

TYVObject *TYVArrayListGetItemAtIndex(TYVArrayList *array, uint64_t index);

uint64_t TYVArrayListGetIndexOfItem(TYVArrayList *array, TYVObject *item);

void TYVArrayListRemoveItem(TYVArrayList *array, TYVObject *item);

void TYVArrayListRemoveItemAtIndex(TYVArrayList *array, uint64_t index);

void TYVArrayListRemoveAllItems(TYVArrayList *array);

void TYVArrayListRemoveItemsInRange(TYVArrayList *array, TYVRange range);

bool TYVArrayListContainsItem(TYVArrayList *array, TYVObject *item);

uint64_t TYVArrayListGetCount(TYVArrayList *array);

TYVArrayList *TYVArrayListCreateWithSize(uint64_t size);

#endif /* defined(__IDAPCoursesHomework__TYVArrayList__) */
