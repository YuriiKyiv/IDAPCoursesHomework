//
//  TYVHuman.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHuman.h"
#include "TYVString.h"
#include "stdlib.h"

#pragma mark -
#pragma mark Private Declarations

static
void TYVHumanDealloc(TYVHuman *);

static
void TYVHumanDeletePartner(TYVHuman *human);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

static
void TYVHumanDeletePartner(TYVHuman *human);

static
void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human);

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender){
    TYVHuman *human = malloc(sizeof(*human));
    human->_referenceCount = 1;
    TYVStringRetain(string);
    human->_name = string;
    human->_age = age;
    human->_gender = gender;
    human->_childrenCount = 0;
    human->_partner = NULL;
    human->_father = NULL;
    human->_mother = NULL;
    
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

void TYVHumanGetMarried(TYVHuman *male, TYVHuman *female){
        TYVHumanSetPartner(male,female);
        TYVHumanSetPartner(female, male);
}

void TYVHumanDivorce(TYVHuman *human){
    TYVHumanSetPartner(human, NULL);
    TYVHumanSetPartner(human->_partner, NULL);
}

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name){
    // TODO: Add condition of childrenCount
    TYVHuman *child = NULL;
    if (NULL != human && NULL != human->_partner) {
        child = TYVHumanCreate(name, 0, TYVMale);
        if (TYVHumanGetGender(human) == TYVMale){
            TYVHumanConnectWithParents(child, human);
        } else {
            TYVHumanConnectWithParents(child, human->_partner);
        }
    }
    
    return child;
}
            
TYVGender TYVHumanGetGender(TYVHuman *human){
    return human->_gender;
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanDealloc(TYVHuman *human){
    // TODO: add children information
    if (NULL != human->_name) {
        TYVStringRelease(human->_name);
    }
    
    if (NULL != human->_partner){
        TYVHumanRelease(human->_partner);
    }
    
    if (NULL != human->_father) {
        TYVHumanRelease(human->_father);
    }
    
    if (NULL != human->_mother) {
        TYVHumanRelease(human->_mother);
    }
    
    free(human);
}

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    if (NULL == human){
        return;
    }
    
    if (NULL == human->_partner){
        if (NULL == partner){
            return;
        } else {
            TYVHumanRetain(partner);
            human->_partner = partner;
        }
        
    } else {
        if (NULL != partner){
            TYVHumanRetain(partner);
        }
        
        TYVHumanRelease(human->_partner);
        human->_partner = partner;
    }
}

void TYVHumanDeletePartner(TYVHuman *human){
    if (NULL != human
        && NULL != human->_partner) {
        TYVHumanRelease(human->_partner);
        human->_partner = NULL;
    }
}

void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human){
    child->_father = human;
    TYVHumanRetain(human);
    child->_mother = human->_partner;
    TYVHumanRetain(human->_partner);
    TYVHumanRetain(human);
    TYVHumanRetain(human->_partner);
    human->_children[human->_childrenCount] = child;
    human->_partner->_children[human->_partner->_childrenCount] = child;
    TYVHumanRetain(child);
    TYVHumanRetain(child);
    human->_childrenCount++;
    human->_partner->_childrenCount++;
}