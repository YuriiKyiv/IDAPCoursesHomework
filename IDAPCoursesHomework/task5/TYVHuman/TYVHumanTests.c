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

static
void TYVHumanCreateTest();

static
void TYVHumanRetainTest();

static
void TYVHumanGetMarriedTest();

void TYVHumanTests(){
    TYVHumanCreateTest();
    TYVHumanRetainTest();
    TYVHumanGetMarriedTest();
}

void TYVHumanCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHumanCreate(string, 100, TYVMale);
}

void TYVHumanRetainTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    assert(1 == human->_referenceCount);
}

void TYVHumanReleaseTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    TYVHumanRelease(human);
    TYVHumanRetain(human);
    assert(1 == human->_referenceCount);
}

void TYVHumanGetMarriedTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    
    char partnerName[] = "Mother test";
    TYVString *partnerString = TYVStringCreate(partnerName);
    TYVHuman *partnerHuman = TYVHumanCreate(partnerString, 100, TYVMale);
    
    TYVHumanGetMarried(human, partnerHuman);
    printf("%s", TYVHumanGetPartner(human)->_name->_data);
}
