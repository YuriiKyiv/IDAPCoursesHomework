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

// after creating string object with char doesn't equal null
//     data of string object doesn't equals char pointer
//     length of data equals  input char array

// after creating string object with char doesn't equal null
//      and set a new data of char which doesnt equal null
//          data of string object doesn't equal char pointer
//          length of data equals  input char array

// after creating string object with char equals null
//     data of string object equals null
//     length of data equals  0

// after creating string object with char doesn't equal null
//      and set a new data of char which equals null
//          data of string object equals null
//          length of data equals  0

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
