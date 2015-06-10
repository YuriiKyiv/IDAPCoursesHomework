//
//  TYVDispatch.c
//  IDAPCoursesHomework
//
//  Created by Yurii Trokhymchuk on 6/9/15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include "TYVDispatch.h"

#pragma mark -
#pragma mark Private Declarations

typedef void(TYVperfomBlockOnMainQueue)(void *self, void *context);

#pragma mark -
#pragma mark Public Implementations

void dispatch_sync_onMainQueue(TYVperfomBlockOnMainQueue *block) {

}