//
//  TYVValueBitOutput.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutput.h"

void TYVBitLoop(unsigned char charValue);

void TYVValueBitOutput(void *valueRef, size_t size, TYVEndian endian) {
    unsigned char *charValueRef = (unsigned char *)valueRef;
    unsigned char charValue = 0;
    size_t iter = 0;
    for (long int byteIter = 0; byteIter < size; byteIter++) {
        iter = endian == TYVLitleEndian ? byteIter : size - byteIter - 1;
        charValue = charValueRef[iter];
        TYVBitLoop(charValue);
    }
    
    printf("\n");
}

inline
void TYVBitLoop(unsigned char charValue){
    for (int bitIter = 0; bitIter < 8; bitIter++) {
        printf("%u", 0 != (charValue & 128));
        charValue <<= 1;
    }
    
    printf(" ");
}
