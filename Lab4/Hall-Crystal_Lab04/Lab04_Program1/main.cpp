/*******************************************
 *                                         *
 * C++ Programming Lab 4 Program 1         *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 2 FEB 2019                        *
 *                                         *
 * Simple factorization program that       *
 * prompts the user to input one positive  *
 * number. It checks if the user has       *
 * entered a positive, and if they have,   *
 * then it proceeds to print out the       *
 * results. It offers the user a way to    *
 * exit the program, and provides an error *
 * message if the user has input something *
 * other than a positive number.           *
 *                                         *
 *******************************************/

#include <iostream>

using std::cout;
using std::cin;

int main()
{
    //Thought about using unsigned, but it would never be a negative #.
    long int posNum;
    int const LARGE_NUM = 25000000, ERROR_FORMAT = 64, END_PROG = 0;

    //First time asking the question:
    cout << "Input a positive number (0 to exit): ";
    cin  >> posNum;

    //Check if the user has entered something other than a positive number.
    //cin.fail() is for anything not a number.
    //posNum < END_PROG is for anything less than 1.
    //posNum != END_PROG is for exiting the program. If it's not 0, continue checking.
    while(cin.fail() || (posNum < END_PROG && posNum != END_PROG))
    {

        //Part of error printout.
        cout << "\t";
        for(int i = 0; i < ERROR_FORMAT; i++)
            cout << '-';

        //Error indication. Number input failed.
        cout << "\n\tERROR: Your input is one of the following:\n"
             << "\t\t- Not a number.\n"
             << "\t\t- Not a positive number.\n"
             << "\t\t- Larger than 2,147,483,647.\n\n"
             << "\tIf it's the latter, we apologize for the limits of this program.\n\t";

        //Part of error printout.
        for(int i = 0; i < ERROR_FORMAT; i++)
            cout << '-';

        //The next two lines make sure we're not stuck in the while loop.
        cin.clear();
        cin.ignore(256, '\n');

        //Ask the question again.
        cout << "\n\nInput a positive number (0 to exit): ";
        cin  >> posNum;

        //If the user has input a number, continue here to check the number
        if(!cin.fail() && posNum != END_PROG)
        {
            //This will check if the number is less than 1
            if(posNum < 1)
            {
                //The user has input a negative number (or 0).
                //Print error format.
                cout << "\t";
                for(int i = 0; i < ERROR_FORMAT; i++)
                    cout << '-';

                //Error indication. Number input failed.
                cout << "\n\tERROR: Your input is one of the following:\n"
                     << "\t\t- Not a number.\n"
                     << "\t\t- Not a positive number.\n"
                     << "\t\t- Larger than 2,147,483,647.\n\n"
                     << "\tIf it's the latter, we apologize for the limits of this program.\n\t";

                //Part of error printout.
                for(int i = 0; i < ERROR_FORMAT; i++)
                    cout << '-';

                //Ask, once again, for a positive number.
                cout << "\n\nInput a positive number (0 to exit): ";
                cin  >> posNum;

                //At this point the user is just being cheeky.
                //They have input a letter, or something.
                //Return to beginning of the while loop to re-check.
                //It could also be that they want to exit.
                if(cin.fail())
                    continue;
                else if(posNum == END_PROG)// 0
                    break;
            }//if(posNum < 1)
        }//if(!cin.fail() && posNum != 0)
    }//while(cin.fail() || (posNum < 0 && posNum != 0))

    //Checks if pos num while loop is done, or not.
    bool isDone = false;

    //Checks if posNum is a whole number
    double checkWithInt;
    long int checkWithDouble;

    //Checks how many divisors there are.
    int divisors = 0;

    //Player has input a number that is not negative.
    //As long as it's not 0, or done, continue into the while loop.
    while(posNum != END_PROG && !isDone)
    {
        //Check how large the number is, and warn of decrease in speed.
        if(posNum > LARGE_NUM)
            cout << "\n\t***ALERT***\n\tLarge number alert. Please wait. System processing...\n\n";

        //iterate to find all factors of posNum
        for(long int i = posNum; i >= 1; i--)
        {
            checkWithInt = static_cast<double>(posNum) / i;//result will either be a whole number, or not
            checkWithDouble = posNum / i;//result will always be a whole number

            //Checks if the double is a whole number.
            if(checkWithInt == checkWithDouble)
            {
                //Check if it's the last number.
                if(i != 1)
                {
                    cout << checkWithInt << ", ";
                    divisors++;
                }
                else
                {
                    cout << checkWithInt << "\n\n";
                    divisors++;
                    cout << "There are " << divisors << " divisors.\n";
                    isDone = true;//needed to avoid infinite loop
                }//if(i != 1)
            }//if(checkWithInt == checkWithDouble)
        }//for(int i = posNum; i >= 1; i--)
    }//while(posNum != 0 && !isDone)

    if(posNum == END_PROG)// 0
        cout << "\n***Program aborted.***\n";

    return 0;
}
