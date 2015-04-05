//
//  TYVAutoreleasePoolTests.c
//  IDAPCoursesHomework
//
//  Created by YURII on 04.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#include <assert.h>

#include "TYVAutoreleasePoolTests.h"
#include "TYVAutoreleasePool.h"
#include "TYVObject.h"

void TYVAutoreleasePoolBehaviorTest();

// IDPAutoreleasePool
//  after calling new and receiving pool
//      after adding IDPObject *value
//          values retain count should not change
//              after draining the pool
//                  values retain count should decrement
//      after adding IDPObject *value 2000 times
//          values retain count should not change
//              after calling new and receiving pool1
//                  pool1 should equal pool
//                      after calling new and receiving pool2
//                          value retain count shoudln't change
//                              after draining pool2
//                                  value retain count shouldn't change
//                                      after adding value
//                                          value retain count shouldn't change
//                                              after draining the pool1
//                                                  value retain count should decrement
//                                                      after draining the pool
//                                                          value retain count should

void TYVAutoreleasePoolPerfomTest() {
    TYVAutoreleasePoolBehaviorTest();
}

void TYVAutoreleasePoolBehaviorTest() {
    TYVAutoreleasePool *pool = TYVAutoreleasePoolCreate();
    TYVObject *object1 = TYVObjectCreate(TYVObject);
    TYVObjectRetain(object1);
    TYVAutoreleasePoolAddObject(pool, object1);
    assert(TYVObjectGetReferenceCount(object1) == 2);
    TYVAutoreleasePoolDrain(pool);
    assert(TYVObjectGetReferenceCount(object1) == 1);
    
    
    int count = 10000;
    for (int i = 0; i < count; i++) {
        TYVObjectRetain(object1);
        TYVAutoreleasePoolAddObject(pool, object1);
    }
    assert(TYVObjectGetReferenceCount(object1) == count + 1);
    TYVAutoreleasePool *pool1 = TYVAutoreleasePoolCreate();
    assert(pool == pool1);
    assert(TYVObjectGetReferenceCount(object1) == count + 1);
    TYVAutoreleasePool *pool2 = TYVAutoreleasePoolCreate();
    TYVAutoreleasePoolDrain(pool2);
    assert(TYVObjectGetReferenceCount(object1) == count + 1);
    
    TYVObjectRelease(object1);
}

