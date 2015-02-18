//
//  TYVName.c
//  IDAPCoursesHomework
//
//  Created by YURII on 18.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVName.h"
#include "stdlib.h"
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

static
void IDPStringStructStackDealloc(TYVName *name);

#pragma mark -
#pragma mark Public Implementations

TYVName *TYVNameCreate(){
    TYVName *name = malloc(sizeof(*name));
    name->_name = NULL;
    name->_referenceCount = 1;
    
    return name;
}

void TYVNameRetain(TYVName *name){
    name->_referenceCount++;
}

void TYVNameRelease(TYVName *name){
    name->_referenceCount--;
    if (0 == name->_referenceCount) {
        //Dealloc
    }
}

uint64_t TYVNameGetLength(TYVName *name){
    return name->_length;
}

void TYVNameSetLength(TYVName *name, uint64_t length){
    if (length > name->_length){
        name->_name = realloc(name->_name, length * sizeof(*name->_name));
        memset(name->_name + name->_length, 0, length - name->_length);
    }
    
    if (length < name->_length){
        name->_name = realloc(name->_name, length * sizeof(*name->_name));
    }
    
    name->_length = length;
}

char *TYVNameGetName(TYVName *name){
    return name->_name;
}

#pragma mark -
#pragma mark Private Implementations

void IDPStringStructStackDealloc(TYVName *name) {
    if (NULL != name->_name) {
        free(name->_name);
    }
    
    free(name);
}