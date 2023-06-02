//
//  PlayingCardDeck.cpp
//  Lab9 c++2
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "PlayingCardDeck.hpp"


PlayingCardDeck::PlayingCardDeck() { 
    gameDeckPTR = new PlayingCard *[DECK_SIZE];
    count = 0;
    
    initDeck();
}

PlayingCardDeck::PlayingCardDeck(int numShuffles) {
    gameDeckPTR = new PlayingCard *[DECK_SIZE];
    count = 0;
    initDeck();
    this->shuffle(numShuffles);
}
void PlayingCardDeck::initDeck() {
    
    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[] = {'C','H','D','S'};
    count = 0;
    
    for(int i=0; i<NUM_SUITES; i++){
        for(int j=0; j< NUM_VALUES; ++j){
            gameDeckPTR[i * NUM_VALUES +j] = new PlayingCard(values[j], suits[i]);
        }
    }
}

PlayingCardDeck::~PlayingCardDeck() { 
    deleteDeck();
    delete [] gameDeckPTR;
}


void PlayingCardDeck::deleteDeck() {
    for (int i = 0; i < DECK_SIZE; ++i){
            delete gameDeckPTR[i];
    }
}


// DEAL CARDS FUNCTION
PlayingCard *PlayingCardDeck::dealCard() {
    if(gameDeckPTR[count] != nullptr && count <= DECK_SIZE){
        
        PlayingCard *currentCard = gameDeckPTR[count];
        gameDeckPTR[count] = nullptr;
        count++;
        
        return currentCard;
    }
    return nullptr;
}


// Shuffle the deck cards.
bool PlayingCardDeck::shuffle(int numShuffles){
    
    std::srand(static_cast<int>(std::time(nullptr)));
    
    if(gameDeckPTR[count] != nullptr){
        PlayingCard *tempCard;
        
            for (int i=0; i<DECK_SIZE; ++i) {
                int j = rand() % DECK_SIZE;
                tempCard = gameDeckPTR[j];
                gameDeckPTR[j] = gameDeckPTR[i];
                gameDeckPTR[i] = tempCard;
            }
        
        return true;
    }
    return false;
}

void PlayingCardDeck::reset() {
    deleteDeck();
    initDeck();
}

std::string PlayingCardDeck::getAllCardCodes() {
    
    std::stringstream cardCodes;
    
    
    for(int i=0; i < NUM_SUITES; i++){
        for(int j=0; j< NUM_VALUES; j++){
            if(gameDeckPTR[i * NUM_VALUES +j])
            cardCodes << gameDeckPTR[i * NUM_VALUES +j]->getValue() << gameDeckPTR[i * NUM_VALUES +j]->getSuit() << " ";
        }
        cardCodes << std::endl;
    }
    return cardCodes.str();
}

int PlayingCardDeck::getCountUsed() {
    return count;
}

int PlayingCardDeck::getCountRemain() {
    return DECK_SIZE - count;
}












