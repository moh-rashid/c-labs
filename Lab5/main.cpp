#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// define variables.
int sticksTaken = 0, numOfSticks = 11;
int computerChoice;
bool winner = false;

// this generates a random number between 1 and 3.
int generateRandomInt(int numOfSticks){
    if(numOfSticks >= 3){
        computerChoice = rand() % 3 + 1;
    }
    // checks if computer choose more than sticks left
    else if(numOfSticks < 3){
        computerChoice = rand() % numOfSticks + 1;
    }
    return computerChoice;
}

// clears bad input.
void clearOutCin(){
    cin.clear();
    cin.ignore(256, '\n');
}
// prints the sticks
void printSticks(int numOfStickss)
{
    for(int i = 0; i < numOfStickss; i++)
        cout << " |";
}
int printStatment(){
    
    cout << "There are "; printSticks(numOfSticks); cout << " sticks in the pile.\n";
    ///////////////
    if(numOfSticks == 2){
        cout << "Please enter the amount of sticks (1-2) that you want to take out.\n";
        cin >> sticksTaken;
    }
    else if (numOfSticks == 1){
        cout << "Please enter the amount of sticks (1) that you want to take out.\n";
        cin >> sticksTaken;
    }
    else{
        cout << "Please enter the amount of sticks (1-3) that you want to take out.\n";
        cin >> sticksTaken;
    }
    return sticksTaken;
}

int main (){
    srand((unsigned)time(NULL));
    while (numOfSticks != 0) {
        
        printStatment();
        // checks if sticks taken bigger than current number of sticks
        while (sticksTaken > numOfSticks){
            clearOutCin();
            cout << "Oops! There aren't enough sticks left to take this many from the pile.\n";
            printStatment();
        }
        while((sticksTaken < 1) || (sticksTaken > 3)){
            clearOutCin();
            cout << "This is not an acceptable value.\n";
            printStatment();
        }
        
        numOfSticks -= sticksTaken;
        
        if(numOfSticks == 0){
            winner = true;
            cout << "\nYay!!! You won the game of NIM! Congratulations!\n\n";
        }
        else{
            generateRandomInt(numOfSticks);
            //This subtracts the computer's choice of removal sticks from the total sticks in the pile.
            numOfSticks -= computerChoice;
            cout << "\nThe computer has chosen to take away "; printSticks(computerChoice); cout << " sticks from the pile.\n\n";
            
            //If the total number of sticks in the pile reaches 0 during the computer's turn, the computer is declared winner.
            if(numOfSticks == 0){
                winner = true;
                cout << "Awwww darn.  The computer won. Better luck next time!" << endl;
            }
        }
    }
    return 0;
}

