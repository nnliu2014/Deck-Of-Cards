# Deck-Of-Cards
Deck Of Cards Assignment from Appian

## Requirement
 Implement a set of classes that represent a deck of poker-style paying cards.
 (Fifty-two playing cards in four suits: hearts, spades, clubs, diamonds with
 face value of Ace, 2-10, Jack, Queen and King.) Within one of your classes, two operations need to be provided:

 **shuffle()** which returns no value, but results in the cards in the deck being randomly permuted.

 **dealOneCard()** which return one card from the deck to the caller.

 Specifically, a call to shuffle followed by 52 calls to dealOneCard() should result in the caller being provided all 52 cards of the deck in a random order. If the caller then makes a 53rd call dealOneCard(), no card is dealt.

## Source Codes
 9 files in total

 IDE used is developed with Xcode version 10.2.1.
 -main.cpp
 -Card.hpp
 -Card.cpp
 -Deck.hpp
 -Deck.cpp
 -CardTester.hpp
 -CardTester.cpp
 -DeckTester.hpp
 -DeckTester.cpp

## Installation
 Source code can be imported into a Xcode c++ Command Line Tool Project.
 Only standard libraries are used.

## Execution/Testing
 **main()** in main.cpp serve as the unit test executor.
 Testing result will be printed to the output.
 There will be assertion with messages when test failed.

 _Note: Xcode's unit test framework, XCTest, is not very friendly with c++ project testing. It is more commonly used for UI testing and swift. Thus a more generic c++ project (not IDE dependent) is created for testing purposes._

## Design

### Card
 Card class is the representation of a poker-style card.
#### Data Members
 -**mSuit** (Defined as enum PokerSuit: Hearts, Spades, Diamonds, Clubs)

 -**mRank** (Defined as enum PokerRank: Ace, Two...Ten, Jack, Queen, King)

 -**NUM_OF_SUIT**, an enum value of PokerSuit is also defined to keep the number of suits.

 -**NUM_OF_Rank**, an enum value of PokerRank is also defined to keep the number of ranks.
#### Methods
 -**getSuit();** return the suit of the Card.
 
 -**getRank();** return the rank of the Card.

 Only expose read only methods since a card shall not be changed after creation.
#### Constructors
 -**Card(iSuit, iRank);** protected

 -**Card(&iCard);** protected

 Can only be created by friend classes: Deck, CardTester, DeckTester. No public constructors.
#### Other methods and operators
 -**==** and **!=** as friend function, for testing purposes

 -**getCardStr();** protected, for testing purposes
#### Ownership and Lifetime of Card instances
 To avoid fraud in games, the Card shall have an exclusive ownership: either it is in a Deck of Cards or it has been dealt (to a player or on the table, etc.) The Card can only be created when a Deck is created. The Deck has the sole ownership of the Card until it is dealt, which will transfer its ownership to the caller.

### Deck
 Deck class is the representation of a deck of poker-style card.
#### Data Members
 -**mCardUniPtrs** (std::vector<std::unique_ptr<Card>>)
 -**unique_ptr** is used here to ensure the exclusive ownership on Card objects.
#### Methods
 -**getSize();** return the remaining number of Cards in the Deck.
 -**shuffle();** randomly permute the Cards remained in the Deck.
 -**dealOneCard();** return the Card on top of the Deck, return no Card if Deck is empty.
#### Constructors
 -**Deck();** Default constructor, public
 -**Deck(&iDeck);** copy constructor, protected

 The copy constructor can only be invoked by friend classes for testing purposes.
#### Other methods and operators
 -**getDeckStr();** protected, for testing purposes
#### Ownership and Lifetime of Deck instances
 Similar to Cards, the lifetime and ownership of Deck shall also be handled with care in the system. Generally one Deck shall be managed/handled by one owner only.

 _Note: This in the current design and implementation, thread safety is not considered. If in some cases concurrent accessing to one Deck is necessary, Smart locks can be added to all the member functions, but it might be more expensive._

### CardTester and DeckTester
 These are testing classes for Card and Deck Objects. They are friend classes of the two main classes and thus can access the non-public members and methods of the main classes.

## Testing
 There are 3 unit tests defined for Card and 8 unit tests for Deck, as Described below:

### Unit tests for Card
 1. **testCardCreation** will check if the Card created will have the right suit and rank.
 2. **testCardValue** will check if the correct value of suit and rank can be retrieved.
 3. **testCardComparison** will test the == and != operators.

### Unit tests for Deck
 1. **testDeckCreation** will check if the Deck created will have all the Cards created correctly.
 2. **testInitialShuffle** will check:
    -a. a permutation is done
    -b. no duplicate Cards
 (Correctness of the Cards is not checked since only the constructor can create Cards.)
 3. **testDeckShuffleRandomness** will check if multiple calls to shuffle will generate different random permutations. This is to ensure the fairness of the game.
 4. **testMultipleDeckShuffle** will check if shuffle calls to multiple Decks will generate different random permutations. This is also to ensure the fairness of the game.
 5. **testDealOneCard** will test the case of dealing from a fresh Deck or a Deck after one shuffle call.
 6. **testDealCards** will test the case where several cards are dealt continuously.
 7. **testDealEmptyDeck** will test the case when dealOneCard() is called when the deck is empty.
 8. **testShuffleAfterDealing** will test the case when shuffle() is called on a partial Deck.
