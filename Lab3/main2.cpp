//
//  lab3
//
//  Created by Mohammed AlRashid on 1/27/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
// declaring 2 integer variables and char for the operator.
    int num1, num2;
    char ope;
// asking the user to enter 2 integers and choose the operator.
    cout << "Enter two integers to calculate" << endl;
    cin >> num1 >> num2;
    cout << "Enter an operator from the list * / % + -" << endl;
    cin >> ope;
    
    cout << num1 << " " << ope << " " << num2 << " = ";
    // using Switch, defining the operators and what it does.
    switch (ope)
    {
        case'+':
            cout << num1 + num2 << endl;
            break;
        case'-':
            cout << num1 - num2 << endl;
            break;
        case'*':
            cout << num1 * num2 << endl;
            break;
        case'/':
            // If statment to tell the user if they entered 0 on the second number.
            if(num2 == 0)
            {
                cout << "You cannot divide by zero." << endl;
            }
            else
            {
                cout << (num1 / num2) << endl;
            }
            break;
        case'%':
            if(num2 == 0)
            {
                cout << "You cannot divide by zero." <<endl;
            }
            else {
                cout << (num1 % num2) << endl;
            }
            break;
            // if the user doesn't enter a valid operator it sends an error.
        default:
            cout << "That is not a valid operator" << endl;
    }
    return 0;
}
