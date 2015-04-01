//
//  TYVObject.c
//  IDAPCoursesHomework
//
//  Created by YURII on 27.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVObject.h"
#include "stdlib.h"

void *__TYVObjectCreate(size_t objectSize, TYVDeallocateCallback deallocateCallback){
    TYVObject *object = calloc(1, objectSize);
    object->_referenceCount = 1;
    object->_deallocateCallback = deallocateCallback;
    
    return object;
}

void *TYVObjectRetain(void *object){
    if (NULL != object){
        ((TYVObject *)object)->_referenceCount++;
    }
    
    return object;
}

void TYVObjectRelease(void *voidObject){
    if (NULL == voidObject){
        return;
    }
    
    TYVObject *object = (TYVObject *)voidObject;
    object->_referenceCount--;
    if (0 == object->_referenceCount) {
        object->_deallocateCallback(object);
    }
}

void __TYVObjectDeallocate(void *object){
    free(object);
}

uint64_t TYVObjectGetReferenceCount(TYVObject *object) {
    return (NULL != object) ? object->_referenceCount : 0;
}
