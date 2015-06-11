//
//  TYVDispatch.m
//  IDAPCoursesHomework
//
//  Created by YURII on 10.06.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVDispatch.h"
#import "TYVProtocolObservableObject.h"

#pragma mark -
#pragma mark Public Implementations

void TYVDispatchSyncOnMainQueueWithBlock(TYVBlock block) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}
