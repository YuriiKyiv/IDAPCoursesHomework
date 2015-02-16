//
//  TYVValueBitOutput.c
//  IDAPCoursesHomework
//
//  Created by YURII on 16.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVValueBitOutput.h"
#include "stdbool.h"

enum endian {litleEndian = 1, bigEndian = 0};

void IDPValueBitOutput(void *valueRef, size_t size, bool endian) {
    unsigned char *charValueRef = (unsigned char *)valueRef;
    unsigned char charValue = 0;
    if (bigEndian == endian) {
        for (long int byteIter = size - 1; byteIter >= 0; byteIter--) {
            charValue = charValueRef[byteIter];
            for (int bitIter = 0; bitIter < 8; bitIter++) {
                printf("%u", 0 != (charValue & 128));
                charValue <<= 1;
            }
    }
        
    } else {
            for (long int byteIter = 0; byteIter < size; byteIter++) {
                charValue = charValueRef[byteIter];
                for (int bitIter = 0; bitIter < 8; bitIter++) {
                    printf("%u", 0 != (charValue & 128));
                    charValue <<= 1;
                }
            }
    }
    
    printf("\n");
}
