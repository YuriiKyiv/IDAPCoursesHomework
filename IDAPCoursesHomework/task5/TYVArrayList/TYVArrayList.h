//
//  TYVArrayList.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVArrayList__
#define __IDAPCoursesHomework__TYVArrayList__

#include <stdio.h>
#include "TYVObject.h"

typedef struct TYVArrayList TYVArrayList;

struct TYVArrayList {
    TYVObject _object;
    
    void *_data;
    
    uint64_t _count;
    size_t _size;
};

TYVArrayList *TYVArrayListCreate(size_t size);

void __TYVArrayListDeallocate(TYVArrayList *arrayList);

#endif /* defined(__IDAPCoursesHomework__TYVArrayList__) */
