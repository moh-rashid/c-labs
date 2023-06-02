//
//  PlayingCardDeck.cpp
//  Lab9 c++2
//
//  Created by Mohammed AlRashid on 6/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "PlayingCardDeck.hpp"


PlayingCardDeck::PlayingCardDeck() { 
    gameDeckPTR = new PlayingCard *[DECK_SIZE]; // Allocating space for cards
    count = 0; // reset count to 0
    
    initDeck(); // initilaize the deck
}

PlayingCardDeck::PlayingCardDeck(int numShuffles) {
    gameDeckPTR = new PlayingCard *[DECK_SIZE];
    count = 0;
    initDeck();
    this->shuffle(numShuffles); // Shuffle cards after init
}
void PlayingCardDeck::initDeck() {
    
    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[] = {'C','H','D','S'};
    count = 0;
    
    // filling array with cards
    for(int i=0; i<NUM_SUITES; i++){
        for(int j=0; j< NUM_VALUES; ++j){
            gameDeckPTR[i * NUM_VALUES +j] = new PlayingCard(values[j], suits[i]);
        }
    }
}

PlayingCardDeck::~PlayingCardDeck() { 
    deleteDeck(); // delete cards before freeing pointer
    delete [] gameDeckPTR; // free pointer array
}


void PlayingCardDeck::deleteDeck() {
    for (int i = 0; i < DECK_SIZE; ++i){ // delete the cards from array
        if(gameDeckPTR[i] != nullptr) // check if pointer is valid
            delete gameDeckPTR[i];
    }
}


PlayingCard *PlayingCardDeck::dealCard() {
    if(gameDeckPTR[count] != nullptr && count <= DECK_SIZE){ // checks for boundries
        
        PlayingCard *currentCard = gameDeckPTR[count]; // temp pointer that contain the card
        gameDeckPTR[count] = nullptr; // setting card to nullptr after dealing
        count++; // move to next card
        
        return currentCard;
    }
    return nullptr;
}


// Shuffle the deck cards.
bool PlayingCardDeck::shuffle(int numShuffles){
    
    std::srand(static_cast<int>(std::time(nullptr))); // rand seed
    
    if(gameDeckPTR[count] != nullptr){ // check if cards are delt
        PlayingCard *tempCard; // temp card for copying
        int index=0;
        while(index <= numShuffles){
            for (int i=0; i<DECK_SIZE; ++i) {
                int j = rand() % DECK_SIZE;
                tempCard = gameDeckPTR[j];
                gameDeckPTR[j] = gameDeckPTR[i];
                gameDeckPTR[i] = tempCard;
            } // switch array[a] with array[j]
        index++;
    } // end while loop
        return true;
    } // end if statment
    return false;
}

void PlayingCardDeck::reset() {
    deleteDeck();
    initDeck();
}

std::string PlayingCardDeck::getAllCardCodes() {
    
    std::stringstream cardCodes; // streaming card strings to sstream
    
    
    for(int i=0; i < NUM_SUITES; i++){
        for(int j=0; j< NUM_VALUES; j++){
            if(gameDeckPTR[i * NUM_VALUES +j])
            cardCodes << gameDeckPTR[i * NUM_VALUES +j]->getValue() << gameDeckPTR[i * NUM_VALUES +j]->getSuit() << " ";
        }
        cardCodes << std::endl;
    }
    return cardCodes.str();
}

int PlayingCardDeck::getCountUsed() const{
    return count;
}

int PlayingCardDeck::getCountRemain() const{
    return DECK_SIZE - count;
}












