//
//  DeckTester.cpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

#include "DeckTester.hpp"

#include <assert.h>
#include <string>
#include <set>

// Define the number of shuffles and Decks to be used when testing shuffle randomness.
#define NUM_OF_SHUFFLES 50
#define NUM_OF_DECKS 50

// Test if a new Deck has the expected order and number of Cards.
void DeckTester::testDeckCreation(){
    // This is the expected result when a new Deck is created.
    std::string cleanDeckStr = "3.12 3.11 3.10 3.9 3.8 3.7 3.6 3.5 3.4 3.3 3.2 3.1 3.0 2.12 2.11 2.10 2.9 2.8 2.7 2.6 2.5 2.4 2.3 2.2 2.1 2.0 1.12 1.11 1.10 1.9 1.8 1.7 1.6 1.5 1.4 1.3 1.2 1.1 1.0 0.12 0.11 0.10 0.9 0.8 0.7 0.6 0.5 0.4 0.3 0.2 0.1 0.0";
    
    // Create a new Deck and get its content as a string.
    Deck lDeck;
    std::string lDeckStr;
    lDeck.getDeckStr(lDeckStr);
    
    // Check the newly created Deck against the expected result.
    ASSERT_WITH_MESSAGE((cleanDeckStr.compare(lDeckStr)== 0), "Deck creation error!\n");
}

// Test if the initial shuffle will create a permutation of Cards correctly.
void DeckTester::testDeckInitialShuffle(){
    // This is the expected string for a new Deck.
    std::string cleanDeckStr = "3.12 3.11 3.10 3.9 3.8 3.7 3.6 3.5 3.4 3.3 3.2 3.1 3.0 2.12 2.11 2.10 2.9 2.8 2.7 2.6 2.5 2.4 2.3 2.2 2.1 2.0 1.12 1.11 1.10 1.9 1.8 1.7 1.6 1.5 1.4 1.3 1.2 1.1 1.0 0.12 0.11 0.10 0.9 0.8 0.7 0.6 0.5 0.4 0.3 0.2 0.1 0.0";
    
    // Create a new Deck and shuffle it.
    Deck lDeck;
    lDeck.shuffle();
    
    // Test Shuffle Step 1 : different than a clean Deck
    std::string lDeckStr;
    lDeck.getDeckStr(lDeckStr);
    
    // Failed if two strings are the same.
    ASSERT_WITH_MESSAGE((cleanDeckStr.compare(lDeckStr)!= 0), "Deck not shuffled!\n");
    
    // Test Shuffle Step 2 : correct number of Cards;
    ASSERT_WITH_MESSAGE((lDeck.getSize() == (NUM_OF_RANK*NUM_OF_SUIT)), "Wrong number of Cards after shuffle!\n");
    
    // Test Shuffle Step 3: no repeating elements
    std::set<std::string> lCardSet;
    std::pair<std::set<std::string>::iterator,bool> lRet;
    
    for(int i = 0; i<(NUM_OF_RANK*NUM_OF_SUIT); i++)
    {
        std::string lCardStr;
        std::unique_ptr<Card> lDealtCard = lDeck.dealOneCard();
        ASSERT_WITH_MESSAGE(lDealtCard.get(), "Dealt empty card when deck is not empty!\n");
        
        // lRet.second will be false if the element already exists in the set.
        lRet = lCardSet.insert(lDealtCard->getCardStr());
        ASSERT_WITH_MESSAGE((lRet.second), "Duplicate Card after shuffle!\n");
    }
}

// Shuffle the same Deck many times to see if a same order of Card is produced.
void DeckTester::testDeckShuffleRandomness(){
    // Create a new Deck
    Deck lDeck;
    
    std::string lDeckStr;
    std::set<std::string> lDeckStrSet;
    std::pair<std::set<std::string>::iterator,bool> lRet;
    
    // Shuffle the same Deck again and again and check for duplication.
    for(int i = 0; i<NUM_OF_SHUFFLES; i++)
    {
        // Shuffle the Deck and then retrieve its content as a string.
        lDeck.shuffle();
        lDeck.getDeckStr(lDeckStr);
        
        // lRet.second will be false if the same string already exists in the set.
        lRet = lDeckStrSet.insert(lDeckStr);
        ASSERT_WITH_MESSAGE((lRet.second), "Duplicate Card order within multiple shuffles.\n");
        
        lDeckStr.clear();
    }
}

// Shuffle multiple Decks to see if a same order of Card is produced.
void DeckTester::testMultipleDeckShuffle(){
    // Create a number of Decks
    Deck lDecks[NUM_OF_DECKS];
    
    std::string lDeckStr;
    std::set<std::string> lDeckStrSet;
    std::pair<std::set<std::string>::iterator,bool> lRet;
    
    // Shuffle the each Deck and check for duplication.
    for(int i = 0; i<NUM_OF_DECKS; i++)
    {
        // Shuffle the Deck and then retrieve its content as a string.
        lDecks[i].shuffle();
        lDecks[i].getDeckStr(lDeckStr);
        
        // lRet.second will be false if the same string already exists in the set.
        lRet = lDeckStrSet.insert(lDeckStr);
        ASSERT_WITH_MESSAGE((lRet.second), "Duplicate Card order within multiple decks.\n");
        
        lDeckStr.clear();
    }
}

