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
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>
#include <iostream>

class PlayingCardDeck{
  
private:
    static const int NUM_SUITES = 4;
    static const int NUM_VALUES = 13;
    static const int DECK_SIZE = NUM_SUITES * NUM_VALUES;
    
    PlayingCard **gameDeckPTR;
    int count;
    
    
    void initDeck();
    void deleteDeck();
    
public:
    // class Constructors
    PlayingCardDeck();
    PlayingCardDeck(int numShuffles);
    ~PlayingCardDeck();
    
    PlayingCard *dealCard();
    bool shuffle(int numShuffles);
    void reset();
    std::string getAllCardCodes();
    int getCountUsed();
    int getCountRemain();
    
    
};


#endif /* PlayingCardDeck_hpp */
