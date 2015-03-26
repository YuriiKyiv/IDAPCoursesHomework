//
//  TYVLinkedListNode.c
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListNode.h"

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