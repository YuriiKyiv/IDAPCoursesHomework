//
//  TYVLinkedListNode.c
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListNode.h"

TYVLinkedListNode *TYVLinkedListNodeCreate(TYVObject *object) {
    TYVLinkedListNode *node = TYVObjectCreate(TYVLinkedListNode);
    TYVLinkedListNodeSetObject(node, object);
    return node;
}

void __TYVLinkedListNodeDeallocate(TYVLinkedListNode *node) {
    TYVLinkedListNodeSetObject(node, NULL);
    TYVLinkedListNodeSetNextNode(node, NULL);
    
    __TYVObjectDeallocate(node);
}

extern
void TYVLinkedListNodeSetNextNode(TYVLinkedListNode *node, TYVLinkedListNode *nextNode);

extern
TYVLinkedListNode *TYVLinkedListNodeGetNextNode(TYVLinkedListNode *node);

extern
void TYVLinkedListNodeSetObject(TYVLinkedListNode *node, TYVObject *object);

extern
TYVObject *TYVLinkedListNodeGetNextNode(TYVLinkedListNode *node);
