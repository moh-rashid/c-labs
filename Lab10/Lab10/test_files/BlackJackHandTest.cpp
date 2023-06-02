//
//
//#include <iostream>
//#include "BlackJackHand.h"
//#include "PlayingCard.h"
//
//using namespace std;
//
//#define TEST_HAND_WITH_DECK
//#define TEST_TWO_ACES
//
//int main()
//{
//
//#ifdef TEST_HAND_WITH_DECK
//
//    // Create a Blackjack hand object
//    BlackJackHand myHand;
//
//    // Theee arrays of values and suits for normal cards
//    //  are used in the following code that builds a deck
//    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'},
//        suits[] = {'C','H','D','S'};
//
//    const int DECK_SIZE = 52;
//    const int SUIT_SIZE = 13;
//    // This is an array of pointers to cards that acts as a deck
//    PlayingCard *deck[DECK_SIZE];
//
//    // Create the cards in suit order and add to the deck
//    // Display each card as it is created
//    cout << "Here is the starting deck " << endl;
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j = 0; j<SUIT_SIZE; j++)
//        {
//          deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
//          cout << deck[i * SUIT_SIZE + j]->getCardCode();
//          cout << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    // Now add each card in the deck in turn to the hand
//    // when the hand is full, empty it
//    // Test the display functions for hand
//    cout << "Now adding each card to hand in turn and seeing how results" << endl;
//    cout << "Should get increasing count, new hand after break or five cards" << endl;
//    for(int i = 0; i < DECK_SIZE; i++)
//    {
//            // list the card and add to hand
//            // mark that deck location as used
//        cout << deck[i]->getCardCode();
//        myHand.addCard(deck[i]);
//        deck[i] = nullptr;
//
//            // display the hand with this new card
//        cout << " : ";
//        cout << myHand.getAllCardCodes();
//        cout << " : " << myHand.getLowScore()
//          << " : " << myHand.getHighScore()
//          << " : " << myHand.isBust()
//          << " : " << myHand.isFull()
//          << " : " << myHand.getCardCount()
//          << " : " << myHand.canTakeCard()
//          << endl;
//
//            // if hand is full, empty it
//        if(!myHand.canTakeCard())
//        {
//            cout << "\nClearing hand\n";
//            myHand.clearHand();
//        }
//    }
//
//        // delete any cards remaining in deck
//        // then delete the deck itself
//    for (int i = 0; i < DECK_SIZE; i++)
//        if (deck[i] != nullptr)
//    delete deck[i];
//#endif
//
//#ifdef TEST_TWO_ACES
//    cout << "\n\nTesting two aces, should show 11, then 12, then 22" << endl;
//    PlayingCard
//    *card1 = new PlayingCard('J', 'C'),
//    *card2 = new PlayingCard('A', 'S'),
//    *card3 = new PlayingCard('A', 'D');
//
//
//    BlackJackHand hand2 = BlackJackHand(card1,card2);
//    cout << hand2.getAllCardCodes();
//    cout << " : " << hand2.getLowScore()
//    << " : " << hand2.getHighScore()
//    << " : " << hand2.isBust()
//    << " : " << hand2.isFull()
//    << " : " << hand2.getCardCount()
//    << " : " << hand2.canTakeCard()
//    << endl;
//
//    cout << "\nAdding a second ace:\n";
//
//    hand2.addCard(card3);
//    cout <<hand2.getAllCardCodes();
//    cout << " : " << hand2.getLowScore()
//    << " : " << hand2.getHighScore()
//    << " : " << hand2.isBust()
//    << " : " << hand2.isFull()
//    << " : " << hand2.getCardCount()
//    << " : " << hand2.canTakeCard()
//    << endl;
//
//#endif
//
//    return 0;
//}
//
