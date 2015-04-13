//
//  main.m
//  TYVObjCHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVBeing.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        TYVBeing *beingOne = [[[TYVBeing alloc] initWithName:@"beingOne" age:100 gender:TYVMaleGender] autorelease];
        TYVBeing *beingTwo = [[[TYVBeing alloc] initWithName:@"beingOne" age:50 gender:TYVFemaleGender] autorelease];
        NSArray *beingArray = [[[NSArray alloc] initWithObjects:beingOne, beingTwo, nil] autorelease];
        for (int i = 0; i < 10; i++) {
            [beingOne addChild:[[[TYVBeing alloc] initWithName:@"name1" age:i gender:i % 2] autorelease]];
            [beingTwo addChild:[[[TYVBeing alloc] initWithName:@"name2" age:i gender:i + 1 % 2] autorelease]];
        }
        
        for (TYVBeing *being in beingArray) {
            if ([being gender] == TYVMaleGender) {
                [being fight];
            } else {
                [being giveBirth];
            }
        }
    }
    
    return 0;
}
