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
#include "stdbool.h"
#include "TYVValueBitOutputTests.h"
#include "TYVEndian.h"
#include "TYVStringTests.h"
#include "TYVHumanTests.h"
#include "TYVArrayListTests.h"
#include "TYVStackTest.h"
#include "TYVLinkedListNodeTests.h"
#include "TYVLinkedListTests.h"
#include "TYVAutoreleasePoolTests.h"

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

void TYVTask4Perform();

void TYVTask5Perform();

void TYVTask6Perfom();

TYVValueOutputGenerate(int, d);
TYVValueOutputGenerate(long, ld);
TYVValueOutputGenerate(char, c);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    TYVTask1Perform();
//    
//    TYVTask2Perform();
//    
//    TYVTask3Perform();
//    
//    TYVTask4Perform();
    
    TYVTask5Perform();
    
    TYVTask6Perfom();
    
    return 0;
}

inline
void TYVOutputMultiplesNumberLoop(int iter) {
    for (int iter = 0; iter < iterations; iter++) {
        printf("Iteration: %d ", iter);
        TYVMultiplesOutputMessage(iter);
        printf("\n");
    }
}

inline
void TYVTask1Perform() {
    TYVOutputMultiplesNumberLoop(iterations);
    TYVMultiplesTests();
}

inline
void TYVTask2Perform() {
    TYVOutputValue(int, 15)
    TYVOutputValue(long, 100500)
    TYVOutputValue(char,'c')
    
    assert(12 == TYVOutput_int(12));
    assert(100500 == TYVOutput_long(100500));
    assert('c'== TYVOutput_char('c'));
}

inline
void TYVTask3Perform() {
    TYVStuctureTestsRun();
}

inline
void TYVTask4Perform() {
        TYVTests();
}

inline
void TYVTask5Perform() {
    //TYVStringTestsPerfom();
    TYVHumanTests();
    //TYVArrayListPerfomTests();
}

inline
void TYVTask6Perfom() {
//    TYVLinkedListNodePerfomTest();
//    TYVLinkedListPerfomTest();
//    TYVStackTestPerfom();
    TYVAutoreleasePoolPerfomTest();
}
