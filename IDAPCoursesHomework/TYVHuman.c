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

#define TYVReleaseFieldGeneratorByClass(class, field) \
    if (NULL != human->_##field){ \
        TYV##class##Release(human->_##field); \
    }

#pragma mark -
#pragma mark Private Declarations

static
void TYVHumanDealloc(TYVHuman *);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

static
void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human);

static
void TYVHumanAddChild(TYVHuman *human, TYVHuman *child);

static
void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child);

static
void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother);

static
void TYVHumanSetFather(TYVHuman *human, TYVHuman *mother);

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
    
    TYVReleaseFieldGeneratorByClass(String, name);
    TYVReleaseFieldGeneratorByClass(Human, partner);
    TYVReleaseFieldGeneratorByClass(Human, father);
    TYVReleaseFieldGeneratorByClass(Human, mother);
  
    free(human);
}

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    if (human != partner){
        if (NULL != human->_partner){
            TYVHumanRelease(human->_partner);
            human->_partner = partner;
        }
        
        if (NULL != partner){
            TYVHumanRetain(partner);
        }
    }
}

void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human){
    // TODO: add cheaking for NULL - parent partner child
    TYVHumanAddChild(human, child);
    TYVHumanAddChild(human->_partner, child);
}

void TYVHumanAddChild(TYVHuman *human, TYVHuman *child){
    if (TYVMale == human->_gender){
        child->_father = human;
    } else {
        child->_mother = human;
    }
    
    TYVHumanRetain(child);
    TYVHumanRetain(human);
    human->_children[human->_childrenCount] = child;
    human->_childrenCount++;
}

void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child){
    
}

void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother){
    if (NULL !=human->_mother){
        TYVHumanRelease(human->_mother);
    }
    
    TYVHumanRetain(mother);
    human->_mother = mother;
}

void TYVHumanSetFather(TYVHuman *human, TYVHuman *father){
    if (NULL !=human->_father){
        TYVHumanRelease(human->_father);
    }
    
    TYVHumanRetain(father);
    human->_father = father;
}
