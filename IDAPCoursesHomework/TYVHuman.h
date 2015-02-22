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

//const uint8_t TYVChildrenMaxCount = 20;

typedef enum TYVGender TYVGender;
enum TYVGender {
    TYVMale,
    TYVFemale
};

typedef struct TYVHuman TYVHuman;
struct TYVHuman {
    TYVString *_name;
    uint8_t _age;
    TYVGender _gender;
    uint8_t _childrenCount;
    TYVHuman *_partner;
    TYVHuman *_father;
    TYVHuman *_mother;
    TYVHuman *_children[20];
    
    size_t _referenceCount;
};

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender);

void TYVHumanRetain(TYVHuman *string);

void TYVHumanRelease(TYVHuman *string);

void TYVHumanDivorce(TYVHuman *human);

TYVHuman *TYVHumanMate(TYVHuman *human, TYVString *name);

TYVGender TYVHumanGetGender(TYVHuman *human);

#endif /* defined(__IDAPCoursesHomework__TYVHuman__) */
