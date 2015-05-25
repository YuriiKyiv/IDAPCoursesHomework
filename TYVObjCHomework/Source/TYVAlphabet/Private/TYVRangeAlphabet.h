//
//  TYVRangeAlphabet.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.05.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "TYVAlphabet.h"

@interface TYVRangeAlphabet : TYVAlphabet
@property (nonatomic, readonly) TYVRange    *range;

- (instancetype)initWithRange:(TYVRange *)range;

@end
