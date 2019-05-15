//
//  CardTester.cpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

#include "CardTester.hpp"

#include <assert.h>
#include <string>

void CardTester::testCardCreation()
{
    // Create 4 Cards with different suits and ranks.
    Card lCard1(Hearts, Ace);
    Card lCard2(Spades, Two);
    Card lCard3(Diamonds, Three);
    Card lCard4(Clubs, King);
    
    // Check if the Cards are created corrected by retrieving their content as a string.
    ASSERT_WITH_MESSAGE(lCard1.getCardStr() == "0.0", "Card creation error: Hearts, Ace\n");
    ASSERT_WITH_MESSAGE(lCard2.getCardStr() == "1.1", "Card creation error: Spades, Two\n");
    ASSERT_WITH_MESSAGE((lCard3.getCardStr() == "2.2"), "Card creation error: Diamonds, Three\n");
    ASSERT_WITH_MESSAGE((lCard4.getCardStr() == "3.12"), "Card creation error: Clubs, King\n");
}

void CardTester::testCardValue()
{
    // Create 4 Cards with different suits and ranks.
    Card lCard1(Hearts, Ace);
    Card lCard2(Spades, Two);
    Card lCard3(Diamonds, Three);
    Card lCard4(Clubs, King);
    
    // Retrieve the Cards'properties and x-check with creation papameters.
    ASSERT_WITH_MESSAGE(((lCard1.getSuit() == Hearts) && (lCard1.getRank() == Ace)), "Card value error: Hearts, Ace\n");
    ASSERT_WITH_MESSAGE(((lCard2.getSuit() == Spades) && (lCard2.getRank() == Two)), "Card value error: Spades, Two\n");
    ASSERT_WITH_MESSAGE(((lCard3.getSuit() == Diamonds) && (lCard3.getRank() == Three)), "Card value error: Diamonds, Three\n");
    ASSERT_WITH_MESSAGE(((lCard4.getSuit() == Clubs) && (lCard4.getRank() == King)), "Card value error: Clubs, King\n");
}

void CardTester::testCardComparison()
{
    // Create 6 Cards for different cases:
    // 1. Same suit, different ranks
    Card lCard1(Hearts, Ace);
    Card lCard2(Hearts, Two);
    
    // 2. Different suits, same rank
    Card lCard3(Diamonds, Three);
    Card lCard4(Clubs, Three);
    
    // 3. Same suit, same rank
    Card lCard5(Spades, Four);
    Card lCard6(Spades, Four);
    
    // Check to see if the operators are functioning as expected for the 3 cases.
    // We skip the case of different rank, different suit as it should be covered already.
    ASSERT_WITH_MESSAGE(lCard1!=lCard2, "Card comparision error: (Hearts, Ace) and (Hearts, Two)\n");
    ASSERT_WITH_MESSAGE(lCard3!=lCard4, "Card comparision error: (Diamonds, Three) and (Clubs, Three)\n");
    ASSERT_WITH_MESSAGE(lCard5==lCard6, "Card comparision error: (Spades, Four) and (Spades, Four)\n");
}
