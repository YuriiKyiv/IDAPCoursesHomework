//
//  TYVBitFinder.c
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVBitFinder.h"

#define SCHEEM 10000000

void TYVBitCount(char value){
    puts(value & SCHEEM);
}