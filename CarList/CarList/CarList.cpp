//
//  List.cpp
//  CarList
//
//  Created by Mohammed AlRashid on 5/25/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "CarList.hpp"



CarList::CarList() {
    head = nullptr;
}

CarList::~CarList() {
    
    Link *PTR = head;
    
    while (PTR) {
        Link *tempPTR = PTR; // Make a temporary Pointer.
        PTR = PTR->next;
        
        // Deleting pointers.
        delete tempPTR->carValue;
        delete tempPTR;
    }
}

void CarList::addCar(std::string make, std::string color, int year) {
    
    Car *objPTR = new Car(make,color,year);
    
    Link *linkPTR = new Link;
    
    linkPTR->carValue = objPTR;
    linkPTR->next = head;
    
    head = linkPTR;
}

bool CarList::findCar(std::string make, std::string color, int year) {
    
    Link *linkPTR = head;
    
    while(linkPTR){
        bool equ = (linkPTR->carValue->getMake() == make)
        and (linkPTR->carValue->getColor() == color) and (linkPTR->carValue->getYear() == year);
        if(equ){
            return true;
        }
        linkPTR = linkPTR->next;
    }
    return false;
}

Car *CarList::removeHead() { 
    
    if(head == nullptr)
        return nullptr;
    
    Link *linkPTR = head;
    Car *objPTR = linkPTR->carValue;
    
    head = head->next;
    
    delete linkPTR;
    
    return objPTR;
}

std::string CarList::displayList() {
    std::stringstream buffer;
    Link *linkPTR = head;
    
    while(linkPTR){

        buffer << linkPTR->carValue->getYear();
        buffer << " " << linkPTR->carValue->getColor();
        buffer << " " << linkPTR->carValue->getMake();
        
        linkPTR = linkPTR->next;
        if(linkPTR)
            buffer << ", ";
        else
            buffer << ".";
    }
    return buffer.str();
}




