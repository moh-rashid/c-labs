//
//  main.cpp
//  lab3
//
//  Created by Mohammed AlRashid on 1/27/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {

    double salePrice, comm;
    
    cout << "Enter Sale Price." << endl;
    cin >> salePrice;
    
    if (salePrice < 100000)
    {
        comm = salePrice * 0.05;
    }
    else if (salePrice > 100000 and salePrice < 300000)
    {
        comm = salePrice * 0.10 + 5000;
    }
    else
    {
        comm = salePrice * 0.15 + 25000;
    }
    cout << "the Sale price is " << salePrice << " and commision is " << comm << "\n" << endl;
    
    
    return 0;
}
