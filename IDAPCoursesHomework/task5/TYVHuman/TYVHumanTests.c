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
    TYVHumanCreateTest();
    TYVHumanGetMarriedAndDivorceTest();
    TYVHumanAutoreleasingGetterTest();
}

void TYVHumanAutoreleasingGetterTest() {
    printf("HUMAN AUTORELEASE TEST\n");
    TYVAutoreleasePool *pool = TYVAutoreleasePoolCreate();
    
    char nameOne[] = "Vasya Pupkin";
    TYVString *stringOne = TYVStringCreate(nameOne);
    TYVHuman *humanMale = TYVHumanCreate(stringOne, 11, TYVMale);
    TYVAutoreleasePoolAddObject(pool, (TYVObject *)stringOne);
    TYVAutoreleasePoolAddObject(pool, (TYVObject *)humanMale);
    
    char nameTwo[] = "Masha Dasha";
    TYVString *stringTwo = TYVStringCreate(nameTwo);
    TYVHuman *humanFemale = TYVHumanCreate(stringTwo, 9, TYVFemale);
    TYVAutoreleasePoolAddObject(pool, (TYVObject *)stringTwo);
    TYVAutoreleasePoolAddObject(pool, (TYVObject *)humanFemale);
    
    TYVHumanGetMarried(humanMale, humanFemale);
    TYVHuman *partner = TYVHumanGetPartner(humanMale);
    assert(partner == humanFemale);
    
    TYVAutoreleasePoolDrain(pool);
}

void TYVHumanCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 11, TYVMale);
    TYVHumanNameOutput(human);
    assert(11 == TYVHumanGetAge(human));
    
    TYVObjectRelease(human);
    TYVObjectRelease(string);
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
    
    TYVObjectRelease(human);
    TYVObjectRelease(string);
    TYVObjectRelease(partnerString);
    TYVObjectRelease(partnerHuman);
}
