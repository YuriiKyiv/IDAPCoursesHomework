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

static
void TYVHumanCreateTest();

void TYVHumanTests(){
    TYVHumanCreateTest();
}

void TYVHumanCreateTest(){
    char name[] = "Vasy Pupkin";
    TYVString *string = TYVStringCreate(name, 8);
    TYVHumanCreate(string, 100, TYVMale);
}