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
    TYVLinkedListNode *previousNode;
    TYVLinkedListNode *currentNode;
    TYVObject *object;
};

typedef bool(TYVComparisonFunction)(TYVLinkedListNode *node, TYVContext *context);

extern
void TYVLinkedListSetRootNode(TYVLinkedList *list, TYVLinkedListNode *node);

extern
TYVLinkedListNode *TYVLinkedListGetRootNode(TYVLinkedList *list);

extern
uint64_t TYVLinkedListGetMutationCount(TYVLinkedList *list);

extern
TYVLinkedListNode *TYVLinkedListFindNodeWithObject(TYVLinkedList *list, TYVComparisonFunction *function, TYVContext *context);

extern
bool TYVLinkedListNodeContainsObject(TYVLinkedListNode *node, TYVContext *context);

extern
TYVContext TYVLinkedListGetContextForObject(TYVLinkedList *list, TYVObject *object);

extern
void TYVLinkedListMutate(TYVLinkedList *list);

extern
void TYVLinkedListCutToNode(TYVLinkedList *list, TYVLinkedListNode *node, uint64_t emptyStackCount);

#endif
