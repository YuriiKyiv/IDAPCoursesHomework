//
//  TYVPropertySetters.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVPropertySetters__
#define __IDAPCoursesHomework__TYVPropertySetters__

#include <stdio.h>

extern
void TYVPropertySetRetain(void **field, void *value);

#define TYVPropertySetRetain(field, value) \
    TYVPropertySetRetain((void **)field, value)

extern
void TYVPropertySetAssign(void **field, void *value);

#define TYVPropertySetAssign(field, value) \
    TYVPropertySetAssign((void **)field, value)

extern
void *TYVAutoreleasingGetter(void **field);

#define TYVAutoreleasingGetter(field) \
    TYVAutoreleasingGetter((void **)field)

#endif /* defined(__IDAPCoursesHomework__TYVPropertySetters__) */
