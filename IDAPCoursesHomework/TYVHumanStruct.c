//
//  TYVHumanStruct.c
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHumanStruct.h"
#include "stdbool.h"
#include "stdlib.h"

TYVHumanStruct *TYVHumanStructCreate(){
    TYVHumanStruct *human = malloc(sizeof(*human));
    human->_partner = NULL;
    human->_parents = NULL;
    human->_referenceCount = 1;
    
    return human;
}

void TYVHumanStructRetain(TYVHumanStruct *human){
    human->_referenceCount++;
}

void TYVHumanStructRelease(TYVHumanStruct *human){
    human->_referenceCount--;
//    if ( 0 == human->_referenceCount);
//    DEALLOC
}


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

bool TYVHumanStructGetMarried(TYVHumanStruct *human){
    return human->_married;
}