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
@property (nonatomic, copy, readonly)   NSArray     *children;

@property (nonatomic, assign, readonly) uint8_t     weight;
@property (nonatomic, assign, readonly) uint8_t     age;

- (instancetype) initWithName:(NSString *)name age:(uint8_t)age;

- (void)addChild:(TYVBeing *)aChild;

- (void)removeChild:(TYVBeing *)aChild;

- (void)sayHi;

- (void)performGenderSpecificOperation;

@end
