//
//  TYVPropertySetters.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVPropertySetters__
#define __IDAPCoursesHomework__TYVPropertySetters__

#define TYVPropertySetRetainVoid(field, value) \
    TYVPropertySetRetain((void **) #field, #value);

#define TYVPropertySetAssignVoid(field, value) \
TYVPropertySetAssign((void **) field, value);

#include <stdio.h>

void TYVPropertySetRetain(void **field, void *value);

void TYVPropertySetAssign(void **field, void *value);

#endif /* defined(__IDAPCoursesHomework__TYVPropertySetters__) */
