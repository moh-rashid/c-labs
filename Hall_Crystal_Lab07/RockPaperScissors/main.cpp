/*******************************************
 *                                         *
 * C++ Programming Lab 7 - Part 1          *
 *                                         *
 * Author: Crystal Hall                    *
 * Date: 23 FEB 2019                       *
 *                                         *
 * Rock, paper, scissors game. Player vs.  *
 * computer. The computer randomly chooses *
 * rock, paper, or scissors. It's compared *
 * to the player's choice, and then we     *
 * out who wins.                           *
 *                                         *
 *******************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;

//global constants
char const ROCK = 'r', PAPER = 'p', SCISSORS = 's', YES = 'y', NO = 'n';

//function prototypes
void displayTitle();
void displayInstructions();
char getMove();
char computerMove();
string getChoice(char choice);
int getWinner(char userMove, char compMove);
void printWinner(int winner, char userChoice, char compChoice);
bool playAgain();

//main function
int main()
{
    //display title and clear set of instructions to the user
    displayTitle();
    displayInstructions();
    
    do//go through game once, then see if player wants to go again
    {
        //get user and computer moves
        char userMove = getMove(), compMove = computerMove();
        
        //get and print winner
        printWinner(getWinner(userMove, compMove), userMove, compMove);
    }
    while(playAgain());
    
    return 0;
}

//display title, which will only occur once
void displayTitle()
{
    cout << "\t~~~The Playground Classic's Presents~~~\n"
    << "\t ____ ____ ____ ____\n"
    << "\t||R |||O |||C |||K ||\n"
    << "\t||__|||__|||__|||__||\n"
    << "\t|/__\\|/__\\|/__\\|/__\\|\n"
    << "\t ____ ____ ____ ____ ____\n"
    << "\t||P |||A |||P |||E |||R ||\n"
    << "\t||__|||__|||__|||__|||__||\n"
    << "\t|/__\\|/__\\|/__\\|/__\\|/__\\|\n"
    << "\t ____ ____ ____ ____ ____ ____ ____ ____\n"
    << "\t||S |||C |||I |||S |||S |||O |||R |||S ||\n"
    << "\t||__|||__|||__|||__|||__|||__|||__|||__||\n"
    << "\t|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|\n\n"
    << "\t~~~NOW AVAILABLE FOR COMMAND LINE FUN!~~\n\n\n";
}

//display instructions, which will only occur once
void displayInstructions()
{
    cout << "\tGame Instructions:\n"
    << "\t- Choose rock (r), paper (p), or scissors (s).\n"
    << "\t- Rock (r) defeats scissors (s).\n"
    << "\t- Scissors (s) defeats paper (p).\n"
    << "\t- Paper (p) defeats rock (r).\n"
    << "\t- Have fun!\n\n";
}

//get user's move, and return the result as a char
char getMove()
{
    string userChoice;
    char userMove;
    
    cout << "\tDo you choose ROCK (r), PAPER (p), or SCISSORS (s)!: ";
    cin  >> userChoice;
    
    userMove = tolower(userChoice[0]);
    
    //ask again if user inputs anything other than r, p, or s
    while(userMove != ROCK && userMove != PAPER && userMove != SCISSORS)
    {
        cout << "\tYou can only choose ROCK (r), PAPER (p), or SCISSORS (s): ";
        cin  >> userChoice;
        
        userMove = tolower(userChoice[0]);
    }
    
    return userMove;
}

//get computer's move, and return the result as a char
char computerMove()
{
    //computer's choice will be randomly chosen between 0, 1, 2
    srand(static_cast<unsigned int>(time(NULL)));
    
    int choice = rand() % 3;
    char compChoice;
    
    switch(choice)
    {
        case 0: compChoice = ROCK; break;
        case 1: compChoice = PAPER; break;
        case 2: compChoice = SCISSORS; break;
        default: compChoice = ROCK; break;
    }
    
    return compChoice;
}

//returns string for char choices
string getChoice(char choice)
{
    if(choice == ROCK)
        return "rock";
    else if(choice == PAPER)
        return "paper";
    else//choice == SCISSORS
        return "scissors";
}

//gets winner of the game by returning 1, 2, or 3
int getWinner(char userMove, char compMove)
{
    int winner;
    
    if(userMove == ROCK)
    {
        if(compMove == ROCK)
            winner = 3;
        else if(compMove == PAPER)
            winner = 2;
        else//compMove == SCISSORS
            winner = 1;
    }
    else if(userMove == PAPER)
    {
        if(compMove == PAPER)
            winner = 3;
        else if(compMove == SCISSORS)
            winner = 2;
        else//compMove == ROCK
            winner = 1;
    }
    else//userMove == SCISSORS
    {
        if(compMove == SCISSORS)
            winner = 3;
        else if(compMove == ROCK)
            winner = 2;
        else//compMove == PAPER
            winner = 1;
    }
    
    return winner;
}

//prints final note to player about winner and choices
void printWinner(int winner, char userChoice, char compChoice)
{
    if(winner == 1)
        cout << "\tCongratulations! You are the winner!\n"
        << "\tYou chose " << getChoice(userChoice) << ", which beats computer's "
        << "choice of " << getChoice(compChoice) << ".\n";
    else if(winner == 2)
        cout << "\tThe computer is the winner.\n"
        << "\tComputer chose " << getChoice(compChoice) << ", which beats your "
        << "choice of " << getChoice(userChoice) << ".\n";
    else//winner == 3
        cout << "\tIt's a tie!\n"
        << "\tYou both chose " << getChoice(userChoice) << ".\n";
}

//find out if player wants to play again, and returns true, or false
bool playAgain()
{
    string checkAnswer;
    char userAnswer;
    
    cout << "\tDo you wish to play again? (y/n): ";
    cin  >> checkAnswer;
    cout << "\n\n";
    
    userAnswer = tolower(checkAnswer[0]);
    
    //check if input is yes or no
    while(userAnswer != YES && userAnswer != NO)
    {
        cout << "\tDo you wish to play again? (y/n): ";
        cin  >> checkAnswer;
        cout << "\n";
        
        userAnswer = tolower(checkAnswer[0]);
    }
    
    if(userAnswer == YES)
        return true;
    else//userAnswer == NO
        return false;
}


