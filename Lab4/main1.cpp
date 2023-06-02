//
//  main.cpp
//  factors
//
//  Created by Mohammed AlRashid on 2/3/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // assigning variables:
    int userInput, i;
    char answer;
    bool playAgain = true;
    // while loop to restart
    while (playAgain == true) {
        cout << "Enter a positive integer: " << endl;
        cin >> userInput;
        
        // checks to see if input is larger than 0.
        if(userInput > 0){
            cout << "Factors of " << userInput << " are: " << endl;
            // Factors formula using a for loop
            for(i = 1; i <= userInput; ++i){
                
                if(userInput % i == 0)
                    cout << i << endl;
            }
        }
        // checks if user entered an invalid value.
        else if(!cin){
            cout << "You have entered an invalid value, ";
            cin.clear();
            cin.ignore(256,'\n');
        }
        // anything else is invalid value.
        else{
            cout << "You have entered an invalid value, ";
        }
        // asks if user want to restary
        cout << "Do you want to Repeat? [y/n]" << endl;
        cin >> answer;
        if (answer == 'n'){
            playAgain = false;
        }
    }
    
    cout << "Thank you, Goodbye" << endl;
    
    return 0;
}
