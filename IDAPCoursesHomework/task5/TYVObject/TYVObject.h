//
//  TYVObject.h
//  IDAPCoursesHomework
//
//  Created by YURII on 27.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVObject__
#define __IDAPCoursesHomework__TYVObject__

#include <stdio.h>

typedef void(*TYVDeallocateCallback)(void *);

struct TYVObject {
    uint64_t _referenceCount;
    TYVDeallocateCallback _deallocateCallback;
};
typedef struct TYVObject TYVObject;

extern
void *__TYVObjectCreate(size_t objectSize, TYVDeallocateCallback deallocateCallback);
#define TYVObjectCreate(type) \
    __TYVObjectCreate(sizeof(type), (IDPDeallocateCallback)__##type##Deallocate)

extern
void *TYVObjectRetain(void *object);

extern
void TYVObjectRelease(void *object);

extern
void TYVObjectDeallocate(void *object);

#endif /* defined(__IDAPCoursesHomework__TYVObject__) */
