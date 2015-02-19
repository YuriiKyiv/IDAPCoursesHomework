//
//  main.c
//  IDAPCoursesHomework
//
//  Created by YURII on 12.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <stdio.h>
#include "stdbool.h"
#include "TYVValueBitOutputTests.h"
#include "TYVEndian.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    printf("%u \n", TYVGetByteOrder());
    
    TYVTests();
    
    return 0;
}
