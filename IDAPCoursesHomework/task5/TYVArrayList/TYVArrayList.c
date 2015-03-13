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
        array->_count = 0;
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
