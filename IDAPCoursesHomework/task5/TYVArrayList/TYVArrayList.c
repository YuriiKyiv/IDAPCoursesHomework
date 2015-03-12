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

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize);

void TYVArrayListSetCount(TYVArrayList *array, uint64_t newCount);

void TYVArrayListResize(TYVArrayList *array);

size_t TYVArrayListGetSize(TYVArrayList *array);

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


void __TYVArrayListDeallocate(TYVArrayList *arrayList){
    
}


#pragma mark -
#pragma mark Private Implementations

void TYVArrayListSetData(TYVArrayList *arrayList, void *newData){
    if (NULL == arrayList){
        return;
    }
    
    
}

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize){
    size_t currentSize = array->_size;
    void *data = array->_data;
    if (NULL == array || currentSize == newSize){
        return;
    }
    
    data = realloc(data, newSize * sizeof(data));
    if (currentSize < newSize){
        memset(data + currentSize, 0, (newSize - currentSize) * sizeof(data));
    }
    
    array->_size =  newSize;
}

size_t TYVArrayListGetSize(TYVArrayList *array){
    return array->_size;
}
