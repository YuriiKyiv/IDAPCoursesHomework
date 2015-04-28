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
    __block NSArray *filteredArray = nil;
    
    context(@"when creating object of TYVEmployeesPool", ^{
        
        beforeAll(^{
            employeesPool = [[TYVEmployeesPool alloc] init];
        });
        
        it(@"should not be nil", ^{
            [[employeesPool shouldNot] beNil];
        });
        
        it(@"should have count equls 0", ^{
            [[theValue([employeesPool count]) should] equal:theValue(0)];
        });
        
    });
    
    context(@"when adding one object", ^{
        
        beforeAll(^{
            employeesPool = [[TYVEmployeesPool alloc] init];
            employee = [[TYVEmployee alloc] init];
            [employeesPool addEmployee:employee];
        });
        
        it(@"should contains object", ^{
            [[theValue([employeesPool containsEmployee:employee]) should] beYes];
        });
        
        it(@"should have count equls 1", ^{
            [[theValue([employeesPool count]) should] equal:theValue(1)];
        });
        
    });
    
    context(@"when filtering array", ^{
        
        beforeAll(^{
            employeesPool = [[TYVEmployeesPool alloc] init];
            for (int i = 0; i < 100; i++) {
                employee = [[TYVEmployee alloc] init];
                if (i % 2 == 0) {
                    employee.free = NO;
                }
                
                [employeesPool addEmployee:employee];
            }
            
            filteredArray = [[employeesPool freeEmployeesWithClass:[TYVEmployee class]] copy];
        });
        
        it(@"should have count equls 100", ^{
            [[theValue([employeesPool count]) should] equal:theValue(100)];
        });
        
        it(@"should have count equls 50", ^{
            [[theValue([filteredArray count]) should] equal:theValue(50)];
        });
        
    });
});

SPEC_END