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

    int num1, num2;
    char ope;

    cout << "Enter two integers to calculate" << endl;
    cin >> num1 >> num2;
    cout << "Enter an operator from the list * / % + -" << endl;
    cin >> ope;
    
    switch (ope)
    {
        case'+':
            cout<<num1+num2<<endl;
            break;
        case'-':
            cout<<num1-num2<<endl;
            break;
        case'*':
            cout<<num1*num2<<endl;
            break;
        case'/':
            if(num2==0)
            {
                cout<<"You cannot divide by zero."<<endl;
            }
            else
            {
                cout<<(num1/num2)<<endl;
            }
            break;
        case'%':
            if(num2==0)
            {
                cout<<"You cannot divide by zero."<<endl;
            }
            else {
                cout<<(num1%num2)<<endl; }
            break;
        default:
            cout<<"That is not a valid operator"<<endl;
    }
    return 0;
}
