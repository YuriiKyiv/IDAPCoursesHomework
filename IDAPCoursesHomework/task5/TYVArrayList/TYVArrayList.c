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

#pragma mark -
#pragma mark Private Implementations

void TYVArrayListSetData(TYVArrayList *arrayList, void *newData){
    if (NULL == arrayList || arrayList->_data == newData){
        return;
    }
    
    arrayList->_data = newData;
}

void TYVArrayListSetSize(TYVArrayList *array, size_t newSize){
    if (NULL == array || array->_size == newSize){
        return;
    }
    
    array->_size = newSize;
}
