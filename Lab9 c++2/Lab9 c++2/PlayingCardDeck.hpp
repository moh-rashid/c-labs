//
//  PlayingCardDeck.hpp
//  Lab9 c++2
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#ifndef PlayingCardDeck_hpp
#define PlayingCardDeck_hpp

#include <stdio.h>
#include "PlayingCard.h"
#include <ctime>
#include <sstream>
#include <iostream>

class PlayingCardDeck{
  
private:
    static const int NUM_SUITES = 4;
    static const int NUM_VALUES = 13;
    static const int DECK_SIZE = NUM_SUITES * NUM_VALUES; // Cards number
    
    PlayingCard **gameDeckPTR; // array pointer containing ponters to cards
    int count; // current card
    
    
    void initDeck(); // fill deck and init
    void deleteDeck();
    
public:
    // class Constructors
    PlayingCardDeck();
    PlayingCardDeck(int numShuffles);
    ~PlayingCardDeck();
    
    
    PlayingCard *dealCard(); // deal cards
    bool shuffle(int numShuffles); // shuffle cards
    void reset(); // reset game
    std::string getAllCardCodes(); // print the deck
    int getCountUsed() const; // how many cards dealed?
    int getCountRemain() const; // how many cards left in deck?
    
    
};


#endif /* PlayingCardDeck_hpp */
