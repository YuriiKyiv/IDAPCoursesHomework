//
//  TYVLinkedListNode.h
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVLinkedListNode__
#define __IDAPCoursesHomework__TYVLinkedListNode__

#include <stdio.h>
#include "TYVObject.h"

typedef struct TYVLinkedListNode TYVLinkedListNode;
struct TYVLinkedListNode {
    TYVObject _super;
    
    TYVLinkedListNode *nextNode;
    TYVObject *object;
};

extern
TYVLinkedListNode *TYVLinkedListNodeCreare(TYVObject *object);

extern
void __TYVLinkedListNodeDeallocate(TYVLinkedListNode *node);

extern
void TYVLinkedListNodeSetNextNode(TYVLinkedListNode *node, TYVLinkedListNode *nextNode);

extern
TYVLinkedListNode *TYVLinkedListNodeGetNextNode(TYVLinkedListNode *node);

extern
void TYVLinkedListNodeSetObject(TYVLinkedListNode *node, TYVObject *object);

extern
TYVObject *TYVLinkedListNodeGetNextNode(TYVLinkedListNode *node);

#endif /* defined(__IDAPCoursesHomework__TYVLinkedListNode__) */
