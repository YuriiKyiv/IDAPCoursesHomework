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

struct TYVName {
    char *_name;
    int _lenght;
};
typedef struct TYVName TYVName;

struct TYVHumanStructParents {
    struct TYVHumanStruct *_mather;
    struct TYVHumanStruct *_father;
};
typedef struct TYVHumanStructParents TYVHumanStructParents;

struct TYVHumanStruct {
    TYVName _name;
    int _age;
    int _children;
    bool _married;
    struct TYVHumanStruct *_partner;
    TYVHumanStructParents *_parents;
    struct TYVHumanStruct *_childrenRef[20];
    
    uint64_t _referenceCount;
};
typedef struct TYVHumanStruct TYVHumanStruct;

extern
TYVHumanStruct *TYVHumanStructCreate();

extern
void TYVHumanStructRetain(TYVHumanStruct *human);

extern
void TYVHumanStructRelease(TYVHumanStruct *human);

extern
void TYVHumanStructDealloc(TYVHumanStruct *human);

extern
void TYVHumanStructSetAge(TYVHumanStruct *human, int age);

extern
int TYVHumanStructGetAge(TYVHumanStruct *human);

extern
void TYVHumanStructSetChildren(TYVHumanStruct *human, int children);

extern
int TYVHumanStructGetChildren(TYVHumanStruct *human);

extern
void TYVHumanStructSetMarried(TYVHumanStruct *human, bool married);

extern
bool TYVHumanStructGetMarried(TYVHumanStruct *human);

#endif /* defined(__IDAPCoursesHomework__TYVHumanStruct__) */
