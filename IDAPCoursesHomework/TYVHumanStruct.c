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

TYVHuman *TYVHumanCreate(){
    TYVHuman *human = malloc(sizeof(*human));
    human->_partner = NULL;
    human->_referenceCount = 1;
    
    return human;
}

void TYVHumanRetain(TYVHuman *human){
    human->_referenceCount++;
}

void TYVHumanRelease(TYVHuman *human){
    human->_referenceCount--;
//    if ( 0 == human->_referenceCount);
//    DEALLOC
}

void TYVHumanDealloc(TYVHuman *human){
//    if ((NULL != human->_parents) && NULL != (human->_partner))
//        Call the dealloc method for parents and parther stucts
    free(human);
}

void TYVHumanSetAge(TYVHuman *human, int age){
    human->_age = age;
}

int TYVHumanGetAge(TYVHuman *human){
    return human->_age;
}

void TYVHumanSetChildren(TYVHuman *human, int children){
    human->_children = children;
}

int TYVHumanGetChildren(TYVHuman *human){
    return human->_children;
}

void TYVHumanSetMarried(TYVHuman *human, bool married){
    human->_married = married;
}

bool TYVHumanGetMarried(TYVHuman *human){
    return human->_married;
}