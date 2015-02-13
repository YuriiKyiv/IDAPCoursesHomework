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
const char zero = '\0';

enum multiples {mama = 3, papa = 5, mamapapa = 15};
typedef enum multiples multiples;

enum code {sayMama = 1, sayPapa = 10, sayMamapapa = 100};
typedef enum code code;

int TYVOutputMultiplesNumber(int number) {
    int result = zero;
    if (zero == (number % mama)) {
        printf("%s ", say_mama);
        result += sayMama;
    }
    
    if (zero == (number % papa)) {
        printf("%s ", say_papa);
        result += sayPapa;
    }
    
    if (zero == (number % mamapapa)) {
        printf("%s ", say_mama_papa);
        result += sayMamapapa;
    }
    
    return result;
}
