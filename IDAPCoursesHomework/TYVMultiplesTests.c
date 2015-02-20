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
    assert(TYVMama == TYVMultiplesOutputMessage(3));
    assert(TYVMama == TYVMultiplesOutputMessage(6));
}

void TYVSayOnlyPAPATest(){
    assert(TYVPapa == TYVMultiplesOutputMessage(5));
    assert(TYVPapa == TYVMultiplesOutputMessage(10));
}

void TYVSayMAMAPAPATest(){
    assert(TYVMamaPapa == TYVMultiplesOutputMessage(15));
    assert(TYVMamaPapa == TYVMultiplesOutputMessage(30));
}

void TYVSayNothingTest(){
    assert(TYVNothing == TYVMultiplesOutputMessage(7));
    assert(TYVNothing == TYVMultiplesOutputMessage(17));
}
