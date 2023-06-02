//
//  Player.hpp
//  Lab10
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "BlackJackHand.h"
#include <sstream>

class Player{
public:
    Player();
    Player(int s);
    ~Player();
    // Black jack
   bool takeCard(PlayingCard *c);
    virtual std::string showHand();
    int getLowScore();
    int getHighScore();
    int getScore();
    bool busted();
    bool wantCard();
    void clearHand();
    // local
    void setStake(int stake);
    int getStake() const;
    bool makeBet(int bet);
    void won();
    void lost();
    
    BlackJackHand *theHand;
private:
    int stake;
    int bet;
    
};


#endif /* Player_hpp */
