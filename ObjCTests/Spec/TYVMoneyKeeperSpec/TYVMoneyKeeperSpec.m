//
//  TYVMoneyKeeperSpec.m
//  IDAPCoursesHomework
//
//  Created by YURII on 24.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "Kiwi.h"

#import "TYVMoneyKeeper.h"

SPEC_BEGIN(TYVMoneyKeeperSpec)

describe(@"ClassName", ^{
    
    __block TYVMoneyKeeper *moneyKeeperOne = nil;
    __block TYVMoneyKeeper *moneyKeeperTwo = nil;
    
    context(@"when create object of TYVMoneyKeeper", ^{
        
        beforeAll(^{
            moneyKeeperOne = [[[TYVMoneyKeeper alloc] init] autorelease];
            moneyKeeperTwo = [[[TYVMoneyKeeper alloc] init] autorelease];
        });
        
        it(@"should be objects of TYVMoneyKeeper class", ^{
            [[moneyKeeperOne should] beKindOfClass:[TYVMoneyKeeper class]];
            [[moneyKeeperTwo should] beMemberOfClass:[TYVMoneyKeeper class]];
        });
        
        it(@"should have 0 value of money", ^{
            [[moneyKeeperOne.money should] equal:[NSDecimalNumber zero]];
            [[moneyKeeperTwo.money should] equal:[NSDecimalNumber zero]];
        });

    });
});

SPEC_END