//
//  Person.cpp
//  Lab 6 cs162
//
//  Created by Mohammed AlRashid on 5/10/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "Person.hpp"

// Default constructor
Person::Person():firstName(""), lastName(""), address("") {}
// Caustom constructer
Person::Person(string firstName, string lastName, string address):firstName(firstName),lastName(lastName),address(address) { }

void Person::setFirstName(string firstName){
    this->firstName = firstName;
}

void Person::setLastName(string lastName){
    this->lastName = lastName;
}

void Person::setAddress(string address){
    this->address = address;
}

string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

string Person::getAddress(){
    return address;
}
