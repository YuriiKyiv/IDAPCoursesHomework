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
    return [self alphabetWithStrings:[string symbols]];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(TYVRange *)range {
    [self release];
    return [[TYVRangeAlphabet alloc] initWithRange:range];
}

- (instancetype)initWithStrings:(NSArray *)strings {
    [self release];
    return [[TYVStringsAlphabet alloc] initWithStrings:strings];
}

- (instancetype)initWithAlphabets:(TYVRange *)alphabets {
    [self release];
    return [[TYVClasterAlphabet alloc] initWithAlphabets:alphabets];
}

- (instancetype)initWithSimbols:(NSString *)string {
    return [self initWithSimbols:string];
}

#pragma mark -
#pragma mark NSFastEnumeration methods

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len {
    return 0;
}

@end
