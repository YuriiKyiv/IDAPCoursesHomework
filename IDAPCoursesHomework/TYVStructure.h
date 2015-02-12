//
//  TYVStructure.h
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVStructure__
#define __IDAPCoursesHomework__TYVStructure__

#include <stdio.h>
#include <stdbool.h>

struct TYVBasicStructure {
    
    bool bool1;
    bool bool2;
    bool bool3;
    bool bool4;
    bool bool5;
    bool bool6;
    
    float float1;
    
    int int1;
    
    long long longLong1;
    
    short short1;
    short short2;
    short short3;
    
    double double1;
    
    char *char1;
    
};

typedef struct TYVBasicStructure TYVBasicStructure;

struct TYVBasicOptimizedStructure {
    
    char *char1;
    
    long long longLong1;
    double double1;
    int int1;
    float float1;
    
    short short1;
    short short2;
    short short3;
    
    bool bool1;
    bool bool2;
    bool bool3;
    bool bool4;
    bool bool5;
    bool bool6;
    
};

typedef struct TYVBasicOptimizedStructure TYVBasicOptimizedStructure;

struct TYVBasicUnionStructure {
    
    union {
        struct {
            bool bool1 : 1;
            bool bool2 : 1;
            bool bool3 : 1;
            bool bool4 : 1;
            bool bool5 : 1;
            bool bool6 : 1;
        } bits;
        uint8_t flags;
    } data;
    
    float float1;
    
    int int1;
    
    long long longLong1;
    
    short short1;
    short short2;
    short short3;
    
    double double1;
    
    char *char1;
    
};

typedef struct TYVBasicUnionStructure TYVBasicUnionStructure;

#endif /* defined(__IDAPCoursesHomework__TYVStructure__) */
