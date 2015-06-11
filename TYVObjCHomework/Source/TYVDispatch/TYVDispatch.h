//
//  TYVDispatch.h
//  IDAPCoursesHomework
//
//  Created by Yurii Trokhymchuk on 6/9/15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#ifndef __IDAPCoursesHomework__TYVDispatch__
#define __IDAPCoursesHomework__TYVDispatch__

typedef void(^TYVBlock)();

void TYVDispatchSyncOnMainQueueWithBlock(TYVBlock block);

#endif /* defined(__IDAPCoursesHomework__TYVDispatch__) */
