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
void TYVLinkedListEnumeratorSetNode(TYVLinkedListEnumerator *enumerator, TYVLinkedList *node);

extern
void TYVLinkedListEnumeratorSetMutationCount(TYVLinkedListEnumerator *enumerator, uint64_t mutationCount);

#endif
