//
//  Person.hpp
//  Lab 6 cs162
//
//  Created by Mohammed AlRashid on 5/10/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//
#include "CreditCard.hpp"


#ifndef Person_hpp
#define Person_hpp

using namespace std;

class Person{
    
public:
    
    Person();
    Person(string firstName, string lastName, string address);
    
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAddress(string address);
    
    string getFirstName();
    string getLastName();
    string getAddress();
private:
    string firstName, lastName, address;
    
};



#endif /* Person_hpp */



