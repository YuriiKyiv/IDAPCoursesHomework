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

void TYVStrucureSizeTest(){
    TYVBasicStructure strucuture;
    printf("Size of the basic stucture : %lu \n",sizeof(strucuture));
}

void TYVStrucureOptimizedSizeTest(){
    TYVBasicOptimizedStructure strucuture;
    printf("Size of the optimized stucture : %lu \n",sizeof(strucuture));
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