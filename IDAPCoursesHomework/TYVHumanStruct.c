////
////  TYVHumanStruct.c
////  IDAPCoursesHomework
////
////  Created by YURII on 17.02.15.
////  Copyright (c) 2015 YURII. All rights reserved.
////
//
//#include "TYVHumanStruct.h"
//#include "stdlib.h"
//#include "stdbool.h"
//
//#pragma mark -
//#pragma mark Private Declarations
//
//static
//void TYVHumanDealloc(TYVHuman *human);
//
//static
//void TYVHumanSetMerriedStatus(TYVHuman *human, TYVMarriedStatus status);
//
//static
//void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner);
//
//static
//void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother);
//
//static
//void TYVHumanSetFather(TYVHuman *human, TYVHuman *father);
//
//#pragma mark -
//#pragma mark Public Implementations
//
//TYVHuman *TYVHumanCreate(TYVName *name, unsigned int age, TYVGender gender, TYVMarriedStatus married){
//    TYVHuman *human = malloc(sizeof(*human));
//    human->_referenceCount = 1;   
//    TYVNameRetain(name);
//    human->_name = name;
//    human->_age = age;
//    human->_gender = gender;
//    human->_married = married;
//    
//    human->_mother = NULL;
//    human->_father = NULL;
//    human->_partner = NULL;
//    
//    return human;
//}
//
//void TYVHumanRetain(TYVHuman *human){
//    human->_referenceCount++;
//}
//
//void TYVHumanRelease(TYVHuman *human){
//    human->_referenceCount--;
//    if (0 == human->_referenceCount){
//        TYVHumanDealloc(human);
//    }
//}
//
//TYVName *TYVHumanGetName(TYVHuman *human){
//    return human->_name;
//}
//
//unsigned int TYVHumanGetAge(TYVHuman *human){
//    return human->_age;
//}
//
//void TYVHumanSetAge(TYVHuman *human, unsigned int age){
//    human->_age = age;
//}
//
//TYVGender TYVHumanGetGender(TYVHuman *human){
//    return human->_gender;
//}
//
//TYVMarriedStatus TYVHumanGetMerriedStatus(TYVHuman *human){
//    return human->_married;
//}
//
//TYVHuman *TYVHumanGetPartner(TYVHuman *human){
//    return human->_partner;
//}
//
//TYVHuman *TYVHumanGetMather(TYVHuman *human){
//    return human->_mother;
//}
//
//TYVHuman *TYVHumanGetFather(TYVHuman *human){
//    return human->_father;
//}
//
//void TYVHunamGetMarried(TYVHuman *male, TYVHuman *female){
//    if ((TYVHumanGetGender(male) != TYVHumanGetGender(female)) &&
//        ((TYVHumanGetMerriedStatus(male) == TYVNo) && (TYVHumanGetMerriedStatus(female)) == TYVNo) ) {
//        TYVHumanRetain(male);
//        TYVHumanRetain(female);
//        TYVHumanSetPartner(male, female);
//        TYVHumanSetPartner(female, male);
//        TYVHumanSetMerriedStatus(male, TYVYes);
//        TYVHumanSetMerriedStatus(female, TYVYes);
//    }
//}
//
//bool TYVHumanIsSamePartners(TYVHuman *male, TYVHuman *female){
//    TYVHuman *malePartner = TYVHumanGetPartner(male);
//    TYVHuman *femalePartner = TYVHumanGetPartner(female);
//    if ((malePartner == female) && (femalePartner == male)) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//bool TYVHumanIsDifferentGender(TYVHuman *male, TYVHuman *female){
//    return (TYVHumanGetGender(male) != TYVHumanGetGender(female));
//}
//
//void TYVHumanDivorce(TYVHuman *male, TYVHuman *female){
//    if (TYVHumanIsSamePartners(male, female)) {
//        TYVHumanSetPartner(male, NULL);
//        TYVHumanSetPartner(female, NULL);
//        TYVHumanSetMerriedStatus(male, TYVNo);
//        TYVHumanSetMerriedStatus(female, TYVNo);
//        TYVHumanRelease(male);
//        TYVHumanRelease(female);
//    }
//}
//
//TYVHuman *TYVHumanMakeChildren(TYVHuman *male, TYVHuman *female, TYVName *name, unsigned int age, TYVGender gender){
//    TYVHuman *human = NULL;
//    if (TYVHumanIsSamePartners(male, female) && TYVHumanIsDifferentGender(male, female)) {
//        TYVMarriedStatus married = TYVNo;
//        TYVHuman *human = TYVHumanCreate(name, age, gender, married);
//        if (TYVmale == TYVHumanGetGender(male)) {
//            TYVHumanSetMother(human, female);
//            TYVHumanSetFather(human, male);
//        } else {
//            TYVHumanSetMother(human, male);
//            TYVHumanSetFather(human, female);
//        }
//        
//        TYVHumanRetain(male);
//        TYVHumanRetain(male);
//    }
//    
//    //TODO make connection with the children array and retain
//    
//    return human;
//}
//
//#pragma mark -
//#pragma mark Private Implementations
//
//void TYVHumanDealloc(TYVHuman *human){
//    if (NULL != human->_name){
//        TYVNameRelease(human->_name);
//    }
//    
//    if (TYVYes == TYVHumanGetMerriedStatus(human)){
//        TYVHuman *partner = TYVHumanGetPartner(human);
//        TYVHumanSetPartner(partner, NULL);
//        TYVHumanSetMerriedStatus(partner, TYVNo);
//        TYVHumanRelease(partner);
//    }
//    
//    TYVHuman *father = TYVHumanGetFather(human);
//    TYVHuman *mother = TYVHumanGetMather(human);
//    if (NULL != father){
//        TYVHumanRelease(father);
//    }
//    if (NULL != mother){
//        TYVHumanRelease(mother);
//    }
//    
//    // TODO write for children;
//    
//    free(human);
//}
//
//void TYVHumanSetMerriedStatus(TYVHuman *human, TYVMarriedStatus status){
//    human->_married = status;
//}
//
//void TYVHumanSetPartner(TYVHuman *human, TYVHuman *partner){
//    human->_partner = partner;
//}
//
//void TYVHumanSetMother(TYVHuman *human, TYVHuman *mother){
//    human->_mother = mother;
//}
//
//void TYVHumanSetFather(TYVHuman *human, TYVHuman *father){
//    human->_father = father;
//}
