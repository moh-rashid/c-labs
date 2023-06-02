//
//#include <iostream>
//#include "PlayingCard.h"
//
//using namespace std;
//
//PlayingCard makeValidCard(int value, int suit);
//
////#define TEST_DEFAULT_CONSTRUCTOR
////#define TEST_OVLOADED_CONSTRUCTOR
////#define TEST_ISVALID_VALID_DATA
////#define TEST_ISVALID_INVALID_DATA
//
//int main()
//{
//#ifdef TEST_DEFAULT_CONSTRUCTOR
//    // Create default playing card
//    PlayingCard card1;
//
//    // Test the default constructor and GetCardCode
//    cout << "Testing default constructor. Expect card code to be 00\n card code is :";
//    cout << card1.getCardCode() << endl << endl;
//
//
//    // Test the setter and getter
//    cout << "Seting card to 'AH' using SetValue and SetSuit" << endl;
//    card1.setCard('A', 'H');
//    cout << "GetValue returns: " << card1.getValue() << endl;
//    cout << "GetSuit returns: " << card1.getSuit() << endl << endl;
//
//#endif
//
//#ifdef TEST_OVLOADED_CONSTRUCTOR
//    // Test overloaded constructor
//    // Create Ten of Spaces
//    PlayingCard tenOfSpades('T', 'S');
//    cout << "Testing overloaded constructor. Expect card code to be TS\n card code is :";
//    cout << tenOfSpades.getCardCode() << endl << endl;
//#endif
//
//#ifdef TEST_ISVALID_VALID_DATA
//    // Test IsValid with valid cards
//    cout << "Testing valid card codes.\n"
//         << "Expect isValid to return true for all (except perhaps Jokers.)"
//          << endl;
//    // Create and test valid cards
//    int validCards = 0;     // cards that return true for IsValid
//    int invalidCards = 0;   // cards that return false for IsValid
//
//    // Create and test four suits plus the jokers
//    for(int suit = 1; suit <= 5; suit++)
//    {
//        // Create and test ace, 2 - 9, Jack, Queen, and King
//        for(int value = 1; value <= 13; value++)
//        {
//            PlayingCard aCard = makeValidCard(value, suit);
//            cout << "Card Code: " << aCard.getCardCode() << " IsValid: ";
//            if (aCard.isValid())
//            {
//                validCards++;
//                cout << "true" << endl;
//            }
//            else
//            {
//                invalidCards++;
//                cout << "false" << endl;
//            }
//        // suit 5 is just for creating the two Jokers
//        if (suit == 5 && value >= 2)
//            break;
//        }
//    }
//    cout << "IsValid returned false for " << invalidCards << " card codes" << endl;
//    cout << "IsValid returned true for " << validCards << " card codes" << endl;
//    cout << endl;
//
//#endif
//
//#ifdef TEST_ISVALID_INVALID_DATA
//    // Test IsValid with invalid cards
//    // Create and test invalid cards
//    cout << "Testing invalid card codes; isValid should return false for all." << endl;
//    int validCards2 = 0;
//    int invalidCards2 = 0;
//       // Loop through all possible ASCII character codes for card codes
//       for(int suit = 0; suit <= 255; suit++)
//       for(int value = 0; value <= 255; value++)
//       {
//            // Only check card codes that are not valid
//            PlayingCard aCard = makeValidCard(value, suit);
//            if (aCard.getCardCode() == "00")
//            {
//                if (aCard.isValid())
//                {
//                   cout << "value :" << value << " suit :" <<suit << " IsValid :";
//                   cout << "true" << endl;
//                   validCards2++;
//                }
//                else
//                {
//                    invalidCards2++;
//                }
//            }
//        }
//    cout << "Should have 65584 invalid codes without jokers, actually have " << endl;
//    cout << "IsValid returned false for " << invalidCards2 << " card codes" << endl;
//    cout << "IsValid returned true for " << validCards2 << " card codes" << endl;
//#endif
//    return 0;
//}
//
//
///******************************************************
//"
//" Test Functions
//"
//* This function creats a card with a valid Suit or Rank
//*   and tests to see if it properly detects invalid cards
//*
//******************************************************/
//
//PlayingCard makeValidCard(int iValue, int iSuit)
//{
//    char value = '0';
//    char suit = '0';
//
//
//        switch (iValue)
//        {
//            case 1:
//               value = 'A';
//               break;
//            case 10:
//                value = 'T';
//                break;
//            case 11:
//               value = 'J';
//               break;
//            case 12:
//               value = 'Q';
//               break;
//            case 13:
//               value = 'K';
//               break;
//            default:
//                if ((iValue >= 2) && (iValue <= 9))
//                    value = '0' + iValue;
//                break;
//        }
//
//
//       switch (iSuit)
//        {
//            case 1:
//               suit = 'D';
//               break;
//            case 2:
//               suit = 'S';
//               break;
//            case 3:
//               suit = 'C';
//               break;
//            case 4:
//               suit = 'H';
//               break;
//            // Special case for the Joker
//            case 5:
//                if(iValue == 1)
//                {
//                    value = 'Z';
//                    suit = 'B';
//                }
//                else if(iValue == 2)
//                {
//                    value = 'Z';
//                    suit = 'R';
//                }
//                else
//                {
//                    value = '0';
//                    suit = '0';
//                }
//                break;
//        }
//
//        PlayingCard testCard(value, suit);
//        return testCard;
//}
//
