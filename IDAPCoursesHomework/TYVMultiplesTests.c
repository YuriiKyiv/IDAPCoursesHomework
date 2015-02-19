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
void TYVSayOnlyMAMA();

static
void TYVSayOnlyPAPA();

static
void TYVSayMAMAPAPA();

static
void TYVSayNothing();

#pragma mark -
#pragma mark Public Implementations

void TYVMultiplesTests(){
    TYVOutputMultiplesNumber(6);
    TYVOutputMultiplesNumber(10);
    TYVOutputMultiplesNumber(45);
    TYVSayOnlyMAMA();
    TYVSayOnlyPAPA();
    TYVSayMAMAPAPA();
    TYVSayNothing();
}

#pragma mark -
#pragma mark Private Implementations

void TYVSayOnlyMAMA(){
    assert(TYVSayMama == TYVOutputMultiplesNumber(3));
    assert(TYVSayMama == TYVOutputMultiplesNumber(6));
}

void TYVSayOnlyPAPA(){
    assert(TYVSayPapa == TYVOutputMultiplesNumber(5));
    assert(TYVSayPapa == TYVOutputMultiplesNumber(10));
}

void TYVSayMAMAPAPA(){
    assert(TYVSayMamapapa == TYVOutputMultiplesNumber(15));
    assert(TYVSayMamapapa == TYVOutputMultiplesNumber(30));
}

void TYVSayNothing(){
    assert(TYVSayNothing == TYVOutputMultiplesNumber(7));
    assert(TYVSayNothing == TYVOutputMultiplesNumber(17));
}
