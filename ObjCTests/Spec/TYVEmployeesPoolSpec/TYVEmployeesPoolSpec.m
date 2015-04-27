//
//  TYVEmployeesPoolSpec.m
//  IDAPCoursesHomework
//
//  Created by YURII on 25.04.15.
//  Copyright (c) 2015 YURII. All rights reserved.
//

#import "Kiwi.h"
#import "TYVEmployeesPool.h"
#import "TYVEmployee.h"

SPEC_BEGIN(TYVEmployeesPoolSpec)

//- (void) addEmployee:(TYVEmployee *)anEmployee;
//
//- (void) removeEmployee:(TYVEmployee *)anEmployee;
//
//- (TYVEmployee *) freeEmployeeWithClass:(Class)class;
//
//- (NSArray *) freeEmployeesWithClass:(Class)class;
//
//- (NSArray *) employeesWithClass:(Class)class;
//
//- (BOOL) containsEmployee:(TYVEmployee *)anEmployee;
//
//- (NSUInteger) count;


describe(@"TYVEmployeesPool", ^{
    
    __block TYVEmployeesPool *employeesPool = nil;
    __block TYVEmployee *employee = nil;
    
    beforeAll(^{
        employeesPool = [[[TYVEmployeesPool alloc] init] autorelease];
        employee = [[[TYVEmployee alloc] init] autorelease];
    });
    
    context(@"when creating object of TYVEmployeesPool", ^{
        
        it(@"should not be nil", ^{
            [[employeesPool shouldNot] beNil];
        });
        
        it(@"should have count equls 0", ^{
            [[theValue([employeesPool count]) should] equal:theValue(0)];
        });
        
    });
    
    context(@"when adding one object", ^{
        
//        beforeAll(^{
//            [employeesPool addEmployee:employee];
//        });
        
        it(@"should contains object", ^{
            [theValue([employeesPool containsEmployee:employee]) beYes];
        });
        
        it(@"should have count equls 1", ^{
            [[theValue([employeesPool count]) should] equal:theValue(1)];
        });
        
    });
});

SPEC_END