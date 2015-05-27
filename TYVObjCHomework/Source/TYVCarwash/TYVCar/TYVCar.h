//
//  TYVCar.h
//  IDAPCoursesHomework
//
//  Created by YURII on 15.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVMoneyKeeper.h"

@interface TYVCar : TYVMoneyKeeper
@property (atomic, assign, getter=isClean)   BOOL    clean;

@end
