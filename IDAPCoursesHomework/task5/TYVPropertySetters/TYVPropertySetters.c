//
//  TYVPropertySetters.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVObject.h"

void TYVPropertySetRetain(void **field, void *value) {
    if (NULL == field || *field == value){
        return;
    }
    
    if (NULL != value){
        TYVObjectRetain(value);
    }
    
    if (NULL != *field){
        TYVObjectRelease(*field);
    }
    
    *field = value;
}

void TYVPropertySetAssign(void **field, void *value) {
    if (NULL == field || *field == value){
        return;
    }
    
    *field = value;
}

void *TYVAutoreleasingGetter(void **field) {
    return (NULL != field) ? TYVObjectAutorelease(TYVObjectRetain(*field)) : NULL;
}
