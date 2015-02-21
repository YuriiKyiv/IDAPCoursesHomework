//
//  TYVString.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVString.h"
#include "stdlib.h"

#pragma mark -
#pragma mark Private Declarations

static
void TYVStringDealloc(TYVString *string);

#pragma mark -
#pragma mark Public Implementations

TYVString *TYVStringCreate(char *data, uint8_t length){
    TYVString *string = malloc(sizeof(*string));
    string->_data = data;
    string->_length = length;
    string->_referenceCount = 1;
    
    return string;
}

void TYVStringRetain(TYVString *string){
    string->_referenceCount++;
}

void TYVStringRelease(TYVString *string){
    string->_referenceCount--;
    if (0 == string->_referenceCount){
        TYVStringDealloc(string);
    }
}

char *TYVStringGetData(TYVString *string){
    return string->_data;
}

uint8_t TYVStringGetLength(TYVString *string){
    return string->_length;
}

#pragma mark -
#pragma mark Private Implementations

void TYVStringDealloc(TYVString *string){
    if (NULL != string->_data){
        free(string->_data);
    }
    
    free(string);
}
