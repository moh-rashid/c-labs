#ifndef BlackJackHand_H
#define BlackJackHand_H

#include "PlayingCard.h"

class BlackJackHand
{
    private:
            // Somewhat arbitrary decision of max 5 cards
        const static int HANDSIZE = 5;
        PlayingCard * hand[HANDSIZE];
        int cardCount;
    
            // local method for getting a value
        int getCardIntValue(char value);

    public:
        BlackJackHand();
        BlackJackHand(PlayingCard *c1, PlayingCard *c2);
        ~BlackJackHand();
        bool addCard(PlayingCard *c1);
        int getCardCount();
        int getHighScore();
        int getLowScore();
        void clearHand();
        bool isBust();
        bool isFull();
        bool canTakeCard();
        std::string getAllCardCodes();

};

#endif // BlackJackHand_H
