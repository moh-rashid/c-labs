#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

//defining constents.
const int tooHigh = 100;
const char endOfL = '\n';
const int HIGH = 99;
const int LOW = 1;

// function prototypes
void showInstructions();
int setNumber();
int getGuess();
bool playAgain();

// Main FUnction
int main()
{
    // SEED Rand()
    srand( static_cast<unsigned>(time( NULL )) );
    
    // defining variables
    int number, guess;
    
    // loop untill player don't want to play anymore.
    do {
        // displaying instructions.
        showInstructions();
        
        // assign variable to setNumber function call
        number = setNumber();
        // setting count variable for how many tries.
        int count = 0;
        do {
            // set guess variable to function call.
            guess = getGuess();
            
            // check if too low or too high.
            if ( guess < number ){
                cout << "Too low!" << endl;
            }
            if ( guess > number ){
                cout << " Too high!" << endl;
            }
            // increase count num.
            count++;
            
        } while ( number != guess );
        
        cout << "You Got It!! It took you " << count << " guesses." << endl;
        
    } while (playAgain());
    
    return 0;
}
// fix input error.
void inputReset(){
    cin.clear();
    cin.ignore(tooHigh, endOfL);
}

// output instructiouns
void showInstructions() {
    cout << "..Guess My Number Game.." << endl;
    cout << "Choose a number between 1 and 99." << endl;
    cout << "then keep tring to guess until you get the correct answer." << endl;
    cout << "The computer will tell you if you are too high or too low." << endl;
}
// set the computer Move.
int setNumber() {
    
    return rand() % HIGH + LOW;
}

// ask user to input number.
int getGuess()
{
    // input variable
    int guess;
    cin >> guess;
    
    // check user input.
    do {
        if (guess < LOW || guess > HIGH) {
            cout << "Invalid input, Please try again " << endl;
            inputReset();
            cin >> guess;
        }
    } while (guess < LOW || guess > HIGH);
    
    return guess;
}

// check if player want to play again.
bool playAgain() {
    
    char answer;
    cout << "Would you like to play again? (Y/N) " ;
    cin >> answer;
    answer = tolower(answer);
    
    do{
        if (answer != 'y' && answer != 'n')
        {
            cout << "Invalid input, Would you like to play again? (Y/N)." << endl;
            inputReset();
            cin >> answer;
            answer = tolower(answer);
        }
    } while ( answer != 'y' && answer != 'n' );
    
    return answer == 'y';
}

