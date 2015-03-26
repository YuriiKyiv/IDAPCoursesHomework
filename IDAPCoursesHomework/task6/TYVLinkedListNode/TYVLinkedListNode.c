//
//  TYVLinkedListNode.c
//  IDAPCoursesHomework
//
//  Created by YURII on 26.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVLinkedListNode.h"
#include "TYVPropertySetters.h"

TYVLinkedListNode *TYVLinkedListNodeCreate() {
    return TYVLinkedListNodeCreateWithObjectAndNextNode(NULL, NULL);
}

TYVLinkedListNode *TYVLinkedListNodeCreateWithObject(TYVObject *object) {
    return TYVLinkedListNodeCreateWithObjectAndNextNode(object, NULL);
}

TYVLinkedListNode *TYVLinkedListNodeCreateWithObjectAndNextNode(TYVObject *object, TYVLinkedListNode *nextNode) {
    TYVLinkedListNode *node = TYVObjectCreate(TYVLinkedListNode);
    TYVLinkedListNodeSetObject(node, object);
    TYVLinkedListNodeSetNextNode(node, nextNode);
    
    return node;
}

void __TYVLinkedListNodeDeallocate(TYVLinkedListNode *node) {
    if (NULL == node) {
        return;
    }
    
    TYVLinkedListNodeSetObject(node, NULL);
    TYVLinkedListNodeSetNextNode(node, NULL);
    
    __TYVObjectDeallocate(node);
}

void TYVLinkedListNodeSetNextNode(TYVLinkedListNode *node, TYVLinkedListNode *nextNode) {
    if (NULL == node || node->_nextNode == nextNode) {
        return;
    }
    
    TYVPropertySetRetain(node->_nextNode, nextNode);
}

TYVLinkedListNode *TYVLinkedListNodeGetNextNode(TYVLinkedListNode *node) {
    return (NULL != node) ? node->_nextNode : NULL;
}

void TYVLinkedListNodeSetObject(TYVLinkedListNode *node, TYVObject *object) {
    if (NULL == node || node->_object == object) {
        return;
    }
    
    TYVPropertySetRetain(node->_object, object);
}

TYVObject *TYVLinkedListNodeGetObject(TYVLinkedListNode *node) {
    return (NULL != node) ? node->_object : NULL;
}
