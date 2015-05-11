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

#import "NSString+TYVExtensions.h"

@implementation TYVAlphabet

#pragma mark -
#pragma mark Class methods

+ (instancetype)alphabetWithRange:(TYVRange *)range {
    return [[[TYVRangeAlphabet alloc] initWithRange:range] autorelease];
}

+ (instancetype)alphabetWithStrings:(NSArray *)strings {
    return [[TYVStringsAlphabet alloc] initWithStrings:strings];
}

+ (instancetype)alphabetWithAlphabets:(TYVRange *)alphabets {
    return [[[TYVClasterAlphabet  alloc] initWithAlphabets:alphabets] autorelease];
}

+ (instancetype)alphabetWithSimbols:(NSString *)string {
    return [[[TYVStringsAlphabet alloc] initWithStrings:[string symbols]] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (instancetype)initWithRange:(TYVRange *)range {
    return nil;
}

- (instancetype)initWithStrings:(NSArray *)strings {
    return nil;
}

- (instancetype)initWithAlphabets:(TYVRange *)alphabets {
    return nil;
}

- (instancetype)initWithSimbols:(NSString *)string {
    return nil;
}

#pragma mark -
#pragma mark NSFastEnumeration methods

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len {
    return 0;
}

@end
