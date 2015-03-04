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
void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);

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

#pragma mark -
#pragma mark Public Implementations

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender){
    TYVHuman *human = TYVObjectCreate(TYVHuman);
    TYVHumanSetName(human, string);
    TYVHumanSetGender(human, gender);
    TYVHumanSetAge(human, age);
    
    return human;
}

void TYVHumanSetAge(TYVHuman *human, uint8_t age){
    human->_age = age;
}

uint8_t TYVHumanGetAge(TYVHuman *human){
    return human->_age;
}

void TYVHumanGetMarried(TYVHuman *male, TYVHuman *female){
    if (NULL == male || NULL == female){
        return;
    }
    
    TYVHumanSetPartner(male,female);
    TYVHumanSetPartner(female, male);
}

void TYVHumanDivorce(TYVHuman *human){
    TYVHumanSetPartner(human, NULL);
    TYVHumanSetPartner(TYVHumanGetPartner(human), NULL);
}

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name){
    // TODO: Add condition of childrenCount
    TYVHuman *child = NULL;
    if (NULL != human && NULL != TYVHumanGetPartner(human)) {
        child = TYVHumanCreate(name, 0, TYVMale);
        if (TYVHumanGetGender(human) == TYVMale){
            TYVHumanConnectWithParents(child, human);
        } else {
            TYVHumanConnectWithParents(child, TYVHumanGetPartner(human));
        }
    }
    
    return child;
}

void TYVHumanSetName(TYVHuman *human, TYVString *string){
    if (NULL == human || human->_name == string){
        return;
    }
    
    if (NULL != human->_name){
        TYVObjectRelease(human->_name);
    }
    
    if (NULL != string){
        TYVObjectRetain(string);
    }
    
    human->_name = string;
}

TYVString *TYVHumanGetName(TYVHuman *human){
    TYVString *string = NULL;
    if (NULL != human){
        string = human->_name;
    }
    
    return string;
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
    return human->_gender;
}

TYVHuman *TYVHumanGetMother(TYVHuman *human){
    return human->_mother;
}

TYVHuman *TYVHumanGetFather(TYVHuman *human){
    return human->_father;
}

TYVHuman *TYVHumanGetPartner(TYVHuman *human){
    return human->_partner;
}

TYVArray *TYVHumanGetArray(TYVHuman *human){
    return human->childrenArray;
}


void __TYVHumanDeallocate(TYVHuman *human){
    // TODO: add children information
    
    TYVHumanSetName(human, NULL);
    TYVHumanSetPartner(human, NULL);
    TYVHumanSetFather(human, NULL);
    TYVHumanSetMother(human, NULL);
    
    __TYVObjectDeallocate(human);
}

#pragma mark -
#pragma mark Private Implementations

void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
    if ( NULL == human || human == partner){
        return;
    }
    
    if (NULL != TYVHumanGetPartner(human)){
        TYVObjectRelease(human->_partner);
    }
    
    if (NULL != partner){
        TYVObjectRetain(partner);
    }
    
    human->_partner = partner;
}

void TYVHumanConnectWithParents(TYVHuman *child, TYVHuman *human){
    // TODO: add cheaking for NULL - parent partner child
    TYVHumanAddChild(human, child);
    TYVHumanAddChild(TYVHumanGetPartner(human), child);
}

void TYVHumanAddChild(TYVHuman *human, TYVHuman *child){
    if (NULL == human){
        return;
    }
    
    if (NULL == human->childrenArray){
        TYVArray *array = __TYVObjectCreate(sizeof(TYVArray), (TYVDeallocateCallback)&__TYVArrayDeallocate);
        TYVHumanSetArray(human, array);
    }
    
    TYVArrayAdd(TYVHumanGetArray(human), child);
}

//void TYVHumanRemoveChild(TYVHuman *human, TYVHuman *child){
//    
//}

void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother){
    if (NULL != TYVHumanGetMother(human)){

        TYVObjectRelease(human->_mother);
    }
    
    if (NULL != mother) {
        TYVObjectRetain(mother);
    }
    
    human->_mother = mother;
}

void TYVHumanSetFather(TYVHuman *human, TYVHuman *father){
    if (NULL != TYVHumanGetFather(human)){
        TYVObjectRelease(human->_father);
    }
    
    if (NULL != father) {
        TYVObjectRetain(father);
    }
    
    human->_father = father;
}

void TYVHumanSetArray(TYVHuman *human, TYVArray *array){
    TYVObjectRetain(array);
    human->childrenArray = array;
}
