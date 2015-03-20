//
//  TYVRange.h
//  IDAPCoursesHomework
//
//  Created by YURII on 20.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVRange__
#define __IDAPCoursesHomework__TYVRange__

#include <stdio.h>

typedef struct TYVRange TYVRange;
struct TYVRange {
    uint64_t origin;
    uint64_t length;
};

uint64_t TYVRangeGetLastIndex(TYVRange range);

#endif /* defined(__IDAPCoursesHomework__TYVRange__) */
