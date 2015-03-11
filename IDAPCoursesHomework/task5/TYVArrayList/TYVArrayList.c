//
//  TYVArrayList.c
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArrayList.h"
#include "stdlib.h"

#pragma mark -
#pragma mark Private Declarations

void TYVArrayListSetData(TYVArrayList *arrayList, void *newData);

void *TYVArrayListGetData(TYVArrayList *array);

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize);

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount);

void TYVArrayListResize(TYVArrayList *array);

size_t TYVArrayListGetSize(TYVArrayList *array);

#pragma mark -
#pragma mark Public Implementations

TYVArrayList *TYVArrayListCreate(size_t size){
    if (0 == size){
        size = 1;
    }
    TYVArrayList *arrayList = TYVObjectCreate(TYVArrayList);
    void *newData = calloc(size, sizeof(*newData));
    TYVArrayListSetData(arrayList, newData);
    TYVArrayListSetSize(arrayList, size);
    
    return arrayList;
}



void __TYVArrayListDeallocate(TYVArrayList *arrayList){
    
}

uint64_t TYVArrayListGetCount(TYVArrayList *array){
    return (NULL != array) ? array->_count : 0;
}

size_t TYVArrayListGetSize(TYVArrayList *array){
    return (NULL != array) ? array->_size : 0;
}

void TYVArrayListAddItem(TYVArrayList *array, void *item){
    if (NULL == array){
        return;
    }
    
    uint64_t currentCount = TYVArrayListGetCount(array);
    size_t arraySize = TYVArrayListGetSize(array);
    
    if (arraySize == currentCount){
        TYVArrayListResize(array);
    }
    
    void *data = TYVArrayListGetData(array);
    size_t iter = 0;
    while ((NULL != &data[iter]) && (iter < arraySize)) {
        iter++;
    }
    
    TYVArrayListSetCount(array, currentCount + 1);
    //data[iter] = *item;
}

#pragma mark -
#pragma mark Private Implementations

void TYVArrayListSetData(TYVArrayList *arrayList, void *newData){
    if (NULL == arrayList || arrayList->_data == newData){
        return;
    }
    
    arrayList->_data = newData;
}

void *TYVArrayListGetData(TYVArrayList *array){
    return (NULL != array) ? array->_data : NULL;
}

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize){
    if (NULL == array || array->_size == newSize){
        return;
    }
    
    array->_size = newSize;
}

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount){
    if (NULL == array || array->_count == newCount){
        return;
    }
    
    array->_count = newCount;
}

void TYVArrayListResize(TYVArrayList *array){
    if (NULL == array){
        return;
    }
    
    size_t newSize = TYVArrayListGetSize(array)*2;
    void *newData = realloc(TYVArrayListGetData(array), newSize);
    TYVArrayListSetData(array, newData);
    TYVArrayListSetSize(array, newSize);
}
