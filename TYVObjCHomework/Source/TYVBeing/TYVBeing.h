//
//  TYVBeing.h
//  IDAPCoursesHomework
//
//  Created by YURII on 10.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum TYVGender TYVGender;
enum TYVGender {
    TYVMaleGender,
    TYVFemaleGender
};

@interface TYVBeing : NSObject

@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, copy, readonly)   NSArray     *chidren;

@property (nonatomic, assign, readonly) TYVGender   gender;
@property (nonatomic, assign, readonly) uint8_t     weight;
@property (nonatomic, assign, readonly) uint8_t     age;

- (void)fight;

- (TYVBeing *)giveBirth;

- (void)addChild:(TYVBeing *)aChild;

- (void)removeChild:(TYVBeing *)aChild;

- (void)sayHi;

@end
