//
//  TYVCarwashEnterprise.h
//  IDAPCoursesHomework
//
//  Created by YURII on 16.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYVCarwashBuilding.h"
#import "TYVBuilding.h"

@interface TYVCarwashEnterprise : NSObject

@property (nonatomic, readonly)    TYVCarwashBuilding    *carwashBuilding;
@property (nonatomic, readonly)    TYVBuilding           *building;

- (void)hirePersonal;

@end
