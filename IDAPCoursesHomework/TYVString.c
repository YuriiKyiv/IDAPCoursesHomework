//
//  TYVString.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVString.h"
#include "stdlib.h"

struct TYVString {
    char *data;
    uint8_t length;
};

TYVString *TYVStringCreate(char *data, uint8_t length){
    TYVString *string = malloc(sizeof(*string));
    string->data = data;
    string->length = length;
    
    return string;
}