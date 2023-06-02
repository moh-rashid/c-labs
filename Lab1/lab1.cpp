//
//  main.cpp
//  Lab 1
//
//  Created by Mohammed AlRashid on 1/9/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    //we declare first, last name and age.
    string firstName, lastName;
    int age;
    // we ask user for name and age
    cout << "What is your first and last name?" << endl;
    cin >> firstName >> lastName;
    
    cout << "How old are you?" << endl;
    cin >> age;
    cout << "Your name is " << firstName << " " << lastName << " and you are " << age << " years old." << endl;
    
    return 0;
}
