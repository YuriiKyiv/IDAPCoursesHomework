//
//  TYVRange.c
//  IDAPCoursesHomework
//
//  Created by YURII on 20.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVRange.h"

uint64_t TYVRangeGetLastIndex(TYVRange range){
    return range.origin + range.length;
}