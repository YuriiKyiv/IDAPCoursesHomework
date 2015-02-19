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

TYVWhatSay TYVOutputMultiplesNumber(int number) {
    TYVWhatSay result = TYVSayNothing;
    if (0 == (number % 3)) {
        printf("%s ", mamaMessage);
        result +=1;
    }
    
    if (0 == (number % 5)) {
        printf("%s ", papaMessage);
        result += 2;
    }
    
    printf("\n");
    
    return result;
}
