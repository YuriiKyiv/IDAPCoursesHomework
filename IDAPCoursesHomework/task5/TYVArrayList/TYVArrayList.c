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

#pragma mark -
#pragma mark Private Declarations

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize);

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount);

size_t TYVArrayListGetSize(TYVArrayList *array);

void TYVArrayListSwapItems(TYVArrayList *array, size_t indexFirst, size_t indexSecond);

#pragma mark -
#pragma mark Public Implementations

TYVArrayList *TYVArrayListCreate(size_t size){
    TYVArrayList *array = TYVObjectCreate(TYVArrayList);
    TYVArrayListSetSize(array, size);
    
    return array;
}

uint64_t TYVArrayListGetCount(TYVArrayList *array){
    return array->_count;
}

void TYVArrayListAddItem(TYVArrayList *array, TYVObject *item){
    if (NULL == array || NULL == item){
        return;
    }
    
    size_t currentSize = TYVArrayListGetSize(array);
    
    if (currentSize == TYVArrayListGetCount(array)){
        TYVArrayListSetSize(array, currentSize * 2);
    }
    
    TYVObjectRetain(item);
    array->_data[TYVArrayListGetCount(array)] = item;
    array->_count++;
}

void TYVArrayListRemoveItem(TYVArrayList *array, TYVObject *item){
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

void TYVArrayListRemoveItems(TYVArrayList *array){
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

bool TYVArrayListIsContain(TYVArrayList *array, TYVObject *item){
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

void __TYVArrayListDeallocate(TYVArrayList *arrayList){
    TYVArrayListSetSize(arrayList, 0);
    
    __TYVObjectDeallocate(arrayList);
}


#pragma mark -
#pragma mark Private Implementations

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize){
    if (NULL == array || array->_size == newSize){
        return;
    }
    
    if (0 == newSize && NULL != array->_data){
        free(array->_data);
        array->_data = NULL;
        array->_size = 0;
        TYVArrayListSetCount(array, 0);
        return;
    }
    
    array->_data = realloc(array->_data, newSize * sizeof(array->_data));
    assert(NULL != array->_data);
    if (array->_size < newSize){
        memset(array->_data + array->_size, 0, (newSize - array->_size) * sizeof(array->_data));
    }
    
    array->_size = newSize;
}

size_t TYVArrayListGetSize(TYVArrayList *array){
    return array->_size;
}

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount){
    if (NULL == array){
        return;
    }
    
    array->_count = newCount;
}

void TYVArrayListSwapItems(TYVArrayList *array, size_t indexFirst, size_t indexSecond){
    if (NULL == array) {
        return;
    }
    
    TYVObject *tempItem = array->_data[indexFirst];
    array->_data[indexFirst] = array->_data[indexSecond];
    array->_data[indexSecond] = tempItem;
}