// Test dealing of one Card.
void DeckTester::testDealOneCard(){
    // Create a new Deck
    Deck lDeck;
    
    // The expected CardString for the first Card after Deck creation.
    std::string lExpectedCardStr = "3.12";
    
    // Test dealOneCard before Shuffle.
    std::unique_ptr<Card> lFirstCard = lDeck.dealOneCard();
    ASSERT_WITH_MESSAGE(lFirstCard.get(), "Dealt empty card when deck is clean!\n");
    ASSERT_WITH_MESSAGE((lExpectedCardStr.compare(lFirstCard->getCardStr())==0), "Erro dealing the first card!\n");
    
    // Test dealOneCard after Shuffle.
    lDeck.shuffle();
    
    // Copy the top Card
    ASSERT_WITH_MESSAGE((lDeck.mCardUniPtrs.back().get()), "Corrupted Deck!\n");
    Card lTopCard(*lDeck.mCardUniPtrs.back());
    
    // Test dealOneCard, expecting the top Card to be returned.
    std::unique_ptr<Card> lDealtCard = lDeck.dealOneCard();
    ASSERT_WITH_MESSAGE(lDealtCard.get(), "Dealt empty card when deck is not empty!\n");
    ASSERT_WITH_MESSAGE(lTopCard == (*lDealtCard), "Error dealing card after shuffle!\n");
}

// Test dealing of multiple Cards continuously.
void DeckTester::testDealCards(){
    // Create a new Deck and shuffle
    Deck lDeck;
    lDeck.shuffle();
    
    // Deal all the Cards until Deck is empty.
    while(lDeck.getSize()!=0)
    {
        // Copy the Top Card
        ASSERT_WITH_MESSAGE((lDeck.mCardUniPtrs.back().get()), "Corrupted Deck!\n");
        Card lTopCard(*lDeck.mCardUniPtrs.back());
        
        // Check if the dealt Card is as expected.
        std::unique_ptr<Card> lDealtCard = lDeck.dealOneCard();
        ASSERT_WITH_MESSAGE(lDealtCard.get(), "Dealt empty card when deck is not empty!\n");
        ASSERT_WITH_MESSAGE(lTopCard == (*lDealtCard), "Error dealing mutliple cards!\n");
    }
}

// Test the return when dealOneCard is called on an empty Deck.
void DeckTester::testDealEmptyDeck(){
    // Create a new Deck and shuffle
    Deck lDeck;
    lDeck.shuffle();
    
    // Deal all the Cards until Deck is empty.
    for(int i=0; i<(NUM_OF_RANK*NUM_OF_SUIT); i++)
    {
        std::unique_ptr<Card> lCard = lDeck.dealOneCard();
        ASSERT_WITH_MESSAGE((lCard.get() != 0), "Error dealing all the cards\n");
    }
    
    // Check to see if the Deck is empty.
    ASSERT_WITH_MESSAGE((lDeck.getSize()==0), "Error creating empty deck!\n");
    
    // Check if the returned Card is NULL.
    std::unique_ptr<Card> lEmptyCard = lDeck.dealOneCard();
    ASSERT_WITH_MESSAGE((lEmptyCard.get() == 0), "Error dealing empty deck!\n");
}

// Test the shuffling after some Cards are dealt.
void DeckTester::testDeckShuffleAfterDealing(){
    // Create a Deck and deal some Cards.
    Deck lDeck;
    std::string lDealtCards[10];
    
    lDeck.shuffle();
    // Store the string of the dealt Cards in an array.
    for(int i = 0; i<10; i++)
    {
        std::unique_ptr<Card> lDealtCard = lDeck.dealOneCard();
        ASSERT_WITH_MESSAGE(lDealtCard.get(), "Dealt empty card when deck is not empty!\n");
        lDealtCards[i] = lDealtCard->getCardStr();
    }
    
    // Test shuffle: no repeating element
    std::set<std::string> lCardSet;
    std::pair<std::set<std::string>::iterator,bool> lRet;
    
    // shuffle again and check size
    lDeck.shuffle();
    ASSERT_WITH_MESSAGE((lDeck.getSize() == (NUM_OF_RANK*NUM_OF_SUIT - 10)), "Wrong size after dealing and shuffle\n");
    
    int lDeckSize = (int) lDeck.getSize();
    // Deal all the Cards and check for repeating elements
    for(int i = 0; i<lDeckSize; i++)
    {
        std::string lCardStr;
        std::unique_ptr<Card> lDealtCard = lDeck.dealOneCard();
        ASSERT_WITH_MESSAGE(lDealtCard.get(), "Dealt empty card when deck is not empty!\n");
        
        // lRet.second will be false if the element already exists in the set.
        lRet = lCardSet.insert(lDealtCard->getCardStr());
        ASSERT_WITH_MESSAGE((lRet.second), "Duplicate Card after shuffle!\n");
    }
    
    // Also the previously dealt Cards shall not be in the set, either
    for(int i = 0; i<10; i++)
    {
        // lRet.second will be false if the element already exists in the set.
        lRet = lCardSet.insert(lDealtCards[i]);
        ASSERT_WITH_MESSAGE((lRet.second), "Duplicate Card already dealt after shuffle!\n");
    }
    
    // Call shuffle() again on the empty Deck.
    lDeck.shuffle();
    ASSERT_WITH_MESSAGE((lDeck.getSize() == 0), "Wrong size shuffling empty Deck\n");
}
