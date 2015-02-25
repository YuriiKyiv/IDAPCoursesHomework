//
//  TYVString.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVString.h"
#include "stdlib.h"
#include "string.h"

#pragma mark -
#pragma mark Private Declarations

static
void TYVStringDealloc(TYVString *string);

static
char *TYVCharCopy(char *data, size_t length);

#pragma mark -
#pragma mark Public Implementations

TYVString *TYVStringCreate(char *data){
    size_t length  = strlen(data);
    TYVString *string = malloc(sizeof(*string));
    string->_data = TYVCharCopy(data, length);
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

size_t TYVStringGetLength(TYVString *string){
    return string->_length;
}

char *TYVCharCopy(char *data, size_t length){
    char *newData = malloc(sizeof(char) * length);
    memcpy(data, newData, length);
    
    return newData;
}

#pragma mark -
#pragma mark Private Implementations

void TYVStringDealloc(TYVString *string){
    if (NULL != string->_data){
        free(string->_data);
    }
    
    free(string);
}
