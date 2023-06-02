/*******************************************
 *                                         *
 * C++ Programming Lab 7 - Part 2          *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 23 FEB 2019                       *
 *                                         *
 * Guess My Number game. Player has to     *
 * guess the number that has been randomly *
 * generated. The player will be notified  *
 * if their guess is too high, or too low. *
 *                                         *
 *******************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;

//global constants
int const RAND_MINIMUM = 1, RAND_MAXIMUM = 99;
char const YES = 'y', NO = 'n';

//function prototypes
void displayTitle();
void displayInstructions();
int getNumber(int minInput = RAND_MINIMUM, int maxInput = RAND_MAXIMUM);
void clearOutCin();
int getMove(int minInput = RAND_MINIMUM, int maxInput = RAND_MAXIMUM);
int checkGuessValid(int guess, int minInput = RAND_MINIMUM, int maxInput = RAND_MAXIMUM);
bool playAgain();

//main function
int main()
{
    //display title and instructions; will occur only once
    displayTitle();
    displayInstructions();

    do
    {
        //get random number, and set up userGuess & counter
        int randomNumber = getNumber();
        int userGuess;
        int numberOfGuessNeeded = 0;

        do
        {
            //get user's guess, and add to counter
            userGuess = getMove();
            numberOfGuessNeeded++;

            //check if userGuess equals random number, or not
            if(userGuess != randomNumber)
            {
                //if not, then check if guess is too low, or too high
                if(userGuess < randomNumber)
                    cout << " Your number is too low. Guess again.\n";
                else//userGuess > randomNumber
                    cout << " Your number is too high. Guess again.\n";
            }
            else//user's guess is spot on
                cout << " You guessed it! It's " << userGuess << "!\n"
                     << " It took you " << numberOfGuessNeeded << " tries before you got the answer.\n";
        }
        while(userGuess != randomNumber);//continue until user has guess correctly
    }
    while(playAgain());//continue if player wishes to play again

    return 0;
}

//display title, which will only occur once
void displayTitle()
{
    cout << "  #####                                       #     #\n"
         << " #     #  #    #  ######   ####    ####       ##   ##  #   #\n"
         << " #        #    #  #       #       #           # # # #   # #\n"
         << " #  ####  #    #  #####    ####    ####       #  #  #    #\n"
         << " #     #  #    #  #            #       #      #     #    #\n"
         << " #     #  #    #  #       #    #  #    #      #     #    #\n"
         << "  #####    ####   ######   ####    ####       #     #    #\n\n"
         << "\t #     #                                           #\n"
         << "\t ##    #  #    #  #    #  #####   ######  #####    #\n"
         << "\t # #   #  #    #  ##  ##  #    #  #       #    #   #\n"
         << "\t #  #  #  #    #  # ## #  #####   #####   #    #   #\n"
         << "\t #   # #  #    #  #    #  #    #  #       #####    #\n"
         << "\t #    ##  #    #  #    #  #    #  #       #   #\n"
         << "\t #     #   ####   #    #  #####   ######  #    #   #\n\n";
}

//display instructions, which will only occur once
void displayInstructions()
{
    cout << " Game Instructions:\n"
         << "   The computer will generate a random number between 1 and 99,\n"
         << "   and you will have to guess what the number is.\n"
         << "   You'll get hints if your guess is too high, or too low, but keep\n"
         << "   in mind, your guesses will be counted!\n\n Good luck!\n\n";
}

//inputs are min and max, returns a random number between min and max
int getNumber(int minInput, int maxInput)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int randomNumber = (rand() % maxInput) + minInput;

    return randomNumber;
}

//clear and ignore console input
void clearOutCin()
{
    cin.clear();
    cin.ignore(256, '\n');
}

//inputs are min and max, gets, validates, returns an int from user between
//min and max
int getMove(int minInput, int maxInput)
{
    int userGuess;

    cout << " Enter a number between 1 - 99: ";
    cin  >> userGuess;
    userGuess = checkGuessValid(userGuess, minInput, maxInput);

    return userGuess;
}

//validation function; check if user has input a number & it's between 1 - 99
int checkGuessValid(int guess, int minInput, int maxInput)
{
    while(cin.fail() || ((guess < minInput) || (guess > maxInput)))
    {
        cout << " INVALID INPUT!";
        clearOutCin();

        cout << " Enter a number between 1 - 99: ";
        cin >> guess;
    }

    return guess;
}

//find out if player wants to play again, and returns true, or false
bool playAgain()
{
    string checkAnswer;
    char userAnswer;

    cout << " Do you wish to play again? (y/n): ";
    cin  >> checkAnswer;

    userAnswer = tolower(checkAnswer[0]);

    //check if input is yes or no
    while(userAnswer != YES && userAnswer != NO)
    {
        cout << " Do you wish to play again? (y/n): ";
        cin  >> checkAnswer;
        cout << "\n";

        userAnswer = tolower(checkAnswer[0]);
    }

    if(userAnswer == YES)
        return true;
    else//userAnswer == NO
        return false;
}
