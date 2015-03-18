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

const size_t TYVNotFoundItem = SIZE_MAX;

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
    return (NULL != array) ? array->_count : 0;
}

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return;
    }
    
    TYVArrayListSetItemAtIndex(array, TYVArrayListGetCount(array), item);
}

size_t TYVArrayListGetIndexOfItem(TYVArrayList *array, TYVObject *item) {
    if (NULL == array || NULL == item) {
        return 0;
    }
    
    uint64_t currentCount = TYVArrayListGetCount(array);
    for (size_t iter = 0; iter < currentCount; iter++) {
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

void TYVArrayListRemoveItemAtIndex(TYVArrayList *array, size_t index){
    if (NULL == array || TYVArrayListGetCount(array) <= index){
        return;
    }
    
    TYVPropertySetRetainVoid(&array->_data[index], NULL);
}

void TYVArrayListRemoveAllItems(TYVArrayList *array) {
    if (NULL == array){
        return;
    }
    
    size_t currentCount = TYVArrayListGetCount(array);
    for (size_t iter = 0; iter < currentCount; iter++) {
        TYVArrayListRemoveItemAtIndex(array, iter);
    }    
}

void TYVArrayListRemoveItems(TYVArrayList *array, size_t beginIndex, size_t endIndex){
    if (NULL == array || TYVArrayListGetCount(array) <= endIndex || beginIndex > endIndex) {
        return;
    }
    
    for (size_t iter = beginIndex; endIndex >= iter; iter++) {
        TYVArrayListRemoveItemAtIndex(array, iter);
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
    if (NULL == array || NULL == item || TYVArrayListGetCount(array) <= index){
        return;
    }
    
    TYVPropertySetRetainVoid(&array->_data[index], index);
}

TYVObject *TYVArrayListGetItemAtIndex(TYVArrayList *array, size_t index) {
    if (NULL == array || TYVArrayListGetCount(array) < index){
        return NULL;
    }

    return array->_data[index];
}

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize) {
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
    
    if (array->_size > newSize){
        TYVArrayListRemoveItems(array, newSize - 1, array->_size - 1);
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
