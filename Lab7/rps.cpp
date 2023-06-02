#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>

using namespace std;

//function prototypes
void displayInstructions();
char getMove();
char compMove();
void getWinner(char compChoice, char playerChoice);
bool playAgain();


// Main Function
int main()
{
    srand( static_cast<unsigned>(time(NULL)));
    char playerChoice;
    char compChoice;
    
    do
    {
        displayInstructions();
        
        playerChoice = getMove();
        compChoice = compMove();
        
        getWinner(compChoice, playerChoice);
        
    } while (playAgain());
}

void displayInstructions()
{
    // display instruction
    cout << "\tGame Instruction\n\n";
    cout << "\t Choose one of the following:\n";
    cout << "Rock, paper, scissors\n\n";
    
    cout << "Scissors is stronger than paper\n"
    << "Paper is stronger than Rock\n"
    << "Rock is stronger than Scisors\n";
}

char getMove()
{
    cout << "Please choose a move: \n(r)Rock\n(p)Paper\n(s)Scissors\n";
    char input;
    cin >> input;
    
    // make input lower case.
    input = tolower(input);
    
    do{
        if ( input != 'r' and input != 'p' and input != 's' ){
            cout << "Invalid Input, Please try again!" << endl;
            cin.clear();
            cin >> input;
        }
    } while(input != 'p' && input != 'r' && input != 's');
    
    return input;
}


char compMove(){
    
    int randNum = rand() % 3 + 1;
    
    if (randNum == 1)
        return 'r';
    else if (randNum == 2)
        return 'p';
    else
        return 's';
}

// Get winner Function.
void getWinner(char compChoice, char playerChoice)
{
    if (compChoice == playerChoice)
        cout << "It's a tie!" << endl;
    else
        if ((compChoice == 'r' && playerChoice == 's') || (compChoice == 'p' && playerChoice == 'r') || (compChoice == 's' && playerChoice == 'p'))
            cout << "The Computer has Won!" << endl;
        else
            cout << "you have WON!! Congratulations!" << endl;
    
}

// play again function.
bool playAgain(){
    char answer;
    cout << "do you want to play again? (Y/N)" << endl;
    cin >> answer;
    answer = tolower(answer);
    
    do{
        if (answer != 'y' && answer != 'n')
        {
            cout << "Invalid Input. Please answer (Y/N)" << endl;
            cin.clear();
            cin >> answer;
            answer = tolower(answer);
        }
    } while ( answer != 'y' && answer != 'n' );
    
    return answer == 'y';
}
