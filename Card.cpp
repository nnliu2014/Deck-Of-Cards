//
//  Card.cpp
//  DeckOfCards
//
//  Created by Ningning Liu on 5/14/19.
//  Copyright © 2019 Ningning Liu. All rights reserved.
//

#include "Card.hpp"

#include <iostream>
#include <stdio.h>
#include <sstream>

// Constructor with parameters to set Suit and Rank
Card::Card(PokerSuit iSuit, PokerRank iRank){
    mSuit = iSuit;
    mRank = iRank;
}

// Copy Constructor
Card::Card(const Card &iCard){
    mSuit = iCard.mSuit;
    mRank = iCard.mRank;
}

// Reading methods, constant
PokerSuit Card::getSuit() const
{
    return mSuit;
}

PokerRank Card::getRank() const
{
    return mRank;
}

// For testing purposes only
std::string Card::getCardStr(){
    std::stringstream lSStr;
    lSStr<<mSuit<<"."<<mRank;
    return lSStr.str();
}

// Support judgement of Equal or Not Equal
bool operator == (const Card &iCard1, const Card &iCard2){
    return ((iCard1.mRank == iCard2.mRank) && (iCard1.mSuit == iCard2.mSuit));
}

bool operator != (const Card &iCard1, const Card &iCard2){
    return !(iCard1 == iCard2);
}
