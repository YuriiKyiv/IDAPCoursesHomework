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

static
void TYVHumanDealloc(TYVHuman *human);

static
void TYVHumanSetMerriedStatus(TYVHuman *human);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVName *name, unsigned int age, TYVGender gender){
    TYVHuman *human = malloc(sizeof(*human));
    human->_referenceCount = 1;   
    TYVNameRetain(name);
    human->_name = name;
    human->_age = age;
    human->_gender = gender;
    
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

TYVName *TYVHumanGetName(TYVHuman *human){
    return human->_name;
}

unsigned int TYVHumanGetAge(TYVHuman *human){
    return human->_age;
}

void TYVHumanSetAge(TYVHuman *human, unsigned int age){
    human->_age = age;
}

TYVGender TYVHumanGetGender(TYVHuman *human){
    return human->_gender;
}

TYVMarried TYVHumanGetMerriedStatus(TYVHuman *human){
    return human->_married;
}

void TYVHunamGetMarried(TYVHuman *male, TYVHuman *female){
    if ((TYVHumanGetGender(male) != TYVHumanGetGender(female)) &&
        (TYVHumanGetMerriedStatus(male) == TYVHumanGetMerriedStatus(female)) == no ) {
        TYVHumanRetain(male);
        TYVHumanRetain(female);
        TYVHumanSetPartner(male,female);
        TYVHumanSetPartner(female,male);
    }
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanDealloc(TYVHuman *human){
    free(human);
}

void TYVHumanSetMerriedStatus(TYVHuman *human){
    human->_married = yes;
}

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    human->_partner = partner;
}