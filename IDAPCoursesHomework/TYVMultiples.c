//
//  TYVMultiples.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVMultiples.h"
#include "stdlib.h"

const char say_mama[] = "MAMA";
const char say_papa[] = "PAPA";
const char say_mama_papa[] = "MAMAPAPA";

int TYVOutputMultiplesNumber(int number) {
    
    int result = 0;
    
    if (0 == (number % 3)) {
        printf("%s ",say_mama);
        result += 1;
    }
    
    if (0 == (number % 5)) {
        printf("%s ",say_papa);
        result += 10;
    }
    
    if (0 == (number % 15)) {
        printf("%s ",say_mama_papa);
        result += 100;
    }
    
    return result;
}
