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

typedef struct TYVString TYVString;

TYVString *TYVStringCreate(char *data, uint8_t length);

void TYVStringRetain(TYVString *string);

void TYVStringRelease(TYVString *string);

#endif /* defined(__IDAPCoursesHomework__TYVString__) */
