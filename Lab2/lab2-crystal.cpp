/*******************************************
 *                                         *
 * C++ Programming Lab 2                   *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 19 JAN 2019                       *
 *                                         *
 * Simple math program that generates      *
 * 2 numbers for the user to add together. *
 * Prints out actual sum in proper format. *
 *                                         *
 *******************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::setw;

int main()
{
    //Seed random # generator to change random values.
    srand(time(0));

    //Generate two random int between 1-99.
    int randomNum1 = (rand() % 99) + 1;
    int randomNum2 = (rand() % 99) + 1;

    //Sum variables (user input & sum to be printed).
    int userSum, actualSum;

    //Ask user to input sum.
    cout << "What is the sum of " << randomNum1
         << " and " << randomNum2 << "?\n";
    cin  >> userSum;

    //Get the actual sum of the two random #s
    actualSum = randomNum1 + randomNum2;

    //Print the result in proper format using setw(#)
    cout << "\n" << setw(3) << randomNum1 << "\n+"
         << setw(2) << randomNum2 << "\n---\n"
         << setw(3) << actualSum << "\n";

    return 0;
}
