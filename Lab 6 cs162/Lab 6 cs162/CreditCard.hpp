//
//  CreditCard.hpp
//  Lab 6 cs162
//
//  Created by Mohammed AlRashid on 5/10/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//


#ifndef CreditCard_hpp
#define CreditCard_hpp

#include <iostream>
#include "Person.hpp"

using namespace std;


class CreditCard{

public:
    
    // Public Methods
    CreditCard();
    CreditCard(string firstName, string lastName, string address, int cardNumber, int creditLimit);
    
    void setCreditLimit(double value);
    double getBalance();
    int getCardNumber();
    string getOwnerName();
    string getAddress();
    bool payBalance(double value);
    bool makeCharge(double value);
    
private:
    // private members
    int cardNumber, creditBalance, creditLimit;
    Person person;
    
};




#endif /* CreditCard_hpp */
