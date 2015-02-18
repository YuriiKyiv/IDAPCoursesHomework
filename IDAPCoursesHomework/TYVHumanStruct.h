//
//  TYVHumanStruct.h
//  IDAPCoursesHomework
//
//  Created by YURII on 17.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVHumanStruct__
#define __IDAPCoursesHomework__TYVHumanStruct__

#include <stdio.h>
#include "TYVName.h"
#include "stdbool.h"

enum TYVGender {TYVmale, TYVfemale};
typedef enum TYVGender TYVGender;

enum TYVMarried {yes, no};
typedef enum TYVMarried TYVMarried;

typedef struct TYVHuman TYVHuman;
struct TYVHuman {
    TYVName *_name;
    unsigned int _age;
    TYVGender _gender;
//    unsigned int _childrenCount;
    TYVMarried _married;
    TYVHuman *_partner;
    TYVHuman *_mather;
    TYVHuman *_father;
//    TYVHuman *_childrenRef[20];

    uint64_t _referenceCount;
};

extern
TYVHuman *TYVHumanCreate(TYVName *name, unsigned int age, TYVGender gender, TYVMarried married);

extern
void TYVHumanRetain(TYVHuman *human);

extern
void TYVHumanRelease(TYVHuman *human);

extern
TYVName *TYVHumanGetName(TYVHuman *human);

extern
unsigned int TYVHumanGetAge(TYVHuman *human);

extern
void TYVHumanSetAge(TYVHuman *human, unsigned int age);

extern
TYVGender TYVHumanGetGender(TYVHuman *human);

extern
TYVMarried TYVHumanGetMerriedStatus(TYVHuman *human);

extern
TYVHuman *TYVHumanGetPartner(TYVHuman *human);

extern
void TYVHunamGetMarried(TYVHuman *male, TYVHuman *female);

extern
bool TYVHumanIsSamePartners(TYVHuman *male, TYVHuman *female);

extern
bool TYVHumanIsDifferentGender(TYVHuman *male, TYVHuman *female);

extern
void TYVHumanDivorce(TYVHuman *male, TYVHuman *female);

extern
TYVHuman *TYVHumanMakeChildren(TYVHuman *male, TYVHuman *female, TYVName *name, unsigned int age, TYVGender gender);

#endif /* defined(__IDAPCoursesHomework__TYVHumanStruct__) */
