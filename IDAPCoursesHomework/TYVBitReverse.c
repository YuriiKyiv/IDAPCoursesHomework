//
//  TYVBitReverse.c
//  IDAPCoursesHomework
//
//  Created by YURII on 19.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVBitReverse.h"
#include "stdbool.h"
#include "TYVValueBitOutput.h"

#pragma mark -
#pragma mark Private Definitions

void TYVReverse(void *number, size_t size);

#pragma mark -
#pragma mark Public Implementations

void TYVByteReverse(void *number, size_t size, bool reverse){
    if (reverse) {
        TYVReverse(number, size);
    }
}

#pragma mark -
#pragma mark Private Implementations

void TYVReverse(void *valueRef, size_t size){
    unsigned char *charValueRef = (unsigned char *)valueRef;
    unsigned char charValue = 0;
    for (int byteIter = 0; byteIter < size / 2; byteIter++){
        charValue = charValueRef[byteIter];
        charValueRef[byteIter] = charValueRef[size - 1 - byteIter];
        charValueRef[size - 1 - byteIter] = charValue;
    }
}