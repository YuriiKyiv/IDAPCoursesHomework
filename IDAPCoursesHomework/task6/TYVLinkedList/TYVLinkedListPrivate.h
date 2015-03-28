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

extern
void TYVLinkedListSetRootNode(TYVLinkedList *list, TYVLinkedListNode *node);

extern
TYVLinkedListNode *TYVLinkedListGetRootNode(TYVLinkedList *list);

extern
uint64_t TYVLinkedListGetMutationCount(TYVLinkedList *list);

#endif
