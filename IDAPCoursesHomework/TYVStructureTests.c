//
//  TYVStructureTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVStructureTests.h"
#include "TYVStructure.h"
#include <stdbool.h>
#include <stddef.h>

void TYVStuctureTestsRunAll(){
    TYVStrucureSizeTest();
    TYVStrucureOptimizedSizeTest();
    TYVFieldSizesTest();
    TYVBasicUnionStructureTest();
}

void TYVStrucureSizeTest(){
    TYVBasicStructure structure;
    printf("Size of the basic stucture : %lu \n",sizeof(structure));
}

void TYVStrucureOptimizedSizeTest(){
    TYVBasicOptimizedStructure structure;
    printf("Size of the optimized stucture : %lu \n",sizeof(structure));
}

void TYVStructureOffsetofTest(){
//    TYVBasicStructure strucuture;
//    doesn't work the offsetof method
    TYVBasicOptimizedStructure strucuture;
}

void TYVBasicUnionStructureTest(){
    TYVBasicUnionStructure structure;
    printf("%d\n",structure.data.bits.bool1 = 1);
}

void TYVFieldSizesTest(){
    printf("Size of long long : %lu \n",sizeof(long long));
    printf("Size of long : %lu \n",sizeof(long));
    printf("Size of int : %lu \n",sizeof(int));
    printf("Size of char : %lu \n",sizeof(char));
    printf("Size of short : %lu \n",sizeof(short));
    printf("Size of bool : %lu \n",sizeof(bool));
    printf("Size of float : %lu \n",sizeof(float));
    printf("Size of double : %lu \n",sizeof(double));
}