//
//  TYVUniversalSetters.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVUniversalSetters.h"
#include "TYVObject.h"

#pragma mark -
#pragma mark Public Implementations

void TYVUniversalSetRetain(void **field, void *value){
    if (NULL == field || *field == value){
        return;
    }
    
    if (NULL != *field){
        TYVObjectRelease(*field);
    }
    
    if (NULL != value){
        TYVObjectRetain(value);
    }
    
    *field = value;
}

void TYVUniversalSetAssign(void **field, void *value){
    if (NULL == field || *field == value){
        return;
    }
    
    *field = value;
}