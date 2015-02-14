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
void TYVSayAll();

#pragma mark -
#pragma mark Public Implementations

void TYVMultiplesTests(){
    TYVOutputMultiplesNumber(6);
    TYVOutputMultiplesNumber(10);
    TYVOutputMultiplesNumber(45);
    TYVSayOnlyMAMA();
    TYVSayOnlyPAPA();
    TYVSayAll();
}

#pragma mark -
#pragma mark Private Implementations

void TYVSayOnlyMAMA(){
    assert(1 == TYVOutputMultiplesNumber(3));
    assert(1 == TYVOutputMultiplesNumber(6));
}

void TYVSayOnlyPAPA(){
    assert(10 == TYVOutputMultiplesNumber(5));
    assert(10 == TYVOutputMultiplesNumber(10));
}

void TYVSayAll(){
    assert(111 == TYVOutputMultiplesNumber(15));
    assert(111 == TYVOutputMultiplesNumber(30));
}
