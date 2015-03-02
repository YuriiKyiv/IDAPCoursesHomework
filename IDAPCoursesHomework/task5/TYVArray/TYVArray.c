//
//  TYVArray.c
//  IDAPCoursesHomework
//
//  Created by YURII on 02.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVArray.h"

void TYVArrayAdd(TYVArray *array, void *object){
    uint8_t iter = 0;
    while (NULL != array->_array[iter] && iter < 20) {
        iter++;
    }
    
    if (iter > 19){
        return;
    }
    
    array->_array[iter] = object;
    TYVObjectRetain(object);
}

void TYVArrayRemove(TYVArray *array, void *object){
    uint8_t iter = 0;
    while (object != array->_array[iter] && iter < 20) {
        iter++;
    }
    
    if (iter > 19){
        return;
    }
    
    TYVObjectRelease(array->_array[iter]);
    array->_array[iter] = NULL;
}
