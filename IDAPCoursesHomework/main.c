//
//  main.c
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdio.h>
#include "TYVStructureTests.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    TYVStrucureSizeTest();
    TYVStrucureOptimizedSizeTest();
    TYVFieldSizesTest();
    TYVBasicUnionStructureTest();
    
    return 0;
}
