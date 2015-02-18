//
//  TYVName.c
//  IDAPCoursesHomework
//
//  Created by YURII on 18.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVName.h"
#include "stdlib.h"

TYVName *TYVNameCreate(){
    TYVName *name = malloc(sizeof(*name));
    name->name = NULL;
    name->_referenceCount = 1;
    
    return name;
}