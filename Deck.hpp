//
//  Deck.hpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

//  Class Name: Deck
//
//  Description: One Deck hold 52 different Cards in four suits defined in PokerSuit and with face values
//  defined in PokerRank.

//  1. Deck class support one default constructor, and one copy constructor for testing purposes. The Cards
//  are created at construction of the Deck object and can only be dealt out. Currently implementation does
//  not support a card to be added back to a Deck.
//
//  2. Ownership of a Card is exclusive: only one container can hold the Card at anytime. In
//  real world, this means one card is either in the deck, or is dealt to a player. This is supported by
//  using unique_ptr in the implementation.

//  3. shuffle() return no values but will randomly permute the cards in the Deck. It can be called multiple
//  times.
//
//  4. dealOneCard() will pass the ownership of the Card to the caller. When the Deck is empty, no Card will
//  be returned. The caller need to check the content of the unique_ptr to check if a Card is dealt
//  successfully.
//
//  5. getSize() will return the numbe of Cards, currently in the Deck.
//
//  Other considerations:
//  Thread safty is not considered in this design as the ownership of Deck shall also be exclusive.
//  One Deck can only be in one hand.

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>

#include <memory>
#include <string>
#include <vector>

#include "Card.hpp"

class Deck {
private:
    
    // Use a vector to hold unique_ptrs to Cards
    // This ensures the Deck has the single ownership of the Cards.
    // When a Card is dealt, its ownership is transferred to the caller.
    // This helps to prevent the memory leak at abnormal cases and exceptions.
    std::vector<std::unique_ptr<Card>> mCardUniPtrs;
    
protected:
    // Copy constructor for testing purposes
    Deck(Deck &iDeck);
    // Return the whole Deck as a string, for testing purposes. The order is the same with card dealing.
    void deckStr(std::string &oStr);
    
public:
    // Only a default constructor (with no parameters) as all cards will be created automatically.
    Deck();
    
    // Get the number of Cards in the Deck.
    int getSize();
    // Shuffle method will do a permutation of the remain Cards in the deck.
    void shuffle();
    // Deal the Card at the top of the deck (when suit and rank facing downwards).
    // The Card at the end of the vector will be returned and ownership of the Card transferred.
    std::unique_ptr<Card> dealOneCard();
    
    friend class DeckTester;
};

#endif /* Deck_hpp */
