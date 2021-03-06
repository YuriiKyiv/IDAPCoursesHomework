//
//  TYVHuman.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdlib.h>

#include "TYVHuman.h"
#include "TYVString.h"
#include "TYVPropertySetters.h"
#include "TYVAutoreleasePool.h"

#pragma mark -
#pragma mark Private Declarations

static
void TYVHumanAddChild(TYVHuman *human, TYVHuman *child);

static
void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child);

static
void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother);

static
void TYVHumanSetFather(TYVHuman *human, TYVHuman *mother);

static
void TYVHumanSetArray(TYVHuman *human, TYVArrayList *array);

static
void TYVHumanSetAge(TYVHuman *human, uint8_t age);

static
void TYVHumanSetParent(TYVHuman *child, TYVHuman *parent);

static
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

static
void TYVHumanRemoveAllChildren(TYVHuman *human);

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender) {
    if (NULL == string) {
        return NULL;
    }
    
    TYVHuman *human = TYVObjectCreate(TYVHuman);
    TYVHumanSetName(human, string);
    TYVHumanSetGender(human, gender);
    TYVHumanSetAge(human, age);
    
    TYVArrayList *array = (TYVArrayList *)TYVObjectAutorelease(TYVArrayListCreateWithSize(2));
    
    TYVHumanSetArray(human, array);
    
    return human;
}

void TYVHumanSetAge(TYVHuman *human, uint8_t age) {
    if (NULL == human){
        return;
    }
    
    human->_age = age;
}

uint8_t TYVHumanGetAge(TYVHuman *human) {
    return (NULL != human) ? human->_age : 0;
}

void TYVHumanGetMarried(TYVHuman *male, TYVHuman *female) {
    if (NULL == male || NULL == female || male == female) {
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
    if (NULL == human || !TYVHumanIsMarried(human)) {
        return;
    }
    
    TYVHumanSetPartner(TYVHumanGetPartner(human), NULL);
    TYVHumanSetPartner(human, NULL);
}

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name, TYVGender gender) {
    if (NULL == human
        || NULL == name
        || NULL == TYVHumanGetPartner(human))
    {
        return NULL;
    }
    
    TYVHuman *child = (TYVHuman *)TYVObjectAutorelease(TYVHumanCreate(name, 0, gender));
    
    TYVHumanAddChild(human, child);
    TYVHumanAddChild(TYVHumanGetPartner(human), child);
    
    return child;
}

void TYVHumanSetName(TYVHuman *human, TYVString *string) {
    if (NULL == human || human->_name == string){
        return;
    }

    TYVPropertySetRetain(&human->_name, string);
}

TYVString *TYVHumanGetName(TYVHuman *human) {
    return (NULL != human) ? TYVAutoreleasingGetter(&human->_name) : NULL;
}

void TYVHumanNameOutput(TYVHuman *human) {
    if (NULL == human){
        return;
    }
    
    TYVString *string = TYVHumanGetName(human);
    printf("%s\n", TYVStringGetData(string));
}
            
void TYVHumanSetGender(TYVHuman *human, TYVGender gender) {
    if (NULL == human) {
        return;
    }
    
    human->_gender = gender;
}

TYVGender TYVHumanGetGender(TYVHuman *human) {
    return (NULL != human) ? human->_gender : TYVMale;
}

TYVHuman *TYVHumanGetMother(TYVHuman *human) {
    return (NULL != human) ? TYVAutoreleasingGetter(&human->_mother) : NULL;
}

TYVHuman *TYVHumanGetFather(TYVHuman *human) {
    return (NULL != human) ? TYVAutoreleasingGetter(&human->_father) : NULL;
}

TYVHuman *TYVHumanGetPartner(TYVHuman *human) {
    return (NULL != human) ? TYVAutoreleasingGetter(&human->_partner) : NULL;
}

TYVArrayList *TYVHumanGetArray(TYVHuman *human) {
    return (NULL != human) ? TYVAutoreleasingGetter(&human->_childrenArray) : NULL;
}

uint64_t TYVHumanGetChildrenCount(TYVHuman *human) {
    return (NULL != human) ? TYVArrayListGetCount(TYVHumanGetArray(human)) : 0;
}


void __TYVHumanDeallocate(TYVHuman *human){
    TYVHumanSetName(human, NULL);
    TYVHumanDivorce(human);
    TYVHumanRemoveChild(TYVHumanGetFather(human), human);
    TYVHumanRemoveChild(TYVHumanGetMother(human), human);
    TYVHumanSetFather(human, NULL);
    TYVHumanSetMother(human, NULL);
    TYVHumanRemoveAllChildren(human);
    TYVHumanSetArray(human, NULL);
    
    __TYVObjectDeallocate(human);
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner) {
    if (TYVHumanGetGender(human) == TYVMale) {
        TYVPropertySetRetain(&human->_partner, partner);
    } else {
        TYVPropertySetAssign(&human->_partner, partner);
    }
}

void TYVHumanSetParent(TYVHuman *child, TYVHuman *parent) {
    if (NULL == child || NULL == parent) {
        return;
    }
    
    if (TYVHumanGetGender(parent) == TYVMale) {
        TYVHumanSetFather(child, parent);
    } else {
        TYVHumanSetMother(child, parent);
    }
}

void TYVHumanAddChild(TYVHuman *human, TYVHuman *child) {
    if (NULL == human || NULL == child){
        return;
    }
    
    TYVHumanSetParent(child, human);
    
    TYVArrayList *array = TYVHumanGetArray(human);
    if (!TYVArrayListContainsItem(array, (TYVObject *)child)) {
        TYVArrayListAddItem(TYVHumanGetArray(human), (TYVObject *)child);
    }
}

void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child) {
    if (NULL == human || NULL == child){
        return;
    }
    
    TYVArrayList *array = TYVHumanGetArray(human);
    
    if (NULL == array || !TYVArrayListContainsItem(array, (TYVObject *)child)){
        return;
    }
    
    if (TYVMale == TYVHumanGetGender(human)){
        TYVHumanSetFather(child, NULL);
    } else {
        TYVHumanSetMother(child, NULL);
    }
    
    TYVArrayListRemoveItem(TYVHumanGetArray(human), (TYVObject *)child);
}

void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother) {
    if ( NULL == human || human == mother){
        return;
    }
    
    TYVPropertySetAssign(&human->_mother, mother);
}

void TYVHumanSetFather(TYVHuman *human, TYVHuman *father) {
    if ( NULL == human || human == father){
        return;
    }
    
    TYVPropertySetAssign(&human->_father, father);
}

void TYVHumanSetArray(TYVHuman *human, TYVArrayList *array) {
    if (NULL == human || array != human->_childrenArray){
        return;
    }
    
    TYVPropertySetRetain(&human->_childrenArray, array);
}

void TYVHumanRemoveAllChildren(TYVHuman *human) {
    if (NULL == human || TYVHumanGetArray(human)) {
        return;
    }
    
    TYVArrayList *array = TYVHumanGetArray(human);
    uint64_t count = TYVArrayListGetCount(array);
    for (uint64_t iter = count; iter > 0; iter--) {
        TYVHumanRemoveChild(human, (TYVHuman *)TYVArrayListGetItemAtIndex(array, iter - 1));
    }
}
