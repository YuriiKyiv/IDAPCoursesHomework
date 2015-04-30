//
//  NSString+TYVExtensions.m
//  IDAPCoursesHomework
//
//  Created by YURII on 30.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "NSString+TYVExtensions.h"

@implementation NSString (TYVExtensions)

+ (instancetype)alphabetWithUnicodeRange:(NSRange)range {
    NSMutableString *result = [NSMutableString string];
    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        [result appendFormat:@"%c",character];
    }
    
    return [self stringWithString:result];
}

+ (instancetype)capitalizedLetterAlphabet {
    NSRange range = {'A', 26};
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)lowercaseLetterAlphabet {
    NSRange range = {'a', 26};
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)numericAlphabet {
    NSRange range = {'0', 10};
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)letterAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self lowercaseLetterAlphabet]];
    [result appendString:[self capitalizedLetterAlphabet]];
    
    return [self stringWithString:result];
    
}

@end
