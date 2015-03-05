//
//  TYVStringTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 21.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStringTests.h"
#include "TYVString.h"
#include "assert.h"
#include "TYVObject.h"

static
void TYVStringCreateTest();

void TYVStringTestsPerfom(){
    printf("\nTASK 5\n");
    TYVStringCreateTest();

}

void TYVStringCreateTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    char *data = TYVStringGetData(string);
    printf("%s\n", data);
    assert(*name == *data);
}

void TYVStringBehaviorTest(){
    char name[] = "Vasya Pupkin";
    TYVString *string = TYVStringCreate(name);
    assert(name == TYVStringGetData(string));
    assert(TYVStringGetLength(string) == 12);
    
    char newName[] = "Masha";
    TYVStringSetData(string, newName);
    assert(name != TYVStringGetData(string));
    assert(newName == TYVStringGetData(string));
    assert(TYVStringGetLength(string) == 5);
}
