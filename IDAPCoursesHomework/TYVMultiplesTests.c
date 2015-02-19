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
    TYVOutputMultiplesNumber(6);
    TYVOutputMultiplesNumber(10);
    TYVOutputMultiplesNumber(45);
    TYVSayOnlyMAMATest();
    TYVSayOnlyPAPATest();
    TYVSayMAMAPAPATest();
    TYVSayNothingTest();
}

#pragma mark -
#pragma mark Private Implementations

void TYVSayOnlyMAMATest(){
    assert(TYVSayMama == TYVOutputMultiplesNumber(3));
    assert(TYVSayMama == TYVOutputMultiplesNumber(6));
}

void TYVSayOnlyPAPATest(){
    assert(TYVSayPapa == TYVOutputMultiplesNumber(5));
    assert(TYVSayPapa == TYVOutputMultiplesNumber(10));
}

void TYVSayMAMAPAPATest(){
    assert(TYVSayMamapapa == TYVOutputMultiplesNumber(15));
    assert(TYVSayMamapapa == TYVOutputMultiplesNumber(30));
}

void TYVSayNothingTest(){
    assert(TYVSayNothing == TYVOutputMultiplesNumber(7));
    assert(TYVSayNothing == TYVOutputMultiplesNumber(17));
}
