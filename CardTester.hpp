//
//  CardTester.hpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

//  Class Name : CardTester
//
//  Description: Testing class for Card class.
//  1. testCardCreation will check if the Card created will have the right suit and rank.
//  2. testCardValue will check if the correct value of suit and rank can be retrieved.
//  3. testCardComparison will test the == and != operators.
//  Several hardcoded cases will be tested in each test.
//

#ifndef CardTester_hpp
#define CardTester_hpp

#define ASSERT_WITH_MESSAGE(condition, message) do { \
if (!(condition)) { printf((message)); } \
assert ((condition)); } while(false)

#include <stdio.h>

#include "Card.hpp"

class CardTester{
public:
    void testCardCreation();
    void testCardValue();
    void testCardComparison();
};

#endif /* CardTester_hpp */
