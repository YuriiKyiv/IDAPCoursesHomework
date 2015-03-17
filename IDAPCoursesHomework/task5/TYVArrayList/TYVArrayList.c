//
//  TYVArrayList.c
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArrayList.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "TYVPropertySetters.h"

const static size_t TYVNotFoundItem = SIZE_MAX;

#pragma mark -
#pragma mark Private Declarations

//typedef bool(TYVCompute)(TYVObject *, TYVObject *);

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize);

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount);

size_t TYVArrayListGetSize(TYVArrayList *array);

void TYVArrayListSwapItems(TYVArrayList *array, size_t indexFirst, size_t indexSecond);

void TYVArrayListSetItemAtIndex(TYVArrayList *array, size_t index, TYVObject *item);

#pragma mark -
#pragma mark Public Implementations

TYVArrayList *TYVArrayListCreate(size_t size) {
    TYVArrayList *array = TYVObjectCreate(TYVArrayList);
    TYVArrayListSetSize(array, size);
    
    return array;
}

uint64_t TYVArrayListGetCount(TYVArrayList *array) {
    return array->_count;
}

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return;
    }
    
    size_t currentSize = TYVArrayListGetSize(array);
    
    if (currentSize == TYVArrayListGetCount(array)) {
        TYVArrayListSetSize(array, currentSize * 2);
    }
    
    TYVObjectRetain(item);
    array->_data[TYVArrayListGetCount(array)] = item;
    array->_count++;
}

size_t TYVArrayListGetIndexOfItem(TYVArrayList *array, TYVObject *item) {
    size_t result = TYVNotFoundItem;
    if (NULL == array || NULL == item) {
        return TYVNotFoundItem;
    }
    
    for (size_t iter = 0; iter < TYVArrayListGetCount(array); iter++) {
        if (TYVArrayListGetItemAtIndex(array, iter) == item) {
            result = iter;
        }
    }
    
    return result;
}

void TYVArrayListRemoveItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item){
        return;
    }
    
    size_t currentCount = TYVArrayListGetCount(array);
    for (size_t iter = 0; iter < currentCount; iter++) {
        if (array->_data[iter] == item){
            TYVObjectRelease(array->_data[iter]);
            array->_data[iter] = NULL;
            TYVArrayListSwapItems(array, iter, currentCount);
            array->_count--;
            break;
        }
    }
}

void TYVArrayListRemoveItems(TYVArrayList *array) {
    if (NULL == array){
        return;
    }
    
    size_t currentCount = TYVArrayListGetCount(array);
    for (size_t iter = 0; iter < currentCount; iter++) {
        TYVObjectRelease(array->_data[iter]);
        array->_data[iter] = NULL;
        array->_count--;
    }    
}

bool TYVArrayListIsContain(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item){
        return false;
    }
    
    size_t currentCount = TYVArrayListGetCount(array);
    for (size_t iter = 0; iter < currentCount; iter++) {
        if (array->_data[iter] == item){
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

void TYVArrayListSetItemAtIndex(TYVArrayList *array, size_t index, TYVObject *item) {
    if (NULL == array || NULL == item || TYVArrayListGetCount(array) < index){
        return;
    }
    // resize if needed
    TYVPropertySetRetainVoid(array->_data[index], index);
}

TYVObject *TYVArrayListGetItemAtIndex(TYVArrayList *array, size_t index) {
    if (NULL == array || TYVArrayListGetCount(array) < index){
        return NULL;
    }
    
    TYVObject *item = array->_data[index];
    TYVPropertySetRetainVoid(array->_data[index], NULL);
    return item;
}

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize) {
    if (NULL == array || array->_size == newSize) {
        return;
    }
    
    if (0 == newSize && NULL != array->_data) {
        free(array->_data);
        array->_data = NULL;
        array->_size = 0;
        TYVArrayListSetCount(array, 0);
        return;
    }
    
    array->_data = realloc(array->_data, newSize * sizeof(array->_data));
    assert(NULL != array->_data);
    if (array->_size < newSize) {
        memset(array->_data + array->_size, 0, (newSize - array->_size) * sizeof(array->_data));
    }
    
    array->_size = newSize;
}

size_t TYVArrayListGetSize(TYVArrayList *array) {
    return array->_size;
}

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount) {
    if (NULL == array) {
        return;
    }
    
    array->_count = newCount;
}

void TYVArrayListSwapItems(TYVArrayList *array, size_t indexFirst, size_t indexSecond) {
    if (NULL == array) {
        return;
    }
    
    TYVObject *tempItem = array->_data[indexFirst];
    array->_data[indexFirst] = array->_data[indexSecond];
    array->_data[indexSecond] = tempItem;
}

//bool TYVArrayListIterationWithFunction(TYVArrayList *array, TYVCompute *compute, TYVObject* compared){
//    for (size_t iter = 0; iter < array->_count; iter++) {
//        if (compute(array->_data[iter], compared)){
//            return true;
//        }
//    }
//    return false;
//}
//
//bool TYVIsContain(TYVObject *item, TYVObject *compared){
//    return (item == compared) ? true : false;
//}
//
//bool TYVArrayIsContain(TYVArrayList *array, TYVObject* compared){
//    return (TYVArrayListIterationWithFunction(array, TYVIsContain(<#TYVObject *item#>, <#TYVObject *compared#>), <#TYVObject *argumant#>))
//}
