//
//  main.c
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdio.h>
#include "TYVMultiplesTests.h"
#include "TYVMultiples.h"

void TYVOutputMultiplesNumberLoop(int iter);

const int iterations = 1000;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    TYVOutputMultiplesNumberLoop(iterations);
    
    TYVMultiplesTests();
    
    return 0;
}

inline
void TYVOutputMultiplesNumberLoop(int iter){
    for (int iter = 0; iter < iterations; iter++) {
        printf("Iteration: %d ", iter);
        TYVMultiplesOutputMessage(iter);
        printf("\n");
    }
}
