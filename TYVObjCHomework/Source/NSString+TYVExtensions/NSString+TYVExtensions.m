//
//  NSString+TYVExtensions.m
//  IDAPCoursesHomework
//
//  Created by YURII on 30.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "NSString+TYVExtensions.h"

static const NSUInteger kNSStringDefaultRandomStringLength  = 25;

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

+ (instancetype)сyrillicSymbols {
    NSRange range = {0x0400, 0x04FF - 0x0400 + 1};
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet {
    NSMutableString *result = [NSMutableString stringWithCapacity:length];
    NSUInteger alphabetLength = [alphabet length];
    for (NSUInteger i = 0; i < length; i++) {
        unichar randomChar = [alphabet characterAtIndex:arc4random_uniform((u_int32_t)alphabetLength)];
        [result appendFormat:@"%c", randomChar];
    }
    
    return [self stringWithString:result];
}

+ (instancetype)randomString {
    return [self randomStringWithLength:kNSStringDefaultRandomStringLength alphabet:[self letterAlphabet]];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length alphabet:[self letterAlphabet]];
}

@end
