//
//  TYVHumanTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <assert.h>

#include "TYVHumanTests.h"
#include "TYVHuman.h"
#include "TYVString.h"
#include "TYVObject.h"
#include "TYVAutoreleasePool.h"

static
void TYVHumanCreateTest();

static
void TYVHumanGetMarriedAndDivorceTest();

static
void TYVHumanAutoreleasingGetterTest();

void TYVHumanTests(){
    printf("HUMAN TESTS\n");
    
    TYVAutoreleasePool *pool = TYVAutoreleasePoolCreate();
    
    TYVHumanCreateTest();
    TYVHumanGetMarriedAndDivorceTest();
    TYVHumanAutoreleasingGetterTest();
    
    TYVAutoreleasePoolDrain(pool);
}

void TYVHumanAutoreleasingGetterTest() {
    printf("HUMAN AUTORELEASE TEST\n");
    
    char nameOne[] = "Vasya Pupkin";
    TYVString *stringOne = TYVStringCreate(nameOne);
    TYVHuman *humanMale = TYVHumanCreate(stringOne, 11, TYVMale);
    TYVObjectAutorelease(stringOne);
    TYVObjectAutorelease(humanMale);
    
    char nameTwo[] = "Masha Dasha";
    TYVString *stringTwo = TYVStringCreate(nameTwo);
    TYVHuman *humanFemale = TYVHumanCreate(stringTwo, 9, TYVFemale);
    TYVObjectAutorelease(stringTwo);
    TYVObjectAutorelease(humanFemale);
    
    TYVHumanGetMarried(humanMale, humanFemale);
    TYVHuman *partner = TYVHumanGetPartner(humanMale);
    assert(partner == humanFemale);
    partner = TYVHumanGetPartner(humanFemale);
    assert(partner == humanMale);
}

void TYVHumanCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 11, TYVMale);
    TYVHumanNameOutput(human);
    assert(11 == TYVHumanGetAge(human));
    
    TYVObjectAutorelease(string);
    TYVObjectAutorelease(human);
}

void TYVHumanGetMarriedAndDivorceTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    
    char partnerName[] = "Masha";
    TYVString *partnerString = TYVStringCreate(partnerName);
    TYVHuman *partnerHuman = TYVHumanCreate(partnerString, 100, TYVFemale);
    
    TYVHumanGetMarried(human, partnerHuman);
    assert(TYVHumanIsMarried(human));
    assert(NULL != TYVHumanGetPartner(human));
    assert(TYVHumanGetPartner(human) == partnerHuman);
    
    assert(TYVHumanIsMarried(partnerHuman));
    assert(NULL != TYVHumanGetPartner(partnerHuman));
    assert(TYVHumanGetPartner(partnerHuman) == human);
    
    TYVHumanDivorce(human);
    assert(NULL == TYVHumanGetPartner(human));
    assert(NULL == TYVHumanGetPartner(partnerHuman));
    
    TYVObjectAutorelease(human);
    TYVObjectAutorelease(string);
    TYVObjectAutorelease(partnerString);
    TYVObjectAutorelease(partnerHuman);
}
