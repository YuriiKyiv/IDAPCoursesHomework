//
//  TYVAlphabet.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TYVRange;

@interface TYVAlphabet : NSObject <NSFastEnumeration>

+ (instancetype)alphabetWithRange:(TYVRange *)range;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithAlphabets:(TYVRange *)alphabets;
+ (instancetype)alphabetWithSimbols:(NSString *)string;

@end
