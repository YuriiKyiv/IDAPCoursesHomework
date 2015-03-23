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

//after creating a string with "mama"
//  the length of data equls 5
//  after getting the data of string, this data equals "mama"
//    after setting "helloworl"
//      the length of string equals 10
//        after setting a NULL char pointer
//          the length of string equals 0
//          the data of string equals NULL
//after creating a string with NULL
//  the length of string equals 0
//  the data of string equals NULL

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
    
    TYVObjectRelease(string);
}
