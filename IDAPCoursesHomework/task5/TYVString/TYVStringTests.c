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
    TYVString *string = __TYVObjectCreate(sizeof(TYVString), (TYVDeallocateCallback)&__TYVStringDeallocate);
    TYVStringSetData(string, name);
    char *data = TYVStringGetData(string);
    printf("%s\n", data);
}
