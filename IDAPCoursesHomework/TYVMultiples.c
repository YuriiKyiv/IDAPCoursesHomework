//
//  TYVMultiples.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVMultiples.h"
#include "stdlib.h"

const char mamaMessage[] = "MAMA";
const char papaMessage[] = "PAPA";
const char mamaPapaMessage[] = "MAMAPAPA";
const char zero = '\0';

enum multiples {mama = 3, papa = 5, mamapapa = 15};
typedef enum multiples multiples;

enum code {sayMama = 1, sayPapa = 10, sayMamapapa = 100};
typedef enum code code;

int TYVOutputMultiplesNumber(int number) {
    int result = zero;
    if (zero == (number % mama)) {
        printf("%s ", mamaMessage);
        result += sayMama;
    }
    
    if (zero == (number % papa)) {
        printf("%s ", papaMessage);
        result += sayPapa;
    }
    
    if (zero == (number % mamapapa)) {
        printf("%s ", mamaPapaMessage);
        result += sayMamapapa;
    }
    
    return result;
}
