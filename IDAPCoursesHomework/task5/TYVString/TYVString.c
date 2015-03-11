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

#pragma mark -
#pragma mark Public Implementations

TYVString *TYVStringCreate(char *data){
    TYVString *string = TYVObjectCreate(TYVString);
    TYVStringSetData(string, data);
    
    return string;
}

void TYVStringSetData(TYVString *string, char *data){
    if (NULL == string){
        return;
    }
    
    if (NULL != string->_data){
        free(string->_data);
        string->_data = NULL;
        string->_length = 0;
    }
    
    if (NULL != data){
        string->_data = strdup(data);
        string->_length = strlen(data) + 1;
    }
}

char *TYVStringGetData(TYVString *string){
    return string->_data;
}

size_t TYVStringGetLength(TYVString *string){
    return string->_length;
}

#pragma mark -
#pragma mark Private Implementations

void __TYVStringDeallocate(TYVString *string){
    TYVStringSetData(string, NULL);
    
    __TYVObjectDeallocate(string);
}
