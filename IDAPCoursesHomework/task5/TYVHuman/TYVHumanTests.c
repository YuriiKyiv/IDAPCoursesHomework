//
//  TYVHumanTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHumanTests.h"
#include "TYVHuman.h"
#include "TYVString.h"
#include "assert.h"
#include "TYVObject.h"

static
void TYVHumanCreateTest();

static
void TYVHumanGetMarriedAndDivorceTest();

void TYVHumanTests(){
    printf("HUMAN TESTS\n");
    TYVHumanCreateTest();
    TYVHumanGetMarriedAndDivorceTest();
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
