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
#import "TYVWasher.h"

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
    __block TYVWasher *washer = nil;
    __block NSSet *filteredSet = nil;
    
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
    
    context(@"when adding object of TYVEmployee with ", ^{
        
        beforeAll(^{
            employeesPool = [[TYVEmployeesPool alloc] init];
            employee = [[TYVEmployee alloc] initWithDuty:@"work1"
                                                  salary:[NSDecimalNumber decimalNumberWithString:@"100"]
                                                   money:[NSDecimalNumber decimalNumberWithString:@"100"]];
            [employeesPool addEmployee:employee];
        });
        
        it(@"should contains employee", ^{
            [[theValue([employeesPool containsEmployee:employee]) should] beYes];
        });
        
        it(@"should have count equls 0", ^{
            [[theValue([employeesPool count]) should] equal:theValue(1)];
        });
        
    });

});

SPEC_END