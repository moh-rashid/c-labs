#include "PlayingCard.h"

    // default constructor, sets suit and value to invalid values
PlayingCard::PlayingCard()
{
    suit = '0';
    value = '0';
}

    // overloaded constructor, sets set and value to input values
    // if those are good, otherwise same as default constructor
PlayingCard::PlayingCard(char value, char suit)
{

    if ( isGood (value, suit))
    {
        this->suit = suit;
        this->value = value;
    }
    else
    {
        this->suit = '0';
        this->value = '0';
    }
}

    // sets value and suit as input, if valid values
    // does nothing if not valid values
bool PlayingCard::setCard (char value, char suit)
{

    if ( isGood (value,suit))
    {
        this->suit = suit;
        this->value = value;
        return true;
    }
    else
    {
        this->suit = '0';
        this->value = '0';
        return false;
    }
}

    // return cards value
char PlayingCard::getValue()
{
    return value;
}
    // return cards suit
char PlayingCard::getSuit()
{
    return suit;
}

    // make a string from the value and suit and return it
    // as a string
std::string PlayingCard::getCardCode()
{
    std::string temp = "";
    return temp + value + suit;
}

    // indicates if this card is a legal card
bool PlayingCard::isValid()
{
    return isGood(value, suit);
}

    // this is the private method that is used
    // to check a value and suit pair
    // it allows Joker (J) that is Red (R) or Black (B)
    // as well as normal 52 cards (CDHS, A23456789TJQK)
bool PlayingCard::isGood(char value, char suit)
{
        // default starting values, not good
   bool goodSuit = false;
   bool goodValue = false;

        // first see if this is a good suit
   switch (suit)
   {
		case 'C':
		case 'D':
		case 'H':
		case 'S':
			goodSuit = true;
			break;
		default:
			goodSuit = false;
   }

        // if suit is good, see if value is good
	if ( goodSuit )
	{
		switch (value)
		{
			case 'A':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'T':
			case 'J':
			case 'Q':
			case 'K':
				goodValue = true;
				break;
			default:
				goodValue = false;
		}
	}
        // was not a good suit, see if Joker
    else
    {
        if ( value == 'J' && (suit == 'R' || suit == 'B'))
        {
            goodSuit = goodValue = true;
        }
    }
    
        // only valid if both values are true
   return goodSuit && goodValue;
}
