//
//  Deck.cpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

#include "Deck.hpp"

#include <iostream>

//Default Constructor which will create the Cards automatically
Deck::Deck()
{
    mCardUniPtrs.clear();
    // Initalize the deck of cards
    try{
        //Seed the random number generation at construction time
        srand((unsigned int)time(0));
        
        // Reserve the size of the vector to avoid repeating copy and allocation
        // during expansion.
        mCardUniPtrs.reserve(NUM_OF_RANK * NUM_OF_SUIT);
        for (int i = 0; i < NUM_OF_SUIT; i++){
            for (int j = 0; j < NUM_OF_RANK; j++){
                // Create the Cards in order of the Suit and Rank.
                mCardUniPtrs.push_back(std::unique_ptr<Card>
                                       (new Card((PokerSuit)i, (PokerRank)j)));
            }
        }
    }
    // Catch the memory allocation failure
    catch(std::bad_alloc& ex){
        mCardUniPtrs.clear();
        exit(1);
    }
}

// Copy constructor, for testing purposes only
Deck::Deck(Deck &iDeck)
{
    //Initialize vector and style
    try{
        //seed the random number generation at construction time
        srand((unsigned int)time(0));
        
        // Reserve the size of the vector to avoid repeating copy and allocation
        // during expansion
        mCardUniPtrs.reserve(iDeck.mCardUniPtrs.size());
        for(int i = 0; i<iDeck.mCardUniPtrs.size(); i++){
            mCardUniPtrs.push_back(std::unique_ptr<Card>
                                   (new Card(iDeck.mCardUniPtrs[i]->getSuit(), iDeck.mCardUniPtrs[i]->getRank())));
        }
    }
    catch(std::bad_alloc& ex){
        mCardUniPtrs.clear();
        exit(1);
    }
}

// Get the deck content in form of a string
// For testing purposes only
void Deck::deckStr(std::string &oStr){
    
    // Initialize output string.
    oStr.clear();
    
    // Return empty string if Deck is empty.
    if(mCardUniPtrs.size() == 0)
        return;
    
    // Append the string of each Card from the top.
    for(int i = (int) mCardUniPtrs.size()-1; i >= 0; i--){
        oStr.append(mCardUniPtrs[i]->getCardStr());
        //Put a space between cards, except the last one
        if(i!=0)
            oStr.append(" ");
    }
}

// Return the number of Cards in the Deck.
int Deck::getSize(){
    return (int) mCardUniPtrs.size();
}

// Randomly permute the Cards remained in the Deck.
void Deck::shuffle(){
    
    int lRandom = 0;
    int lSize = (int) mCardUniPtrs.size();
    
    // From bottom of the the deck, swap every Card with another Card in the Deck.
    for (int i=0; i<mCardUniPtrs.size();i++)
    {
        // Get a random number between i and lSize.
        lRandom = i + (rand() % (lSize -i));
        
        // lRandom will be the index of the Card betwen ith and the top.
        // Swap the ith Card with the random Card .
        std::swap(mCardUniPtrs[i],mCardUniPtrs[lRandom]);
    }
}

// Return the Card on top of the Deck (end of the vector).
// Transfer the ownership of the Card to the caller.
std::unique_ptr<Card> Deck::dealOneCard(){
    // Return no Card when the Deck is empty.
    if(mCardUniPtrs.size() == 0)
        return std::unique_ptr<Card>((Card*)0);
    
    // Hold the ownership of the Card in lCard while clear the last element in vector.
    std::unique_ptr<Card> lCard = std::move(mCardUniPtrs.back());
    mCardUniPtrs.pop_back();
    
    // Transfer the owner ship to the caller
    return (std::unique_ptr<Card>(std::move(lCard)));
}
