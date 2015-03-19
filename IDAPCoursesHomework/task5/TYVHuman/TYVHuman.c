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
#include "TYVUniversalSetters.h"
#include "TYVPropertySetters.h"

const static uint8_t TYVNotFoundObject = 255;

#pragma mark -
#pragma mark Private Declarations

static
void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human);

static
void TYVHumanAddChild(TYVHuman *human, TYVHuman *child);

//static
//void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child);

static
void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother);

static
void TYVHumanSetFather(TYVHuman *human, TYVHuman *mother);

static
void TYVHumanSetArray(TYVHuman *human, TYVArray *array);

static
void TYVHumanSetAge(TYVHuman *human, uint8_t age);

static
void TYVHumanSetParents(TYVHuman *child, TYVHuman *parent);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender){
    TYVHuman *human = TYVObjectCreate(TYVHuman);
    TYVHumanSetName(human, string);
    TYVHumanSetGender(human, gender);
    TYVHumanSetAge(human, age);
    
    TYVArray *array = TYVObjectCreate(TYVArray);
    TYVHumanSetArray(human, array);
    
    TYVObjectRelease(array);
    
    return human;
}

void TYVHumanSetAge(TYVHuman *human, uint8_t age){
    if (NULL == human){
        return;
    }
    
    human->_age = age;
}

uint8_t TYVHumanGetAge(TYVHuman *human){
    return (NULL != human) ? human->_age : 0;
}

void TYVHumanGetMarried(TYVHuman *male, TYVHuman *female){
    if (NULL == male || NULL == female || male == female){
        return;
    }
    
    TYVHumanDivorce(male);
    TYVHumanDivorce(female);
    
    TYVHumanSetPartner(male, female);
    TYVHumanSetPartner(female, male);
}

bool TYVHumanIsMarried(TYVHuman *human){
    return (NULL != human) ? (NULL != TYVHumanGetPartner(human)) : false;
}

void TYVHumanDivorce(TYVHuman *human){
    if (NULL == human || !TYVHumanIsMarried(human)){
        return;
    }
    
    TYVHumanSetPartner(TYVHumanGetPartner(human), NULL);
    TYVHumanSetPartner(human, NULL);
}

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name, TYVGender gender){
    TYVHuman *humanPartner = TYVHumanGetPartner(human);
    if (NULL == human
        || NULL == name
        || NULL == humanPartner)
    {
        return NULL;
    }
    
    if (TYVHumanGetChildrenCount(human) >= TYVChildrenMaxCount
        || TYVHumanGetChildrenCount(humanPartner) >= TYVChildrenMaxCount)
    {
        return NULL;
    }
    
    TYVHuman *child = TYVHumanCreate(name, 0, gender);
    
    TYVHumanConnectWithParents(child, human);
    
    TYVObjectRelease(child);
    
    return child;
}

void TYVHumanSetName(TYVHuman *human, TYVString *string){
    if (NULL == human || human->_name == string){
        return;
    }

    TYVUniversalSetRetain((void **)&human->_name, string);
}

TYVString *TYVHumanGetName(TYVHuman *human){
    return (NULL != human) ? human->_name : NULL;
}

void TYVHumanNameOutput(TYVHuman *human){
    if (NULL == human){
        return;
    }
    
    TYVString *string = TYVHumanGetName(human);
    printf("%s\n", TYVStringGetData(string));
}
            
void TYVHumanSetGender(TYVHuman *human, TYVGender gender){
    if (NULL == human) {
        return;
    }
    
    human->_gender = gender;
}

TYVGender TYVHumanGetGender(TYVHuman *human){
    return (NULL != human) ? human->_gender : TYVMale;
}

TYVHuman *TYVHumanGetMother(TYVHuman *human){
    return (NULL != human) ? human->_mother : NULL;
}

TYVHuman *TYVHumanGetFather(TYVHuman *human){
    return (NULL != human) ? human->_father : NULL;
}

TYVHuman *TYVHumanGetPartner(TYVHuman *human){
    return (NULL != human) ? human->_partner : NULL;
}

TYVArray *TYVHumanGetArray(TYVHuman *human){
    return (NULL != human) ? human->_childrenArray : NULL;
}

uint8_t TYVHumanGetChildrenCount(TYVHuman *human){
    return (NULL != human) ? human->_childrenCount : TYVNotFoundObject;
}


void __TYVHumanDeallocate(TYVHuman *human){
    // TODO: add children information
    
    TYVHumanSetName(human, NULL);
    TYVHumanSetPartner(human, NULL);
    TYVHumanSetFather(human, NULL);
    TYVHumanSetMother(human, NULL);
    TYVHumanSetArray(human, NULL);
    
    __TYVObjectDeallocate(human);
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    if (TYVHumanGetGender(human) == TYVMale){
        TYVPropSetRetain(&human->_partner, partner);
    } else {
        TYVPropSetAssign(&human->_partner, partner);
    }
}

void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human){
    TYVHumanAddChild(human, child);
    TYVHumanAddChild(TYVHumanGetPartner(human), child);
    TYVHumanSetParents(child, human);
    
}

void TYVHumanSetParents(TYVHuman *child, TYVHuman *parent){
    if (NULL == child || NULL == parent){
        return;
    }
    
    if (TYVHumanGetGender(parent) == TYVMale){
        TYVHumanSetFather(child, parent);
        TYVHumanSetMother(child, TYVHumanGetPartner(parent));
    } else {
        TYVHumanSetFather(child, TYVHumanGetPartner(parent));
        TYVHumanSetMother(child, parent);
    }
}

void TYVHumanAddChild(TYVHuman *human, TYVHuman *child){
    if (NULL == human){
        return;
    }
    
    TYVArrayAdd(TYVHumanGetArray(human), child);
}

//void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child){
//    
//}

void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother){
    if ( NULL == human || human == mother){
        return;
    }
    
    TYVUniversalSetRetain((void **)&human->_mother, mother);
}

void TYVHumanSetFather(TYVHuman *human, TYVHuman *father){
    if ( NULL == human || human == father){
        return;
    }
    
    TYVUniversalSetRetain((void **)&human->_father, father);
}

void TYVHumanSetArray(TYVHuman *human, TYVArray *array){
    if (NULL == human || array != human->_childrenArray){
        return;
    }
    
    TYVUniversalSetRetain((void **)&human->_childrenArray, array);
}
