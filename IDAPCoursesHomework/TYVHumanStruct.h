//
//  TYVHumanStruct.h
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVHumanStruct__
#define __IDAPCoursesHomework__TYVHumanStruct__

#include <stdio.h>
#include "stdbool.h"
#include "TYVName.h"

typedef struct TYVHuman TYVHuman;
struct TYVHuman {
    TYVName _name;
    int _age;
    int _children;
    bool _married;
    TYVHuman *_partner;
    TYVHuman *_childrenRef[20];
    
    uint64_t _referenceCount;
};

extern
TYVHuman *TYVHumanStructCreate();

extern
void TYVHumanRetain(TYVHuman *human);

extern
void TYVHumanRelease(TYVHuman *human);

extern
void TYVHumanDealloc(TYVHuman *human);

extern
void TYVHumanSetAge(TYVHuman *human, int age);

extern
int TYVHumanGetAge(TYVHuman *human);

extern
void TYVHumanSetChildren(TYVHuman *human, int children);

extern
int TYVHumanGetChildren(TYVHuman *human);

extern
void TYVHumanSetMarried(TYVHuman *human, bool married);

extern
bool TYVHumanGetMarried(TYVHuman *human);

#endif /* defined(__IDAPCoursesHomework__TYVHumanStruct__) */
