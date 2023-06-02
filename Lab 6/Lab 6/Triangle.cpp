//
//  Triangle.cpp
//  Lab 6
//
//  Created by Mohammed AlRashid on 5/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle():sideA(3), sideB(4), sideC(5){ }

Triangle::Triangle(int sideA, int sideB, int sideC):sideA(sideA), sideB(sideB), sideC(sideC){ }

int Triangle::getA(){
    
    return sideA;
}

int Triangle::getB(){
    
    return sideB;
}

int Triangle::getC(){
    
    return sideC;
}

void Triangle::setA(int side){
    
    sideA = side;
}

void Triangle::setB(int side){
    sideB = side;
}

void Triangle::setC(int side){
    sideC = side;
}

bool Triangle::isEquilateral(){
    
    if(sideA == sideB and sideB == sideC)
        return true;
    return false;
}

bool Triangle::isScalene(){
    if(sideA != sideB and sideB != sideC)
        return true;
    return false;
}

bool Triangle::isIsosceles(){
    
    bool twoEqu = ( sideA == sideB or sideB == sideC or sideA == sideC);
    bool threeEqu = (sideA == sideB and sideB == sideC);
    
    if(twoEqu == true or threeEqu == true)
        return true;
    return false;
}

bool Triangle::isRight(){
    int sideASquared = pow(sideA, 2);
    int sideBSquared = pow(sideB, 2);
    int sideCSquared = pow(sideC, 2);
   
    bool checkSideC = ( (sideASquared + sideBSquared) == sideCSquared);
    bool checkSideB = ( (sideASquared + sideCSquared) == sideBSquared);
    bool checkSideA = ( (sideBSquared + sideCSquared) == sideASquared);

    if(checkSideA == true or checkSideB == true or checkSideC == true)
        return true;
    return false;
}
