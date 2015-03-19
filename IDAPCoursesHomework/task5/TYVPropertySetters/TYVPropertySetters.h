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

void TYVPropertySetRetain(void **field, void *value);

#define TYVPropSetRetain(field, value) \
TYVPropertySetRetain((void **)field, value);

void TYVPropertySetAssign(void **field, void *value);

#define TYVPropSetAssign(field, value) \
TYVPropertySetAssign((void **)field, value);

#endif /* defined(__IDAPCoursesHomework__TYVPropertySetters__) */
