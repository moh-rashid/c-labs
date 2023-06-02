//
//  Dealer.cpp
//  Lab10
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "Dealer.hpp"


Dealer::Dealer() { 
    theDeck = new PlayingCardDeck();
}

Dealer::Dealer(int shuffle) { 
    theDeck = new PlayingCardDeck(shuffle);
}

Dealer::~Dealer() { 
    delete theDeck;
}

std::string Dealer::showHand() {
    std::string str = this->theHand->getAllCardCodes();
    str.replace(0, 2, "XX");
    return str;
}

std::string Dealer::fullHand() { 
    return this->theHand->getAllCardCodes();
}

PlayingCard *Dealer::dealCard() { 
    return this->theDeck->dealCard();
}

int Dealer::cardsLeft() { 
    return theDeck->getCountRemain();
}

void Dealer::shuffle() {
    theDeck->reset();
    theDeck->shuffle(4);
}
