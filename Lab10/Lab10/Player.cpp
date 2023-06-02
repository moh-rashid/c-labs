//
//  Player.cpp
//  Lab10
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "Player.hpp"



Player::Player() {
    theHand = new BlackJackHand();
    stake = 0;
}

Player::Player(int s) {
    theHand = new BlackJackHand();
    stake = s;
}

Player::~Player() {
    delete theHand;
}


bool Player::takeCard(PlayingCard *c) { 
    return theHand->addCard(c); // TODO: Check if cards are full
}

std::string Player::showHand() {
   return theHand->getAllCardCodes();
}

int Player::getLowScore() { 
    return theHand->getLowScore();
}

int Player::getHighScore() { 
    return theHand->getHighScore();
}

int Player::getScore() { 
    if(this->getHighScore() <= 21){
        return this->getHighScore();
    }
    return this->getLowScore();
}

bool Player::busted() { 
    if(this->getLowScore() > 21){
        return true;
    }
    return false;
}

bool Player::wantCard() { 
    if(this->getScore() < 16){
        return true;
    }
    return false;
}

void Player::clearHand() { 
    theHand->clearHand();
}

void Player::setStake(int stake) { 
    this->stake = stake;
}

int Player::getStake() const { 
    return this->stake;
}

bool Player::makeBet(int bet) { 
    if(bet > this->getStake()){
        return false;
    }
    this->bet = bet;
    return true;
}

void Player::won() { 
    stake +=  bet;
}

void Player::lost() { 
    stake -= bet;
}

