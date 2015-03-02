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
    TYVHumanCreateTest();
    TYVHumanGetMarriedTest();
}

void TYVHumanCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVHuman *human = __TYVObjectCreate(sizeof(TYVHuman), (TYVDeallocateCallback)&__TYVHumanDeallocate);
    TYVHumanSetGender(human, TYVMale);
    TYVString *string = TYVStringCreate(name);
}

void TYVHumanGetMarriedTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    TYVHuman *human = TYVHumanCreate(string, 100, TYVMale);
    
    char partnerName[] = "Mother test";
    TYVString *partnerString = TYVStringCreate(partnerName);
    TYVHuman *partnerHuman = TYVHumanCreate(partnerString, 100, TYVMale);
    
    TYVHumanGetMarried(human, partnerHuman);
    printf("%s\n", TYVHumanGetPartner(human)->_name->_data);
    
    TYVHumanGetMarried(human, NULL);
    assert(NULL == TYVHumanGetPartner(human));
}
