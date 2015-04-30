//
//  NSString+TYVExtensionsSpec.m
//  IDAPCoursesHomework
//
//  Created by YURII on 30.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "Kiwi.h"

#import "NSString+TYVExtensions.h"

SPEC_BEGIN(NSStringTYVExtensionsSpec)




describe(@"NSString+TYVExtensionsSpec", ^{
    
    __block NSString *alphabet = nil;
    
    context(@"when initialized with +alphabetWithUnicodeRange: with range = {'B', 2}", ^{
        
        beforeAll(^{
            NSRange range = {'B', 2};
            alphabet = [NSString alphabetWithUnicodeRange:range];
        });
        
        it(@"should be NSString", ^{
            [[alphabet should] beKindOfClass:[NSString class]];
        });
        
        it(@"should have count 2", ^{
            [[theValue([alphabet length]) should] equal:theValue(2)];
        });
        
        it(@"should equal \"BC\" ", ^{
            [[alphabet should] equal:@"BC"];
        });

    });
    
    context(@"when initialized with +сyrillicSymbols", ^{
        
        beforeAll(^{
            alphabet = [NSString сyrillicSymbols];
        });
        
        it(@"should be NSString", ^{
            [[alphabet should] beKindOfClass:[NSString class]];
        });
        
    });

});

SPEC_END