//
//  TYVHuman.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVHuman__
#define __IDAPCoursesHomework__TYVHuman__

#include <stdio.h>
#include "TYVString.h"

typedef struct TYVHuman TYVHuman;

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender);

void TYVHumanRetain(TYVHuman *string);

void TYVHumanRelease(TYVHuman *string);

#endif /* defined(__IDAPCoursesHomework__TYVHuman__) */