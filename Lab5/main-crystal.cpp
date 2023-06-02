/*******************************************
 *                                         *
 * C++ Programming Lab 5 Nim Game          *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 10 FEB 2019                       *
 *                                         *
 * A text-based mathematical strategy game *
 * called Nim. This program has one row of *
 * sticks. The person that grabes the last *
 * stick is the winner.                    *
 * This version of the game can be played  *
 * by two humans, or against the computer. *
 * The computer's decisions are randomly   *
 * chosen. There is also a drawing to see  *
 * which player gets to go first.          *
 *                                         *
 *******************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::toupper;

int const ROW_ONE = 11, /*ROW_TWO_1 = 5, ROW_TWO_2 = 7, ROW_THREE_1 = 3,
          ROW_THREE_2 = 5, ROW_THREE_3 = 7,*/ FIRST_CHAR = 1, THREE_LEFT = 3,
          TWO_LEFT = 2, ONE_LEFT = 1, NONE_LEFT = 0, LIMIT_1 = 1, LIMIT_2 = 2, LIMIT_3 = 3;

string player_one, player_two;
int playerChoice, rowsOfSticks, currentPlayer, numOfSticksLeft1_1, compPickUp,
    playerPickUp, playerRowChoice;
bool checkInputZeroOne = false, computerPlayer = true;//, checkInputSticks = false;


//FUNCTIONS TO REDUCE LENGTH OF PROGRAM
//clear and ignore console input


//print sticks
void printSticks(int numOfSticksLeftForPlayer)
{
    for(int i = 0; i < numOfSticksLeftForPlayer; i++)
        cout << " |";
}

//function to check if player input is valid
int checkPlayerInput(int checkHowManyLeft, int checkPlayerPickUp)
{
    //if there are three sticks left
    if(checkHowManyLeft == THREE_LEFT)
    {
        while(cin.fail() || ((checkPlayerPickUp < LIMIT_1) || (checkPlayerPickUp > LIMIT_3)))
        {
            cout << "\n\tERROR: You must choose between 1, 2, or 3.\n";
            clearOutCin();

            cout << "\n How many sticks (1, 2, or 3)? ";
            cin  >> checkPlayerPickUp;
        }
    }
    //if there are two sticks left
    else if(checkHowManyLeft == TWO_LEFT)
    {
        while(cin.fail() || ((checkPlayerPickUp < LIMIT_1) || (checkPlayerPickUp > LIMIT_2)))
        {
            cout << "\n\tERROR: You must choose between 1 or 2.\n";
            clearOutCin();

            cout << "\n How many sticks (1 or 2)? ";
            cin  >> checkPlayerPickUp;
        }
    }
    //if there is one stick left
    else if(checkHowManyLeft == ONE_LEFT)
    {
        while(cin.fail() || ((checkPlayerPickUp < LIMIT_1) || (checkPlayerPickUp > LIMIT_1)))
        {
            cout << "\n\tERROR: You must choose 1.\n";
            clearOutCin();

            cout << "\n There is only one left. Pick up 1: ";
            cin  >> checkPlayerPickUp;
        }
    }
    return checkPlayerPickUp;
}

//function to print the messages
void printMessageForPlayer(int currPlayer, int numOfSticksLeftForPlayer, bool isComputer)
{
    if(currPlayer == 1)
    {
        cout << "\n\n " << player_one << ", it's your turn."
             << "\n\n The game currently looks like this:\n";

        printSticks(numOfSticksLeftForPlayer);
    }
    else//if currPlayer == 2
    {
        if(isComputer)
        {
            cout << "\n It's now Computer's turn."
                 << "\n\n The game currently looks like this:\n";

            printSticks(numOfSticksLeftForPlayer);
        }
        else//isHuman
        {
            cout << "\n\n " << player_two << ", it's your turn."
                 << "\n\n The game currently looks like this:\n";

            printSticks(numOfSticksLeftForPlayer);
        }
    }
}

//function that returns the number of sticks left after computer "choice"
int computerGeneratedPickUp(int computerLimit, int numOfSticksLeft)
{
    srand(static_cast<unsigned int>(time(NULL)));

    if(computerLimit == LIMIT_1)
    {
        compPickUp = (rand() % computerLimit) + 1;
        numOfSticksLeft -= compPickUp;
    }
    else if(computerLimit == LIMIT_2)
    {
        compPickUp = (rand() % computerLimit) + 1;
        numOfSticksLeft -= compPickUp;
    }
    else//computerLimit == LIMIT_3
    {
        compPickUp = (rand() % computerLimit) + 1;
        numOfSticksLeft -= compPickUp;
    }

    return numOfSticksLeft;
}

