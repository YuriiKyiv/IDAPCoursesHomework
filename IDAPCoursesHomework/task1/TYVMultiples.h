//
//  TYVMultiples.h
//  IDAPCoursesHomework
//
//  Created by YURII on 13.02.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVMultiples__
#define __IDAPCoursesHomework__TYVMultiples__

#include <stdio.h>

enum TYVOutputMessage {
    TYVOutputNothing,
    TYVOutputMama,
    TYVOutputPapa,
    TYVOutputMamaPapa
};
typedef enum TYVOutputMessage TYVOutputMessage;

TYVOutputMessage TYVMultiplesOutputMessage(int number);

#endif /* defined(__IDAPCoursesHomework__TYVMultiples__) */
