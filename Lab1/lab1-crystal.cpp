/*
   CS161C+ W19 Week 1
   Programming Lab 01

   Crystal Hall
   08 JAN 2019
*/

#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main()
{
    //Initializing name and age variables
    string name;
    int age;

    //Ask for the name, and receive input.
    cout << "What is your name?\n";
    cin  >> name;

    //Ask for the age, and receive input.
    cout << "What is your age?\n";
    cin  >> age;

    //Print statement with variables.
    cout << "\nYour name is " << name
         << " and your age is " << age
         << ".\n";

    return 0;
}
