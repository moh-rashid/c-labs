#include "BlackJackHand.h"

    // constructor, sets all locations to nullptr
    // not really needed since use cardCount to
    // indicate where valid cards are
BlackJackHand::BlackJackHand()
{
    for(int i = 0; i < HANDSIZE; i++)
		hand[i] = nullptr;
	cardCount = 0;
}

    // same as default, but starts with two cards in the hand
BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
{
    for(int i = 0; i < HANDSIZE; i++)
		hand[i] = nullptr;
	cardCount = 0;

    hand[cardCount++] = c1;
    hand[cardCount++] = c2;
}

    // destructor, deletes any cards
BlackJackHand::~BlackJackHand()
{
    clearHand();
}

    // add a card to next slot in hand
    // only accepts if the player has less
    // than five cards or has not reached
    // a count of 21 yet.
bool BlackJackHand::addCard(PlayingCard *c1)
{
    if ( getLowScore() == 21 or isBust() or isFull() )
    {
        return false;
    }
    else
	{
        hand[cardCount++] = c1;
    }

    return true;
}

    // how many cards are in the hand
int BlackJackHand::getCardCount()
{
    return cardCount;
}

    // what is the current value of the hand
    // counting first A as 11, other A as 1
int BlackJackHand::getHighScore()
{
    bool firstAce = true;
    int score = 0;

    for ( int i = 0; i < cardCount; i++ )
    {
        if ( hand[i]->getValue() == 'A' and firstAce )
        {
            score += 11;
            firstAce = false;
        }
        else
        {
            score += getCardIntValue(hand[i]->getValue());
        }
    }
    return score;
}

    // what is current value of hand
    // counting all aces as 1
int BlackJackHand::getLowScore()
{
    int score = 0;
    for ( int i = 0; i < cardCount; i++ )
    {
        score += getCardIntValue(hand[i]->getValue());
    }
    return score;
}

    // deletes any cards and resets counter to zero
    // also sets all slots to nullptr,
    // but that is not really necessary since use count
void BlackJackHand::clearHand()
{
    for ( int i = 0; i < HANDSIZE; i++ )
    {
        if ( hand[i] != nullptr )
        {
            delete hand[i];
            hand[i] = nullptr;
        }
    }
    cardCount = 0;
}

    // got a score over 21, done with this hand
bool BlackJackHand::isBust()
{
    return getLowScore() > 21;
}

    // have five cards, can take no more
bool BlackJackHand::isFull()
{
    return cardCount >= HANDSIZE;
}

    // Have not broken, have room for more cards
bool BlackJackHand::canTakeCard()
{
    return getLowScore() < 21 and cardCount < HANDSIZE;
}

    // what does  the hand look like?
std::string BlackJackHand::getAllCardCodes()
{
    std::string temp;

    for ( int i = 0; i < cardCount; i++ )
    {
        temp += hand[i]->getCardCode();
        temp += " ";
    }

    return temp;
}


    // get the integer value of the cards in the hand
    // A are 1, 2-9 face value, T-K are 10
int BlackJackHand::getCardIntValue(char value)
{
    switch (value)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'T':
    case 'J':
    case 'Q':
    case 'K':
        return 10;
    default:
        return 0;
    }
}
