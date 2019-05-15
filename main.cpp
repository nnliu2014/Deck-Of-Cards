//
//  main.cpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

// Assignment Description
//
// Implement a set of classes that represent a deck of poker-style paying cards.
// (Fifty-two playing cards in four suits: hearts, spades, clubs, diamonds with
// face value of Ace, 2-10, Jack, Queen and King.)
//
// Within one of your classes, two operations need to be provided:
// 1. shuffle() which returns no value, but results in the cards in the deck
// being randomly permuted.
//
// 2. dealOneCard() which return one card from the deck to the caller.
// Specifically, a call to shuffle followed by 52 calls to dealOneCard() should
// result in the caller being provided all 52 cards of the deck in a random order.
// If the caller then makes a 53rd call dealOneCard(), no card is dealt.

#include <iostream>

// Testing classes for Card and Deck
#include "CardTester.hpp"
#include "DeckTester.hpp"

// Following flags can be used to toggle the tests.
#define TEST_CARD
#define TEST_DECK

// main() serves as the unit tests executor for this assignment.
// The program will stop at assertion failures.
// For details of each classes and their tester classes, please check
// README.md
// Card.hpp, Deck.hpp
// CardTester.hpp and DeckTester.hpp.

int main(int argc, const char * argv[]) {
    
    CardTester lCardTester;
    DeckTester lDeckTester;
    
#ifdef TEST_CARD
    lCardTester.testCardCreation();
    std::cout<<"Card Creation Test passed\n";
    
    lCardTester.testCardValue();
    std::cout<<"Card Value Test passed\n";
    
    lCardTester.testCardComparison();
    std::cout<<"Card Comparison Test passed\n";
#endif
    
#ifdef TEST_DECK
    lDeckTester.testDeckCreation();
    std::cout<<"Deck Creation Test passed\n";
    
    lDeckTester.testDeckInitialShuffle();
    std::cout<<"Deck Initial Shuffle Test passed\n";
    
    lDeckTester.testDeckShuffleRandomness();
    std::cout<<"Deck Shuffle Randomness Test passed\n";
    
    lDeckTester.testMultipleDeckShuffle();
    std::cout<<"Multiple Deck Shuffle Test passed\n";
    
    lDeckTester.testDeckShuffleAfterDealing();
    std::cout<<"Deck Shuffle After Dealing Test passed\n";
    
    lDeckTester.testDealOneCard();
    std::cout<<"Deck Deal One Card Test passed\n";
    
    lDeckTester.testDealCards();
    std::cout<<"Deck Deal Cards Test passed\n";
    
    lDeckTester.testDealEmptyDeck();
    std::cout<<"Deal Empty Deck Test passed\n";
#endif
    
    std::cout<<"All Tests completed!\n";
    return 0;
}

