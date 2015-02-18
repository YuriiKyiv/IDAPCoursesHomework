//
//  TYVName.h
//  IDAPCoursesHomework
//
//  Created by YURII on 18.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVName__
#define __IDAPCoursesHomework__TYVName__

#include <stdio.h>

struct TYVName {
    char *_name;
    uint64_t _length;
    
    uint64_t _referenceCount;
};
typedef struct TYVName TYVName;

#endif /* defined(__IDAPCoursesHomework__TYVName__) */
