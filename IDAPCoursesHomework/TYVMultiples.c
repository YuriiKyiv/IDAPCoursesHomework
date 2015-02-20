//
//  TYVMultiples.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVMultiples.h"
#include "stdlib.h"

const char TYVMamaMessage[] = "MAMA";
const char TYVPapaMessage[] = "PAPA";

TYVOutputMessage TYVMultiplesOutputMessage(int number) {
    if (0 == number){
        return TYVNothing;
    }
    TYVOutputMessage result = TYVNothing;
    if (0 == (number % 3)) {
        printf("%s", TYVMamaMessage);
        result +=1;
    }
    
    if (0 == (number % 5)) {
        printf("%s", TYVPapaMessage);
        result += 2;
    }
    
    printf("\n");
    
    return result;
}
