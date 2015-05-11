//
//  NSString+TYVExtensions.m
//  IDAPCoursesHomework
//
//  Created by YURII on 30.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "NSString+TYVExtensions.h"
#import "TYVRange.h"

static const NSUInteger kNSStringDefaultRandomStringLength  = 25;

@implementation NSString (TYVExtensions)

+ (instancetype)alphabetWithUnicodeRange:(TYVRange *)range {
    NSMutableString *result = [NSMutableString string];
    for (unichar character = range.origin; character < range.end; character++) {
        [result appendFormat:@"%c",character];
    }
    
    return [self stringWithString:result];
}

+ (instancetype)capitalizedLetterAlphabet {
    TYVRange *range = [TYVRange rangeWithOrigin:'A' end:'Z'];
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)lowercaseLetterAlphabet {
    TYVRange *range = [TYVRange rangeWithOrigin:'a' end:'z'];
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)numericAlphabet {
    TYVRange *range = [TYVRange rangeWithOrigin:'0' end:'10'];
    return [self alphabetWithUnicodeRange:range];
}

+ (instancetype)letterAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self lowercaseLetterAlphabet]];
    [result appendString:[self capitalizedLetterAlphabet]];
    
    return [self stringWithString:result];
    
}

+ (instancetype)сyrillicSymbols {
    TYVRange *range = [TYVRange rangeWithOrigin:0x0400 end:0x04FF];
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

- (NSArray *)symbols {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:[self length]];
    
    NSUInteger length = [self length];
    for (NSUInteger index = 0; index < length; index++) {
        unichar randomChar = [self characterAtIndex:index];
        [result addObject:[NSString stringWithFormat:@"%c", randomChar]];
    }
    
    return [[result copy] autorelease];
}

@end