//main function where the magic happens
int main()
{
    //intro to game
    for(int i = 0; i < 36; i++)
        cout << "*-";

    cout << "*\n\t __    __     _\t\t\t\t\t _\n"
         << "\t/ / /\\ \\ \\___| | ___ ___  _ __ ___   ___\t| |_ ___\n"
         << "\t\\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\\t| __/ _ \\\n"
         << "\t \\  /\\  /  __/ | (_| (_) | | | | | |  __/\t| || (_) |\n"
         << "\t  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|\t \\__\\___/\n\n"
         << "\t\t   ____  _____   _____   ____    ____   _\n"
         << "\t\t  |_   \\|_   _| |_   _| |_   \\  /   _| | |\n"
         << "\t\t    |   \\ | |     | |     |   \\/   |   | |\n"
         << "\t\t    | |\\ \\| |     | |     | |\\  /| |   |_|\n"
         << "\t\t   _| |_\\   |_   _| |_   _| |_\\/_| |_   _\n"
         << "\t\t  |_____|\\____| |_____| |_____||_____| |_|\n\n";

    for(int i = 0; i < 36; i++)
        cout << "*-";

    cout << "*\n\n\t    -- The original mathematical strategy game. --\n\n"
         << "\n   Players will take turns removing 1, 2, or 3 sticks from the "
         << "pile.\n\t\tThe player removing the last stick wins!\n\n";

    for(int i = 0; i < 36; i++)
        cout << "*-";

    //first question to user(s)
    cout << "*\n\n\tHuman vs. Human (0)\tOR\tHuman vs. Computer (1)\n\n"
         << " Human (0) or Computer (1): ";

    //checks if the user has chosen a 0 or 1
    while(!checkInputZeroOne)
    {
        cin >> playerChoice;

        while(cin.fail() || ((playerChoice != 0) && (playerChoice != 1)))
        {
            cout << "\n\tERROR: You must choose between 0 or 1.\n";
            clearOutCin();

            cout << "\n Human (0) or Computer (1): ";
            cin  >> playerChoice;
        }

        checkInputZeroOne = true;
    }

    //if there are 2 humans joining the game
    if(playerChoice == 0)
    {
        computerPlayer = false;

        cout << "\n -Player 1-\n Enter your name: ";
        cin  >> player_one;

        cout << "\n -Player 2-\n Enter your name: ";
        cin  >> player_two;
    }
    else//playerChoice == 1, if it's human vs. machine
    {
        cout << "\n Enter your name: ";
        cin  >> player_one;

        player_two = "Computer";
    }

    //randomly choose which player goes first
    srand(static_cast<unsigned int>(time(NULL)));
    currentPlayer = (rand() % 2) + 1;

    //let player know who is first
    //  replace all he if statment with cout << currentPlayer << .....
    if(currentPlayer == 1)
        cout << "\n " << player_one << " has won the draw. It's your turn!\n";
    else if(currentPlayer == 2)
    {
        if(!computerPlayer)
            cout << "\n " << player_two << " has won the draw. It's your turn!\n";
        else
            cout << "\n " << player_two << " has won the draw.\n";
    }

    numOfSticksLeft1_1 = ROW_ONE;
    cout << "\n The game currently looks like this:\n";

    printSticks(numOfSticksLeft1_1);

    //Checking that the row isn't empty
    while(numOfSticksLeft1_1 != NONE_LEFT)
    {
        //Checking if the row has 3 or more.
        if(numOfSticksLeft1_1 >= THREE_LEFT)
        {
            //Check if player is going against the computer
            if(computerPlayer)
            {
                //Check if the current player is 1, or 2
                if(currentPlayer == 1)
                {
                    //There are 3 or more sticks, so user can choose 1, 2, or 3
                    cout << "\n\n How many sticks would you like to remove (1, 2, or 3)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(THREE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_one << ", you win!\n";
                    else
                    {
                        currentPlayer = 2;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if(currentPlayer == 1)
                else//if currentPlayer == 2
                {
                    numOfSticksLeft1_1 = computerGeneratedPickUp(LIMIT_3, numOfSticksLeft1_1);

                    if(compPickUp == 1)
                        cout << "\n\n Computer removed " << compPickUp << " stick.";
                    else
                        cout << "\n\n Computer removed " << compPickUp << " sticks.";

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n\n Computer wins the game.\n";
                    else
                    {
                        currentPlayer = 1;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if currentPlayer == 2
            }//if Human vs. Computer
            else//Human vs. Human with one row
            {
                //Human 1
                if(currentPlayer == 1)
                {
                    cout << "\n\n How many sticks would you like to remove (1, 2, or 3)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(THREE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_one << ", you win!\n";
                    else
                    {
                        currentPlayer = 2;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if currentPlayer == 1
                //Human 2
                else//if currentPlayer == 2
                {
                    cout << "\n\n How many sticks would you like to remove (1, 2, or 3)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(THREE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_two << ", you win!\n";
                    else
                    {
                        currentPlayer = 1;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if currentPlayer == 2
            }//Human vs. Human with one row
        }//if there are 3 or more sticks left
        //checking if the row has 2 sticks left
        else if(numOfSticksLeft1_1 == TWO_LEFT)
        {
            //Check if player is going against the computer
            if(computerPlayer)
            {
                //Check if the current player is 1, or 2
                if(currentPlayer == 1)
                {
                    //There are 2 sticks, so user can only choose 1, or 2
                    cout << "\n\n How many sticks would you like to remove (1 or 2)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(TWO_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_one << ", you win!\n";
                    else
                    {
                        currentPlayer = 2;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if(currentPlayer == 1)
                else//if currentPlayer == 2
                {
                    numOfSticksLeft1_1 = computerGeneratedPickUp(LIMIT_2, numOfSticksLeft1_1);

                    if(compPickUp == 1)
                        cout << "\n\n Computer removed " << compPickUp << " stick.";
                    else
                        cout << "\n\n Computer removed " << compPickUp << " sticks.";

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n\n Computer wins the game.\n";
                    else
                    {
                        currentPlayer = 1;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }
            }//if Human vs. Computer
            else//Human vs. Human with one row
            {
                //Human 1
                if(currentPlayer == 1)
                {
                    //There are 2 sticks, so user can only choose 1, or 2
                    cout << "\n\n How many sticks would you like to remove (1 or 2)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(TWO_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_one << ", you win!\n";
                    else
                    {
                        currentPlayer = 2;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }//if currentPlayer == 1
                //Human 2
                else//if currentPlayer == 2
                {
                    //There are 2 sticks, so user can only choose 1, or 2
                    cout << "\n\n How many sticks would you like to remove (1 or 2)? ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(TWO_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    if(numOfSticksLeft1_1 == 0)
                        cout << "\n Congratulations " << player_two << ", you win!\n";
                    else
                    {
                        currentPlayer = 1;
                        printMessageForPlayer(currentPlayer, numOfSticksLeft1_1, computerPlayer);
                    }
                }
            }////Human vs. Human with one row
        }//else if(numOfSticksLeft1_1 == TWO_LEFT)
        //checking if the row has 1 stick left
        else if(numOfSticksLeft1_1 == ONE_LEFT)
        {
            //Check if player is going against the computer
            if(computerPlayer)
            {
                //Check if the current player is 1, or 2
                if(currentPlayer == 1)
                {
                    //There is only 1 stick, so user can only choose 1
                    cout << "\n\n There is only one stick left. Pick up 1: ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(ONE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    cout << "\n Congratulations " << player_one << ", you win!\n";
                }
                else
                {
                    numOfSticksLeft1_1 = computerGeneratedPickUp(LIMIT_1, numOfSticksLeft1_1);

                    cout << "\n\n Computer removed " << compPickUp << " stick."
                         << "\n\n Computer wins the game.\n";
                }
            }//Human vs. Computer
            else//Human vs. Human
            {
                //Human 1
                if(currentPlayer == 1)
                {
                    //There is only 1 stick, so user can only choose 1
                    cout << "\n\n There is only one stick left. Pick up 1: ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(ONE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    cout << "\n Congratulations " << player_one << ", you win!\n";
                }//if currentPlayer == 1
                //Human 2
                else//if currentPlayer == 2
                {
                    //There is only 1 stick, so user can only choose 1
                    cout << "\n\n There is only one stick left. Pick up 1: ";
                    cin  >> playerPickUp;

                    playerPickUp = checkPlayerInput(ONE_LEFT, playerPickUp);

                    numOfSticksLeft1_1 -= playerPickUp;

                    cout << "\n Congratulations " << player_two << ", you win!\n";
                }
            }
        }//else if(numOfSticksLeft1_1 == ONE_LEFT)
    }//while(numOfSticksLeft1_1 != NONE_LEFT)
    cout << "\n ***Thank you for playing NIM!***\n";

    return 0;
}
