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

enum TYVGender {male, female};
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
TYVHuman *TYVHumanStructCreate(TYVName *name, unsigned int age);

extern
void TYVHumanRetain(TYVHuman *human);

extern
void TYVHumanRelease(TYVHuman *human);

#endif /* defined(__IDAPCoursesHomework__TYVHumanStruct__) */
