//
//  TYVHumanStruct.c
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHumanStruct.h"
#include "stdbool.h"



struct TYVName {
    char *name;
    int lenght;
};
typedef struct TYVName TYVName;

struct TYVHumanStruct {
    TYVName name;
    int age;
    int children;
    bool married;
    struct TYVHumanStruct *partner;
    struct TYVHumanStruct *mather;
    struct TYVHumanStruct *father;
    struct TYVHumanStruct *childrenRef[20];
    
};
typedef struct TYVHumanStruct TYVHumanStruct;