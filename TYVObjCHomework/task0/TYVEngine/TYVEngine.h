//
//  TYVEngine.h
//  IDAPCoursesHomework
//
//  Created by YURII on 09.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TYVEngineProtocol.h"

typedef enum TYVTypeOfEngine TYVTypeOfEngine;
enum TYVTypeOfEngine {
    TYVDieselEngine,
    TYVJetEngine
};

@interface TYVEngine : NSObject <TYVEngineProtocol>

@property (nonatomic, assign, getter=getType, setter=setType:) TYVTypeOfEngine engineType;

@property (nonatomic, assign, getter=isWorking) BOOL isWorking;

+ (instancetype)newEngineWithType: (TYVTypeOfEngine) engineType;

- (void)start;

- (void)stop;

@end
