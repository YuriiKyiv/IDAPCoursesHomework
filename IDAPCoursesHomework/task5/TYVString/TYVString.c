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
void __TYVStringDealloc(TYVString *string);

static
char *TYVCharCopy(char *data, size_t length);

#pragma mark -
#pragma mark Public Implementations

TYVString *TYVStringCreate(char *data){
    size_t length  = strlen(data);
    TYVString *string = calloc(1 ,sizeof(*string));
    string->_data = TYVCharCopy(data, length);
    string->_length = length;
    string->_referenceCount = 1;
    
    return string;
}

void TYVStringSetData(TYVString *string, char *data){
    if (NULL == string || NULL == data){
        return;
    }
    
    if (NULL != string->_data){
        free(string->_data);
    }
    
    size_t length  = strlen(data);
    string->_data = TYVCharCopy(data, length);
    string->_length = length;
}

char *TYVStringGetData(TYVString *string){
    return string->_data;
}

size_t TYVStringGetLength(TYVString *string){
    return string->_length;
}

char *TYVCharCopy(char *data, size_t length){
    char *newData = calloc(length, sizeof(char));
    memcpy(newData, data, length);
    
    return newData;
}

#pragma mark -
#pragma mark Private Implementations

void __TYVStringDeallocate(TYVString *string){
    if (NULL != string->_data){
        free(string->_data);
        string->_data = NULL;
    }
    
    __TYVObjectDeallocate(string);
}
