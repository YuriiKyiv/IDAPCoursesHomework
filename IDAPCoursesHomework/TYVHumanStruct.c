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
    TYVHumanStructParents *parents;
    struct TYVHumanStruct *_childrenRef[20];
    
};
typedef struct TYVHumanStruct TYVHumanStruct;

void TYVHumanStructSetAge(TYVHumanStruct *human, int age){
    human->_age = age;
}

int TYVHumanStructGetAge(TYVHumanStruct *human){
    return human->_age;
}

void TYVHumanStructSetChildren(TYVHumanStruct *human, int children){
    human->_children = children;
}

int TYVHumanStructGetChildren(TYVHumanStruct *human){
    return human->_children;
}

void TYVHumanStructSetMarried(TYVHumanStruct *human, bool married){
    human->_married = married;
}

bool TYVHumanStructGetChildren(TYVHumanStruct *human){
    return human->_married;
}