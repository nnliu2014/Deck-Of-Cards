//
//  DeckTester.hpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

//  Class Name : DeckTester
//
//  Description: Testing class for Deck class.
//  1. testDeckCreation will check if a new Deck has all the Cards created correctly.
//  2. testInitialShuffle will check:
//      a. a permutation is done
//      b. no duplicated Cards
//      Correctness of the Cards is not checked since only the contructor can create Cards.
//  3. testDeckShuffleRandomness will check if multiple calls to shuffle() will generate different
//     random permutations. This is to ensure the fairness of the game.
//  4. testMultipleDeckShuffle will check if shuffle calls to multiple Decks will generate different
//     random permutations. This is also to ensure the fairness of the game.
//  5. testDealOneCard will test the case of dealing from a fresh Deck and a Deck after one shuffle
//     call.
//  6. testDealCards will test the case where several Cards are dealt continuously.
//  7. testDealEmptyDeck will test the case when dealOneCard() is called when the Deck is empty.
//  8. testShuffleAfterDealing will test the case when shuffle() is called on a partial Deck.
//
//  As explained in Deck.hpp, thread saftey is not tested in these test cases.

#ifndef DeckTester_hpp
#define DeckTester_hpp

#include <stdio.h>

#include "Deck.hpp"

#ifndef ASSERT_WITH_MESSAGE
#define ASSERT_WITH_MESSAGE(condition, message) do { \
if (!(condition)) { printf((message)); } \
assert ((condition)); } while(false)
#endif

class DeckTester{
public:
    // Test if a new Deck has the expected order and number of Cards.
    void testDeckCreation();
    
    // Test if the initial shuffle will create a permutation of Cards correctly.
    void testDeckInitialShuffle();
    
    // Shuffle the same Deck many times to see if a same order of Card is produced.
    void testDeckShuffleRandomness();
    
    // Shuffle multiple Decks to see if a same order of Card is produced.
    void testMultipleDeckShuffle();
    
    // Test dealing of one Card.
    void testDealOneCard();
    
    // Test dealing of multiple Cards continuously.
    void testDealCards();
    
    // Test the returned Card when dealOneCard is called on an empty Deck.
    void testDealEmptyDeck();
    
    // Test the shuffling after some Cards are dealt.
    void testDeckShuffleAfterDealing();
};

#endif /* DeckTester_hpp */
