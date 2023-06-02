//
//  Car.cpp
//  CarList
//
//  Created by Mohammed AlRashid on 5/25/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "Car.hpp"

// Default Constructer
Car::Car():make("Ford"),color("Black"),year(1910) { }
// Overloded Constructer.
Car::Car(std::string model, std::string color, int year): make(model),color(color),year(year) { }

// Getters
std::string Car::getMake() const {
    return make;
}

std::string Car::getColor() const {
    return color;
}

int Car::getYear() const {
    return year;
}
// Setters
void Car::setMake(std::string model) {
    this->make = model;
}

void Car::setColor(std::string color) {
    this->color = color;
}

void Car::setYear(int year) {
    this->year = year;
}


