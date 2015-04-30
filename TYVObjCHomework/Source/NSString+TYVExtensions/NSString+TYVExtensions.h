//
//  NSString+TYVExtensions.h
//  IDAPCoursesHomework
//
//  Created by YURII on 30.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TYVExtensions)

+ (instancetype)alphabetWithUnicodeRange:(NSRange)range;

+ (instancetype)capitalizedLetterAlphabet;

+ (instancetype)lowercaseLetterAlphabet;

+ (instancetype)numericAlphabet;

+ (instancetype)letterAlphabet;

+ (instancetype)сyrillicSymbols;

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet;

+ (instancetype)randomString;

+ (instancetype)randomStringWithLength:(NSUInteger)length;

@end
