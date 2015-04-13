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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSMutableArray *array = [[[NSMutableArray alloc] init] autorelease];
        TYVBeing *being = NULL;
        for(int i = 0; i < 1000; i++) {
            if (i % 2 == 0) {
                being = [[[TYVMaleBeing alloc] init] autorelease];
            } else {
                being = [[[TYVFemaleBeing alloc] init] autorelease];
            }
            
            [array addObject:being];
        }
        
        for (TYVBeing *being in array) {
            [being performGenderSpecificOperation];
        }
    }
    
    return 0;
}
