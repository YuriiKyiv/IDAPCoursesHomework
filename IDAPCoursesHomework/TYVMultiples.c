//
//  TYVMultiples.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVMultiples.h"
#include "stdlib.h"

const char say_mama[] = "MAMA\n";
const char say_papa[] = "PAPA\n";
const char say_mama_papa[] = "MAMAPAPA\n";

int TYVOutputMultiplesNumber(int number) {
    
    if (0 == (number % 3)) {
        printf("%s",say_mama);
    }
    printf("%s",say_mama);
    return 0;
}