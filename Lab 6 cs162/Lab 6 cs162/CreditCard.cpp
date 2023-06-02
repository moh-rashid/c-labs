//
//  CreditCard.cpp
//  Lab 6 cs162
//
//  Created by Mohammed AlRashid on 5/10/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "CreditCard.hpp"


CreditCard::CreditCard(string firstName, string lastName, string address, int cardNumber, int creditLimit){
    person.setFirstName(firstName);
    person.setLastName(lastName);
    person.setAddress(address);
    this->cardNumber = cardNumber;
    this->setCreditLimit(creditLimit);
}

void CreditCard::setCreditLimit(double value){
    this->creditLimit = value;
}

double CreditCard::getBalance(){
    /* HOW TO SET BALANCE ???????????   */
    return creditBalance;
}

int CreditCard::getCardNumber(){
    return cardNumber;
}

string CreditCard::getOwnerName(){
    return person.getFirstName() + " " + person.getLastName();
}

string CreditCard::getAddress(){
    return person.getAddress();
}

bool CreditCard::payBalance(double value){
    
    if(value<0)
        return false;
    creditBalance -= value;
    return true;
}

bool CreditCard::makeCharge(double value){
    
    if(value < 0 or creditBalance + value > creditLimit)
        return false;
    
    creditBalance += value;
    return true;
}

