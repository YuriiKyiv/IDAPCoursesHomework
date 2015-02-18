//
//  TYVHumanStruct.c
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHumanStruct.h"
#include "stdlib.h"

#pragma mark -
#pragma mark Private Declarations

void TYVHumanDealloc(TYVHuman *human);

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVName *name, unsigned int age){
    TYVHuman *human = malloc(sizeof(*human));
    human->_referenceCount = 1;
    TYVNameRetain(name);
    human->_name = name;
    human->_age = age;
    
    return human;
}

void TYVHumanRetain(TYVHuman *human){
    human->_referenceCount++;
}

void TYVHumanRelease(TYVHuman *human){
    human->_referenceCount--;
    if (0 == human->_referenceCount){
        TYVNameRelease(human->_name);
        TYVHumanDealloc(human);
    }
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanDealloc(TYVHuman *human){
    
}