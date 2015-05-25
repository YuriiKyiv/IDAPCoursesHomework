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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");

        
//        NSMutableArray *array = [NSMutableArray object];
//        TYVBeing *being = NULL;
//        for(int i = 0; i < 1000; i++) {
//            if (i % 2 == 0) {
//                being = [TYVMaleBeing object];
//            } else {
//                being = [TYVFemaleBeing object];
//            }
//            
//            [array addObject:being];
//        }
//        
//        for (TYVBeing *being in array) {
//            [being performGenderSpecificOperation];
//        }
        
        TYVCarwashEnterprise *enterprise = [TYVCarwashEnterprise object];
        [enterprise work];
        
        TYVCarManager *carManager = [[[TYVCarManager alloc] initWithEnterprise:enterprise
                                                                   carCapacity:10
                                                                         delay:1] autorelease];
        [carManager performSelectorInBackground:@selector(start) withObject:nil];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
    
    return 0;
}
