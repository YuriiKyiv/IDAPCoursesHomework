//
//  TYVHuman.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVHuman.h"
#include "TYVString.h"
#include "stdlib.h"



#pragma mark -
#pragma mark Public Implementations

struct TYVHuman {
    TYVString *_name;
    uint8_t _age;
    TYVGender _gender;
    
    size_t _referenceCount;
};

TYVHuman *TYVHumanCreate(TYVString *string, uint8_t age, TYVGender gender){
    TYVHuman *human = malloc(sizeof(*human));
    human->_referenceCount = 1;
    human->_name = string;
    human->_age = age;
    human->_gender = gender;
    
    return human;
}