//
//  TYVLinkedListEnumeratorPrivate.h
//  IDAPCoursesHomework
//
//  Created by YURII on 28.03.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef IDAPCoursesHomework_TYVLinkedListEnumeratorPrivate_h
#define IDAPCoursesHomework_TYVLinkedListEnumeratorPrivate_h

#pragma mark -
#pragma mark Private Declarations

extern
void TYVLinkedListEnumeratorSetList(TYVLinkedListEnumerator *enumerator, TYVLinkedList *list);

extern
TYVLinkedList *TYVLinkedListEnumeratorGetList(TYVLinkedListEnumerator *enumerator);

extern
void TYVLinkedListEnumeratorSetNode(TYVLinkedListEnumerator *enumerator, TYVLinkedListNode *node);

extern
TYVLinkedListNode *TYVLinkedListEnumeratorGetNode(TYVLinkedListEnumerator *enumerator);

extern
void TYVLinkedListEnumeratorSetMutationCount(TYVLinkedListEnumerator *enumerator, uint64_t mutationCount);

extern
uint64_t TYVLinkedListEnumeratorGetMutationCount(TYVLinkedListEnumerator *enumerator);

extern
bool TYVLinkedListEnumeratorCheckMutation(TYVLinkedListEnumerator *enumerator);

#endif
