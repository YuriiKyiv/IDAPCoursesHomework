//
//  main.m
//  TYVObjCHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVBeing.h"
#import "TYVMaleBeing.h"
#import "TYVFemaleBeing.h"
#import "TYVCarwashEnterprise.h"
#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"
#import "TYVCarManager.h"
#import "TYVWasher.h"
#import "TYVCar.h"
#import "TYVAccountant.h"
#import "TYVDirector.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");

        TYVCarwashEnterprise *enterprise = [TYVCarwashEnterprise object];
        
        TYVCarManager *carManager = [[[TYVCarManager alloc] initWithEnterprise:enterprise
                                                                   carCapacity:5
                                                                         delay:1] autorelease];
        [carManager start];

        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
    
    return 0;
}
