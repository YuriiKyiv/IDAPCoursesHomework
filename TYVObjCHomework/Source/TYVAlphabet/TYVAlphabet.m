//
//  TYVAlphabet.m
//  IDAPCoursesHomework
//
//  Created by YURII on 09.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAlphabet.h"
#import "TYVRangeAlphabet.h"
#import "TYVClasterAlphabet.h"
#import "TYVStringsAlphabet.h"

@implementation TYVAlphabet

#pragma mark -
#pragma mark Class methods

+ (instancetype)alphabetWithRange:(TYVRange *)range;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithAlphabets:(TYVRange *)alphabets;
+ (instancetype)alphabetWithSimbols:(NSString *)string;

@end
