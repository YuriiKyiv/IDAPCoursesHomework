//
//  TYVLinkedListPrivate.h
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef IDAPCoursesHomework_TYVLinkedListPrivate_h
#define IDAPCoursesHomework_TYVLinkedListPrivate_h

#pragma mark -
#pragma mark Private Declarations

typedef struct TYVContext TYVContext;
struct TYVContext {
    TYVLinkedListNode *prevNode;
    TYVLinkedListNode *currentNode;
    TYVObject *comparable;
};

typedef bool(TYVCompare)(TYVLinkedListNode *node, TYVContext *context);

extern
void TYVLinkedListSetRootNode(TYVLinkedList *list, TYVLinkedListNode *node);

extern
TYVLinkedListNode *TYVLinkedListGetRootNode(TYVLinkedList *list);

extern
uint64_t TYVLinkedListGetMutationCount(TYVLinkedList *list);

extern
TYVLinkedListNode *TYVLinkedListFindNodeWithObject(TYVLinkedList *list, TYVCompare function, TYVContext *context);

extern
bool TYVComparing(TYVLinkedListNode *node, TYVContext *context);

extern
TYVContext TYVLinkedListGetContextForObject(TYVLinkedList *list, TYVObject *object);

#endif
