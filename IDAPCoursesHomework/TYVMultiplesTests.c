//
//  TYVMultiplesTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVMultiplesTests.h"
#include "TYVMultiples.h"
#include "assert.h"

#pragma mark -
#pragma mark Private Definitions

static
void TYVSayOnlyMAMATest();

static
void TYVSayOnlyPAPATest();

static
void TYVSayMAMAPAPATest();

static
void TYVSayNothingTest();

#pragma mark -
#pragma mark Public Implementations

void TYVMultiplesTests(){
    TYVSayOnlyMAMATest();
    TYVSayOnlyPAPATest();
    TYVSayMAMAPAPATest();
    TYVSayNothingTest();
}

#pragma mark -
#pragma mark Private Implementations

void TYVSayOnlyMAMATest(){
    assert(TYVOutputMama == TYVMultiplesOutputMessage(3));
    assert(TYVOutputMama == TYVMultiplesOutputMessage(6));
}

void TYVSayOnlyPAPATest(){
    assert(TYVOutputPapa == TYVMultiplesOutputMessage(5));
    assert(TYVOutputPapa == TYVMultiplesOutputMessage(10));
}

void TYVSayMAMAPAPATest(){
    assert(TYVOutputMamaPapa == TYVMultiplesOutputMessage(15));
    assert(TYVOutputMamaPapa == TYVMultiplesOutputMessage(30));
}

void TYVSayNothingTest(){
    assert(TYVOutputNothing == TYVMultiplesOutputMessage(7));
    assert(TYVOutputNothing == TYVMultiplesOutputMessage(17));
}
