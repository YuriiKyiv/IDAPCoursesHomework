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

void TYVArrayListResize(TYVArrayList *array);

#pragma mark -
#pragma mark Public Implementations

TYVArrayList *TYVArrayListCreate(size_t size){
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

void TYVArraListAddItem(TYVArrayList *array, void *item){
    if (NULL == array){
        return;
    }
    
    if (TYVArrayListGetSize(array) == TYVArrayListGetCount(array)){
        TYVArrayListResize(array);
    }
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

void TYVArrayListResize(TYVArrayList *array){
    if (NULL == array){
        return;
    }
    
    void *newData = realloc(TYVArrayListGetData(array), TYVArrayListGetSize(array)*2);
    TYVArrayListSetData(array, newData);
}
