//
//  TYVHuman.h
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVHuman__
#define __IDAPCoursesHomework__TYVHuman__

#include <stdio.h>
#include "TYVString.h"
#include "TYVArray.h"
#include "stdbool.h"
#include "TYVArrayList.h"

extern
const uint64_t TYVNotFoundItem;

typedef enum TYVGender TYVGender;
enum TYVGender {
    TYVMale,
    TYVFemale
};

typedef struct TYVHuman TYVHuman;
struct TYVHuman {
    TYVObject _object;
    
    TYVString *_name;
    TYVHuman *_partner;
    TYVHuman *_father;
    TYVHuman *_mother;
    TYVArrayList *_childrenArray;
    
    uint8_t _age;
    TYVGender _gender;
};

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender);

void __TYVHumanDeallocate(TYVHuman *human);

void TYVHumanDivorce(TYVHuman *human);

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name, TYVGender gender);

void TYVHumanSetName(TYVHuman *human, TYVString *string);

TYVString *TYVHumanGetName(TYVHuman *human);

void TYVHumanNameOutput(TYVHuman *human);

void TYVHumanSetGender(TYVHuman *human, TYVGender gender);

TYVGender TYVHumanGetGender(TYVHuman *human);

TYVHuman *TYVHumanGetMother(TYVHuman *human);

TYVHuman *TYVHumanGetFather(TYVHuman *human);

TYVHuman *TYVHumanGetPartner(TYVHuman *human);

void TYVHumanGetMarried(TYVHuman *male, TYVHuman *female);

bool TYVHumanIsMarried(TYVHuman *human);

TYVArrayList *TYVHumanGetArray(TYVHuman *human);

uint8_t TYVHumanGetAge(TYVHuman *human);

uint64_t TYVHumanGetChildrenCount(TYVHuman *human);

#endif /* defined(__IDAPCoursesHomework__TYVHuman__) */
