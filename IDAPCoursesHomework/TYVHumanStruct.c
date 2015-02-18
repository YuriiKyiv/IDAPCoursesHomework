//
//  TYVHumanStruct.c
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHumanStruct.h"
#include "stdlib.h"
#include "stdbool.h"

#pragma mark -
#pragma mark Private Declarations

static
void TYVHumanDealloc(TYVHuman *human);

static
void TYVHumanSetMerriedStatus(TYVHuman *human, TYVMarried status);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

static
void TYVHumanSetMother(TYVHuman *human, TYVHuman *mather);

static
void TYVHumanSetFather(TYVHuman *human, TYVHuman *father);

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

TYVHuman *TYVHumanGetPartner(TYVHuman *human){
    return human->_partner;
}

void TYVHunamGetMarried(TYVHuman *male, TYVHuman *female){
    if ((TYVHumanGetGender(male) != TYVHumanGetGender(female)) &&
        (TYVHumanGetMerriedStatus(male) == TYVHumanGetMerriedStatus(female)) == no ) {
        TYVHumanRetain(male);
        TYVHumanRetain(female);
        TYVHumanSetPartner(male, female);
        TYVHumanSetPartner(female, male);
        TYVHumanSetMerriedStatus(male, yes);
        TYVHumanSetMerriedStatus(female, yes);
    }
}

bool TYVHumanIsSamePartners(TYVHuman *male, TYVHuman *female){
    TYVHuman *malePartner = TYVHumanGetPartner(male);
    TYVHuman *femalePartner = TYVHumanGetPartner(female);
    if ((malePartner == female) && (femalePartner == male)) {
        return 1;
    } else {
        return 0;
    }
}

bool TYVHumanIsDifferentGender(TYVHuman *male, TYVHuman *female){
    return (TYVHumanGetGender(male) != TYVHumanGetGender(female));
}

void TYVHumanDivorce(TYVHuman *male, TYVHuman *female){
    if (TYVHumanIsSamePartners(male, female)) {
        TYVHumanSetPartner(male, NULL);
        TYVHumanSetPartner(female, NULL);
        TYVHumanSetMerriedStatus(male, no);
        TYVHumanSetMerriedStatus(female, no);
        TYVHumanRelease(male);
        TYVHumanRelease(female);
    }
}

TYVHuman *TYVHumanMakeChildren(TYVHuman *male, TYVHuman *female, TYVName *name, unsigned int age, TYVGender gender){
    TYVHuman *human = NULL;
    if (TYVHumanIsSamePartners(male, female) && TYVHumanIsDifferentGender(male, female)) {
        TYVHuman *human = TYVHumanCreate(name, age, gender);
        if (TYVmale == TYVHumanGetGender(male)) {
            TYVHumanSetMother(human, female);
            TYVHumanSetFather(human, male);
        } else {
            TYVHumanSetMother(human, male);
            TYVHumanSetFather(human, female);
        }
        
        TYVHumanRetain(male);
        TYVHumanRetain(male);
    }
    
    return human;
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanDealloc(TYVHuman *human){
    if (NULL != human->_name){
        TYVNameRelease(human->_name);
    }
    
    if (yes == TYVHumanGetMerriedStatus(human)){
        TYVHuman *partner = TYVHumanGetPartner(human);
        TYVHumanSetPartner(partner, NULL);
        TYVHumanSetMerriedStatus(partner, no);
        TYVHumanRelease(partner);
    }
    free(human);
}

void TYVHumanSetMerriedStatus(TYVHuman *human, TYVMarried status){
    human->_married = status;
}

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    human->_partner = partner;
}

void TYVHumanSetMother(TYVHuman *human, TYVHuman *mather){
    human->_mather = mather;
}

void TYVHumanSetFather(TYVHuman *human, TYVHuman *father){
    human->_father = father;
}