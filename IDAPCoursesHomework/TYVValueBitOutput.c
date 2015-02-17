//
//  TYVValueBitOutput.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutput.h"
#include "stdbool.h"

void TYVBitLoop(unsigned char charValue);
void TYVByteLoop(unsigned char charValue, unsigned char *charValueRef, size_t size, size_t start, size_t end);

void TYVValueBitOutput(void *valueRef, size_t size, bool endian) {
    unsigned char *charValueRef = (unsigned char *)valueRef;
    unsigned char charValue = 0;
    endian ?
        TYVByteLoop(charValue, charValueRef, size, 0, size) :
        TYVByteLoop(charValue, charValueRef, size, size-1, 0);
    printf("\n");
}

inline
void TYVByteLoop(unsigned char charValue, unsigned char *charValueRef, size_t size, size_t start, size_t end){
    for (long int byteIter = start; byteIter < end; byteIter++) {
        charValue = charValueRef[byteIter];
        TYVBitLoop(charValue);
    }
}

inline
void TYVBitLoop(unsigned char charValue){
    for (int bitIter = 0; bitIter < 8; bitIter++) {
        printf("%u", 0 != (charValue & 128));
        charValue <<= 1;
    }
}
