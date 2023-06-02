//
//  Triangle.hpp
//  Lab 6
//
//  Created by Mohammed AlRashid on 5/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>

class Triangle{

public:
    
    Triangle();
    Triangle(int SideA, int SideB, int sideC);
    
    int getA();
    int getB();
    int getC();
    
    void setA(int side);
    void setB(int side);
    void setC(int side);
    
    bool isEquilateral();
    bool isScalene();
    bool isIsosceles();
    bool isRight();
    
private:
    int sideA, sideB, sideC;
    
    
};









#endif /* Triangle_hpp */
