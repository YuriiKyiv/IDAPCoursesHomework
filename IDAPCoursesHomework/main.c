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
#include <assert.h>
#include "TYVStructureTests.h"

#define TYVValueOutputGenerate(type, spec) \
    type TYVOutput_##type(type value) { \
        printf("%"#spec, value); \
        return value; \
    }

#define TYVOutputValue(type, value) \
TYVOutput_##type(value);

const int iterations = 1000;

void TYVOutputMultiplesNumberLoop(int iter);

void TYVTask1Perform();

void TYVTask2Perform();

void TYVTask3Perform();

TYVValueOutputGenerate(int, d);
TYVValueOutputGenerate(long, ld);
TYVValueOutputGenerate(char, c);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    TYVTask1Perform();
    
    TYVTask2Perform();
    
    TYVTask3Perform();
    
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

inline
void TYVTask1Perform(){
    TYVOutputMultiplesNumberLoop(iterations);
    TYVMultiplesTests();
}

inline
void TYVTask2Perform(){
    TYVOutputValue(int, 15)
    TYVOutputValue(long, 100500)
    TYVOutputValue(char,'c')
    
    assert(12 == TYVOutput_int(12));
    assert(100500 == TYVOutput_long(100500));
    assert('c'== TYVOutput_char('c'));
}

inline
void TYVTask3Perform(){
    TYVStuctureTestsRun();
}
