//
//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//
////#include "PlayingCardDeck.h"
//
//using namespace std;
//
//#define TEST_DEFAULT_CONSTRUCTOR
//#define TEST_OVLOADED_CONSTRUCTOR
//#define TEST_SHUFFLE
//
//int main(){
//    int checkDeck[4][13] = {};
//    int suitNdx = 0, valueNdx = 0;
//    
//    PlayingCardDeck deck, *deckPtr;
//    
//    PlayingCard *myCard;
//    
//    bool found = false;
//    
//    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
//    char suits[] = {'C','H','D','S'};
//    
//    srand(static_cast<int>(time(NULL)));
//
//#ifdef TEST_DEFAULT_CONSTRUCTOR
//    cout << "Original Deck:\n";
//    cout << deck.getAllCardCodes();
//    
//    cout << "\nDealing some cards:\n\n";
//    for(int i=0;i<22;i++) {
//        myCard = deck.dealCard();
//        if (myCard != nullptr)
//        {
//            cout << myCard->getCardCode();
//            cout << " ";
//            if(!((i+1)%13))
//                cout << endl;
//            delete myCard;
//        }
//        myCard = 0;
//    }
//    cout << "\n\nRest of deck:\n" << endl;
//    cout << deck.getAllCardCodes();
//    
//    cout << "\nShould get: \nUsed: 22, Remaining: 30\n";
//    deck.shuffle(1);
//    cout << "Actually got:\nUsed: " << deck.getCountUsed() << " Remaining: " << deck.getCountRemain() << endl << endl;
//    
//    deck.reset();
//#endif //TEST_DEFAULT_CONSTRUCTOR
//    
//#ifdef TEST_OVLOAD_CONSTRUCTOR
//    cout << "\n\nTesting overloaded constructor. Should get shuffled deck:\n\n";
//    
//    deckPtr = new PlayingCardDeck(20);
//    cout << deckPtr->getAllCardCodes();
//    delete deckPtr;
//    
//    cout << "\nReset deck, should get unshuffled full deck:\n\n";
//    cout << deck.getAllCardCodes();
// 
//    cout << "\n\nTesting empty deck:\n";
//    for(int i=0;i<52;i++) {
//        myCard = deck.dealCard();
//        if (myCard != nullptr)
//            delete myCard;
//        myCard = 0;
//    }
//    cout << "Should get: \n";
//    cout << "Used: 52, Remaining: 0\n";
//    cout << "myCard is nullptr\n";
//    
//    myCard = deck.dealCard();
//    myCard = deck.dealCard();
//    cout << deck.getAllCardCodes();
//    cout << "Actually got: \n";
//    cout << "Used: " << deck.getCountUsed() << " Remaining: " << deck.getCountRemain() << endl;
//    if(!myCard)
//        cout << "myCard is nullptr\n";
//    else
//        cout << "ERROR myCard is not nullptr\n";
//#endif //TEST_OVLOAD_CONSTRUCTOR
//    
//#ifdef TEST_SHUFFLE
//    deck.reset();
//    cout << "\n\nShuffle test. Should see unshuffled, shuffled, Array of 52 1's:\n\n";
//    
//    cout << deck.getAllCardCodes();
//    deck.shuffle(50);
//    cout << endl;
//    cout << deck.getAllCardCodes();
//    cout << endl;
//    
//    for(int i=0;i<52;i++) {
//        suitNdx = 0;
//        found = false;
//        myCard = deck.dealCard();
//        while(suitNdx < 4 && !found && myCard != nullptr ) {
//            valueNdx = 0;
//            while(valueNdx < 13 && !found) {
//                if(myCard->getSuit() == suits[suitNdx] &&
//                   myCard->getValue() == values[valueNdx]){
//                    checkDeck[suitNdx][valueNdx]++;
//                    found = true;
//                } // if
//                valueNdx++;
//            } // while
//            suitNdx++;
//        } // while
//        delete myCard;
//    } // for
//    
//    for(int i=0;i<4;i++) {
//        for(int j=0;j<13;j++) {
//            cout << checkDeck[i][j] << "  ";
//        }
//        cout << endl;
//    }
//    
//    cout << endl;
//    
//#endif //TEST_SHUFFLE
//
//    cout << "Testing Complete!\n";
//    
//    return 0;
//} // int main()
//
