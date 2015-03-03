//
//  TYVArray.c
//  IDAPCoursesHomework
//
//  Created by YURII on 02.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArray.h"

#pragma mark -
#pragma mark Private Declarations

uint8_t TYVArrayItemLoop(TYVArray *array, void *object);

#pragma mark -
#pragma mark Public Implementations

void TYVArrayAdd(TYVArray *array, void *object){
    uint8_t iter = TYVArrayItemLoop(array, object);
    
    if (iter < 0){
        return;
    }
    
    array->_array[iter] = object;
    TYVObjectRetain(object);
}

void TYVArrayRemove(TYVArray *array, void *object){
    uint8_t iter = TYVArrayItemLoop(array, object);
    
    if (iter < 0){
        return;
    }
    
    TYVObjectRelease(array->_array[iter]);
    array->_array[iter] = NULL;
}

#pragma mark -
#pragma mark Private Implementations

uint8_t TYVArrayItemLoop(TYVArray *array, void *object){
    uint8_t iter = 0;
    while (object != array->_array[iter] && iter < 20) {
        iter++;
    }
    
    if (iter > 19){
        return -1;
    }
    
    return iter;
}
