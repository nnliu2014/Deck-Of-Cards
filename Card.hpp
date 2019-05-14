//
//  Card.hpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

//  Class Name: Card
//
//  Description: The Card class is used to represent a poker-style playing cards, it belong to
//  one of the four suits defined in PokerSuit with one of the face value defined in PokerRank.
//  1. A Card instance can only be created by a Deck thus no public constructor is exposed.
//  2. Suit and Rank are read only as once created the card can't not be changed.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

// Define the Rank and Suit of the card as enums
enum PokerRank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, NUM_OF_RANK};
enum PokerSuit { Hearts, Spades, Diamonds, Clubs, NUM_OF_SUIT};

class Card {
    
private:
    // Card properties, the pair of values (mSuit, mRank)
    PokerSuit mSuit;
    PokerRank mRank;
    
protected:
    // No public/default constructor as
    // 1. A card must have its suit and rank when created, no blank cards.
    // 2. Cards can only be created by a deck and then dealt out, or created in unit tests.
    Card(PokerSuit iSuit, PokerRank iRank);
    // Copy constructor used for testing purpose only
    Card(const Card &iCard);
    
    // Method for testing purposes only, visable only to friend classes
    std::string getCardStr();
    
public:
    // Read only, a card can not be changed once created
    PokerRank getRank() const;
    PokerSuit getSuit() const;
    
    // To support card comparison in tests
    friend bool operator == (const Card &iCard1, const Card &iCard2);
    friend bool operator != (const Card &iCard1, const Card &iCard2);
    
    // Friend classes for testing purposes
    friend class CardTester;
    friend class DeckTester;
    
    // Only Deck can create Card instances.
    friend class Deck;
};

#endif /* Card_hpp */
