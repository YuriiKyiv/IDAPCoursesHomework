//
//  TYVString.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVString__
#define __IDAPCoursesHomework__TYVString__

#include <stdio.h>
#include "TYVObject.h"

typedef struct TYVString TYVString;
struct TYVString {
    TYVObject _object;
    
    char *_data;
    size_t _length;
};

TYVString *TYVStringCreate(char *data);

char *TYVStringGetData(TYVString *string);

size_t TYVStringGetLength(TYVString *string);

void __TYVStringDeallocate(TYVString *string);

void TYVStringSetData(TYVString *string, char *data);

#endif /* defined(__IDAPCoursesHomework__TYVString__) */
