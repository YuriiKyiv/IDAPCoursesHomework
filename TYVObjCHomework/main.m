//
//  main.m
//  TYVObjCHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVCar.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        TYVCar *car = [[TYVCar new] autorelease];
        TYVEngine *engine = [TYVEngine newEngineWithType:TYVJetEngine];
        [car setEngine:engine];
    }
    
    return 0;
}
