//
//  Dealer.hpp
//  Lab10
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#ifndef Dealer_hpp
#define Dealer_hpp

#include <stdio.h>
#include "Player.hpp"
#include "PlayingCardDeck.hpp"

class Dealer: public Player{
  
public:
    Dealer();
    Dealer(int shuffle);
    ~Dealer();
    
    std::string showHand() override;
    std::string fullHand();
    
    PlayingCard *dealCard();
    int cardsLeft();
    void shuffle();
    
    
private:

    PlayingCardDeck *theDeck;
    
    
};

#endif /* Dealer_hpp */
