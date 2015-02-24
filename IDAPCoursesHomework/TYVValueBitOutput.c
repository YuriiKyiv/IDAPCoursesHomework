//
//  TYVValueBitOutput.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutput.h"

void TYVByteLoop(unsigned char charValue);

void TYVValueBitsOutput(void *valueRef, size_t size, TYVEndian endian) {
    unsigned char *charValueRef = (unsigned char *)valueRef;
    size_t iter = 0;
    for (long int byteIter = 0; byteIter < size; byteIter++) {
        iter = endian ? byteIter : size - byteIter - 1;
        unsigned char charValue = charValueRef[iter];
        TYVByteLoop(charValue);
        printf(" ");
    }
    
    printf("\n");
}

inline
void TYVByteLoop(unsigned char charValue){
    for (int bitIter = 0; bitIter < 8; bitIter++) {
        printf("%u", 0 != (charValue & 128));
        charValue <<= 1;
    }
}
