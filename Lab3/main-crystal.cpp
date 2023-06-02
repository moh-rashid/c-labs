/*******************************************
 *                                         *
 * C++ Programming Lab 3                   *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 26 JAN 2019                       *
 *                                         *
 * Simple calculator program that asks the *
 * user for 2 numbers and an operator.     *
 * Checks if the user entered a valid      *
 * operator, and if it's '/', then the 2nd *
 * number should not be 0. It then prints  *
 * an error message, or the result.        *
 *                                         *
 *******************************************/

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setprecision;

int main()
{
    //declare variables for user input and potential result
    int num1, num2;
    double result; //double to accommodate division
    char userOperator;

    //Ask user to input two integers.
    cout << "Enter two integers:\n";

    //Insert user input into integer variables.
    cin  >> num1 >> num2;

    //Ask user to input an operator.
    cout << "Enter an operator from the list */%+-\n";

    //Insert user input into char variable.
    cin  >> userOperator;

    //Is the user operator *,/,%,+,-? If not, print error note.
    if(userOperator != '*' && userOperator != '/' &&
       userOperator != '%' && userOperator != '+' &&
       userOperator != '-')
    {
        cout << "That is not a valid operator.\n";
    }
    //Is the user operator division, and is the second number 0?
    //If yes, print error note.
    else if(userOperator == '/' && num2 == 0)
    {
        cout << "You cannot divide by zero.\n";
    }
    //Is the user input one of the correct operators (and no division by 0)?
    //If yes, check which valid operator the user wants to use, calculate, and print.
    else
    {
        if(userOperator == '*')
        {
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << "\n";
        }
        else if(userOperator == '/')
        {
            result = static_cast<double>(num1) / num2;
            cout << num1 << " / " << num2 << " = " << setprecision(3) << result << "\n";
        }
        else if(userOperator == '%')
        {
            result = num1 % num2;
            cout << num1 << " % " << num2 << " = " << result << "\n";
        }
        else if(userOperator == '+')
        {
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << "\n";
        }
        else//if userOperator is '-'
        {
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << "\n";
        }
    }

    return 0;
}
