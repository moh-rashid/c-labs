/*******************************************
 *                                         *
 * C++ Programming Lab 4 Program 2         *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 3 FEB 2019                        *
 *                                         *
 * Simple program that finds the min and   *
 * max out of an arbitrary amount of       *
 * numbers the user has entered.           *
 * It checks if the user has entered a     *
 * number from 1 to 100. It continues      *
 * the user choose to end the program by   *
 * inputting 0.                            *
 *                                         *
 *******************************************/

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;

int main()
{
    //ints for input and results, also a counter for a check
    //constants replace "magic" numbers
    int userInput, minResult, maxResult = 0, counter = 0;
    int const MIN_INPUT = 1, MAX_INPUT = 100, ERROR_FORMAT = 64, END_PROG = 0;
    bool continueInput = true;//helps break out of main while, and end the program

    //initial intro, and question
    cout << "Enter a set of positive numbers between 1 and 100."
         << "\nWhen you are done, enter 0 to calculate the minimum and maximum.\n";

    cout << "\nInput a positive number (0 to calculate): ";

    //main while that loops until user enters 0
    while(continueInput)
    {
        //main input, and only input if user doesn't trigger an error
        cin >> userInput;

        //Check if the user has entered something other than a positive number between 1 and 100.
        while(cin.fail() || ((userInput < END_PROG || userInput > MAX_INPUT) && userInput != END_PROG))
        {
            //Part of error printout.
            cout << "\t";
            for(int i = 0; i < ERROR_FORMAT; i++)
                cout << '-';

            //Error indication. Number input failed.
            cout << "\n\tERROR: Your input is one of the following:\n"
                 << "\t\t- Not a number.\n"
                 << "\t\t- Less than 1.\n"
                 << "\t\t- More than 100.\n\t";

            //Part of error printout.
            for(int i = 0; i < 64; i++)
                cout << '-';

            //The next two lines make sure we're not stuck in the while loop.
            cin.clear();
            cin.ignore(256, '\n');

            //Ask the question again.
            cout << "\n\nInput a positive number (0 to calculate): ";
            cin  >> userInput;

            //If the user has input a number, continue here to check the number
            if(!cin.fail() && userInput != END_PROG)
            {
                //This will check if the number is less than 1
                if(userInput < MIN_INPUT)
                {
                    //The user has input a negative number (or 0).
                    //Print error format.
                    cout << "\t";
                    for(int i = 0; i < ERROR_FORMAT; i++)
                        cout << '-';

                    //Error indication. Number input failed.
                    cout << "\n\tERROR: Your input is one of the following:\n"
                         << "\t\t- Not a number.\n"
                         << "\t\t- Less than 1.\n"
                         << "\t\t- More than 100.\n\t";

                    //Part of error printout.
                    for(int i = 0; i < 64; i++)
                        cout << '-';

                    //Ask, once again, for a positive number.
                    cout << "\n\nInput a positive number (0 to calculate): ";
                    cin  >> userInput;

                    //At this point the user is just being cheeky.
                    //They have input a letter, or something.
                    //Return to beginning of the while loop to re-check.
                    //It could also be that they want to exit.
                    if(cin.fail())
                        continue;
                    else if(userInput == END_PROG)
                        break;
                }//if(userInput < MIN_INPUT)
            }//if(!cin.fail() && userInput != END_PROG)
        }//cin.fail() || ((userInput < END_PROG || userInput > MAX_INPUT) && userInput != END_PROG))

        /*-----------------------------------
         |  At this stage, the user has     |
         |  input a true positive number    |
         |  between 1 and 100.              |
         |----------------------------------*/

        //Checks if userInput while loop is done, or not.
        bool isDone = false;

        //Player has input a number that is not negative.
        //As long as it's not 0, or done, continue into the while loop.
        while(userInput != END_PROG && !isDone)
        {
            //counter will check if user quit immediately after running
            counter++;

            //if the minimum result is larger than input, change to smaller number
            if(minResult > userInput)
                minResult = userInput;

            //if the maximum result is smaller than input, change to larger number
            if(maxResult < userInput)
                maxResult = userInput;

            //ask the question, cin is above in line 43
            cout << "Input a positive number (0 to calculate): ";
            isDone = true;//done with min and max while loop
        }//while(userInput != END_PROG && !isDone)

        //user has entered 0, wants to end program, and get the result
        if(userInput == END_PROG)
        {
            //checking if the counter is 0
            //if it is, the user quit right after running
            if(counter == 0)
                minResult = 0;

            //provides extra output formatting
            cout << "\n ";

            //formats final result
            for(int i = 0; i < 15; i++)
                cout << '*';

            //prints final result
            cout << "\n MIN RESULT: " << setw(3) << minResult
                 << "\n MAX RESULT: " << setw(3) << maxResult << "\n ";

            //formats final result
            for(int i = 0; i < 15; i++)
                cout << '*';
            cout << "\n";

            //ends program
            continueInput = false;
        }//if(userInput == END_PROG)
    }//while(continueInput)

    return 0;
}
