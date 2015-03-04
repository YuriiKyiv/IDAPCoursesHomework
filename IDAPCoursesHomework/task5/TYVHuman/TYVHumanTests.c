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
void TYVHumanGetMarriedTest();

void TYVHumanTests(){
    //TYVHumanCreateTest();
    TYVHumanGetMarriedTest();
}

void TYVHumanCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 11, TYVMale);
    TYVHumanNameOutput(human);
    printf("%d\n", TYVHumanGetAge(human));
}

void TYVHumanGetMarriedTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    
    char partnerName[] = "Masha";
    TYVString *partnerString = TYVStringCreate(partnerName);
    TYVHuman *partnerHuman = TYVHumanCreate(partnerString, 100, TYVMale);
    
    TYVHumanGetMarried(human, partnerHuman);
    
    TYVHumanGetMarried(human, NULL);
    assert(NULL == TYVHumanGetPartner(human));
}
