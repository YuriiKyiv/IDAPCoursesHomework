//
//  TYVArrayList.c
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArrayList.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "TYVPropertySetters.h"
#include <math.h>

const uint64_t TYVNotFoundItem = UINT64_MAX;

#pragma mark -
#pragma mark Private Declarations

void TYVArrayListSetSize(TYVArrayList *array, uint64_t newSize);

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount);

uint64_t TYVArrayListGetSize(TYVArrayList *array);

void TYVArrayListSetItemAtIndex(TYVArrayList *array, uint64_t index, TYVObject *item);

void TYVArrayListSetSize(TYVArrayList *array, uint64_t newSize);

uint64_t TYVArrayListGetNewSize(TYVArrayList *array);

void TYVArrayListResizeIfNeeded(TYVArrayList *array);

#pragma mark -
#pragma mark Public Implementations

TYVArrayList *TYVArrayListCreate(uint64_t size) {
    TYVArrayList *array = TYVObjectCreate(TYVArrayList);
    TYVArrayListSetSize(array, size);
    
    return array;
}

uint64_t TYVArrayListGetCount(TYVArrayList *array) {
    return (NULL != array) ? array->_count : 0;
}

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return;
    }
    
    TYVArrayListResizeIfNeeded(array);
    
    TYVArrayListSetItemAtIndex(array, TYVArrayListGetCount(array), item);
    array->_count++;
}

uint64_t TYVArrayListGetIndexOfItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return 0;
    }
    
    uint64_t currentCount = TYVArrayListGetCount(array);
    for (uint64_t iter = 0; iter < currentCount; iter++) {
        if (TYVArrayListGetItemAtIndex(array, iter) == item) {
            return iter;
        }
    }
    
    return TYVNotFoundItem;
}

void TYVArrayListRemoveItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item){
        return;
    }

    uint64_t index = TYVArrayListGetIndexOfItem(array, item);
    TYVArrayListRemoveItemAtIndex(array, index);
}

void TYVArrayListRemoveItemAtIndex(TYVArrayList *array, uint64_t index) {
    if (NULL == array || TYVArrayListGetCount(array) <= index){
        return;
    }
    
    uint64_t lastIndex = TYVArrayListGetCount(array) - 1;
    
    if (index == lastIndex) {
        TYVPropSetRetain(&array->_data[index], NULL);
    }else {
        TYVPropSetRetain(&array->_data[index], NULL);
        TYVPropSetAssign(&array->_data[index], array->_data[lastIndex]);
        TYVPropSetAssign(&array->_data[lastIndex], NULL);
    }
    
    array->_count--;
    
    TYVArrayListResizeIfNeeded(array);
}

void TYVArrayListRemoveAllItems(TYVArrayList *array) {
    if (NULL == array){
        return;
    }
    
    uint64_t currentCount = TYVArrayListGetCount(array);
    for (uint64_t iter = 0; iter < currentCount; iter++) {
        TYVArrayListRemoveItemAtIndex(array, iter);
    }    
}

void TYVArrayListRemoveItemsInRange(TYVArrayList *array, TYVRange range) {
    if (NULL == array) {
        return;
    }
   
    for (uint64_t iter = 0; iter <= range.length; iter++) {
        TYVArrayListRemoveItemAtIndex(array, range.origin + iter);
    }
}

bool TYVArrayListContainsItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return false;
    }
    
    uint64_t currentCount = TYVArrayListGetCount(array);
    for (uint64_t iter = 0; iter < currentCount; iter++) {
        if (TYVArrayListGetItemAtIndex(array, iter) == item) {
            return true;
        }
    }
    
    return false;
}

void __TYVArrayListDeallocate(TYVArrayList *arrayList) {
    TYVArrayListSetSize(arrayList, 0);
    
    __TYVObjectDeallocate(arrayList);
}


#pragma mark -
#pragma mark Private Implementations

void TYVArrayListResizeIfNeeded(TYVArrayList *array) {
    if (NULL == array) {
        return;
    }
    
    TYVArrayListSetSize(array, TYVArrayListGetNewSize(array));
}

uint64_t TYVArrayListGetNewSize(TYVArrayList *array){
    if (NULL == array) {
        return 0;
    }
    
    uint64_t count = TYVArrayListGetCount(array);
    uint64_t size = TYVArrayListGetSize(array);
    
   
    if (size == count){
        size *= 2;
    }
    
    if (size >= (count * 4)){
        size /= 2;
    }
    
    return fmax(size, 1);
}

void TYVArrayListSetItemAtIndex(TYVArrayList *array, uint64_t index, TYVObject *item) {
    if (NULL == array || NULL == item || TYVArrayListGetSize(array) <= index){
        return;
    }

    TYVPropSetRetain(&array->_data[index], item);
}

TYVObject *TYVArrayListGetItemAtIndex(TYVArrayList *array, uint64_t index) {
    if (NULL == array || TYVArrayListGetCount(array) < index){
        return NULL;
    }

    return array->_data[index];
}

void TYVArrayListSetSize(TYVArrayList *array, uint64_t newSize) {
    if (NULL == array || array->_size == newSize) {
        return;
    }
    
    if (0 == newSize && NULL != array->_data) {
        TYVArrayListRemoveAllItems(array);
        free(array->_data);
        array->_data = NULL;
        array->_size = 0;
        TYVArrayListSetCount(array, 0);
        return;
    }
    
    if (newSize < array->_size) {
        TYVRange range = {newSize, array->_size - newSize - 1};
        TYVArrayListRemoveItemsInRange(array, range);
    }
    
    array->_data = realloc(array->_data, newSize * sizeof(array->_data));
    assert(NULL != array->_data);
    if (array->_size < newSize) {
        memset(array->_data + array->_size, 0, (newSize - array->_size) * sizeof(array->_data));
    }
    
    array->_size = newSize;
}

uint64_t TYVArrayListGetSize(TYVArrayList *array) {
    return (NULL != array) ? array->_size : 0;
}

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount) {
    if (NULL == array) {
        return;
    }
    
    array->_count = newCount;
}
