//
//  Car.hpp
//  CarList
//
//  Created by Mohammed AlRashid on 5/25/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp
#include <iostream>
#include <stdio.h>

class Car{
public:
    
    Car();
    Car(std::string model, std::string color, int year);
    
    // Getters:
    std::string getMake() const;
    std::string getColor() const;
    int getYear()  const;
    
    // Setters:
    void setMake(std::string model);
    void setColor(std::string color);
    void setYear(int year);
    
    // Operator Functions
    friend bool operator==(const Car &lhs, const Car &rhs){
        bool result = (lhs.make == rhs.make) and (lhs.color == rhs.color) and (lhs.year == rhs.year);
        
        return result;
    }
    friend std::ostream & operator<<(std::ostream &os, const Car &rhs){
        os << rhs.getYear();
        os << " " << rhs.getColor();
        os << " " << rhs.getMake();
        
        return os;
    }
    
    
    
private:

    std::string make;
    std::string color;
    int year;
    
};




#endif /* Car_hpp */
