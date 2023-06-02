

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <sstream>
#include "Car.hpp"

struct Link{
    
    Link *next;
    Car *carValue;
    
};

class CarList{
    
private:
    Link *head;
    
public:
    
    //Constructers
    CarList();
    ~CarList();
    
    // Methods
    //TODO: fid Types
    void addCar(std::string make, std::string color, int year);
    bool findCar(std::string make, std::string color, int year);
    Car *removeHead();
    std::string displayList();
    
};



#endif /* List_hpp */
