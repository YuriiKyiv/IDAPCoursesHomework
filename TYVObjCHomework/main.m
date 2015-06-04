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
        
        TYVCarManager *carManager = [[[TYVCarManager alloc] initWithEnterprise:enterprise
                                                                   carCapacity:50
                                                                         delay:1] autorelease];
        [carManager performSelectorInBackground:@selector(start) withObject:nil];
        
//        TYVWasher *washer = [TYVWasher object];
//        TYVAccountant *accountant = [TYVAccountant object];
//        TYVDirector *director = [TYVDirector object];
//        
//        [washer addObserver:accountant];
//        [accountant addObserver:director];
//        
//        [washer performWorkWithObject:[TYVCar object]];
//        
//        TYVCarManager *carWasher = [[[TYVCarManager alloc] initWithWasher:washer carCapacity:10 delay:1] autorelease];
//        
//        [carWasher performSelectorInBackground:@selector(startWithWasher) withObject:nil];
        
//        sleep(10);
//        
//        carManager.cancel = YES;
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
    
    return 0;
}
