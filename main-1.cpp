#include <iostream>
#include <iomanip>
#include <ctime>
#include <locale>
#include <cstdlib>

using namespace std;

/********** global constants **********/

// array size
const int MAX_ROW = 10; const int MAX_COL = 10;

// Character
enum characters:char{
    SPACE = '.',
    TRAP = '#',
    PLAY = '@',
    CASH = '$',
    //  bonus = '?',
    //  monster = '&'
    YES = 'Y',
    NO = 'N'
};
// Controls
enum controls:char{
    UP = 'U',
    DOWN = 'D',
    LEFT = 'L',
    RIGHT = 'R'
};

/*********************** Function Prototype ***************************/

void clearOutCin(); // Clears out bad input
void displayInstructions(); // displays the instructions
void initDungeon(char dungeonArray[][MAX_COL],int &currentROW,int &currentCOL,int &gameState,int =6); // initialize game, 5th argument: traps number(optinal)
void displayDungeon(char dungeonArray[][MAX_COL]); // display the current dungeon state
char getMove(char dungeonArray[][MAX_COL],int currentROW,int currentCOL); // gets a valid move (L,R,U,D)
int checkMove(char dungeonArray[][MAX_COL],int ROW,int COL); // sees if move is onto checkCode object
void movePlayer(char dungeonArray[][MAX_COL],int &currentROW,int &currentCOL,char moveDiraction);
void updateDungeon(char dungeonArray[][MAX_COL],int currentROW,int currentCOL); // update the dungeon for next move
bool repeat(); // do you want to play again?

/**************************************
 *                                    *
 *          Main Function             *
 *                                    *
 *************************************/
int main(){
    /**** Defining Variables ****/
    int currentROW, currentCOL, gameState;
    char dungeon[MAX_ROW][MAX_COL], move; // Dungeon Array
    bool repeatGame;
    /*********************** Start Game ***************************/
    do{
        
        displayInstructions();
        initDungeon(dungeon, currentROW, currentCOL, gameState); // Resets Game to begining
        do{ // loop while game still going
            displayDungeon(dungeon);
            
            move = getMove(dungeon, currentROW, currentCOL); // get move from user and validate
            
            movePlayer(dungeon, currentROW, currentCOL, move); // changing current ROW & COL to corresponding box
            gameState = checkMove(dungeon, currentROW, currentCOL); // Game Progress check
            updateDungeon(dungeon, currentROW, currentCOL); // Updates the array after changes
        } while(gameState == 2);
        
        /*********************** End Game ***************************/
        if(gameState == 1) // Winner Massege
            cout << "Congratulations! You Win! ";
        else if(gameState == 0) // Loser Massege
            cout << "Darn it! Better Luck Next Time! ";
        else
            cout << "Error: Winner? or not?" << endl; // FOR DEBUGING
        repeatGame = repeat();
    }while(repeatGame == true); // Playing again
    /*********************** End Program ***************************/
    cout << "Thank you for playing, Goodbye!" << endl;
    
    return 0;
}

/******************************************************
 *                                                    *
 *                   CLEAR OUT CIN                    *
 *                                                    *
 ******************************************************/
void clearOutCin(){
    cin.clear();
    cin.ignore(256, '\n');
}

/******************************************************
 *                                                    *
 *              displays the instructions             *
 *                                                    *
 ******************************************************/
void displayInstructions(){
    cout << "*** Dungeon Crawl Game ***" << endl;
}

/******************************************************
 *                                                    *
 *              Initializng The Game                  *
 *             numTraps Argument Optional             *
 ******************************************************/
void initDungeon(char dungeonArray[][MAX_COL], int &currentROW, int &currentCOL, int &gameState,int numTraps){
    // Rand() seed
    srand(static_cast<unsigned int>(time(NULL)));
    /*************************** Variable Init ***************************/
    currentROW=0; currentCOL=0; gameState = 0;
    int randomSpawnRow, randomSpawnCol;
    
    
    /*************************** Empty space init ***************************/
    for(int i=0; i < MAX_ROW; i++){
        for(int j=0; j < MAX_COL; j++){
            dungeonArray[i][j] = SPACE;
        }
    }
    
    /*************************** Traps Spawn ***************************/
    for(int i=0; i < numTraps; i++){
        do{
            randomSpawnRow = rand() % MAX_ROW + 1;
            randomSpawnCol = rand() % MAX_COL + 1;
            
        }while(dungeonArray[randomSpawnRow][randomSpawnCol] != SPACE); // loop to retry if not possible to spawn
        dungeonArray[randomSpawnRow][randomSpawnCol] = TRAP;
    }
    
    /*************************** Cash Spawn ***************************/
    do{
        randomSpawnRow = (rand() % 3 + 1) + 7; // makes sure it spawns in the Last 3 ROWS
        randomSpawnCol = rand() % MAX_COL + 1;
    }while(dungeonArray[randomSpawnRow][randomSpawnCol] != SPACE);  // only if Empty
    dungeonArray[randomSpawnRow][randomSpawnCol] = CASH;
    
    /*********************** Player Spawn ***************************/
    do{
        currentROW = rand() % 3 + 1; // makes sure it spawns in the First 3 ROWS
        currentCOL = rand() % MAX_COL + 1;
    }while(dungeonArray[currentROW][currentCOL] != SPACE); // only if empty
    dungeonArray[currentROW][currentCOL] = PLAY;
}


/******************************************************
 *                                                     *
 *         display the current dungeon state           *
 *                                                     *
 ******************************************************/
void displayDungeon(char dungeonArray[][MAX_COL]){
    for(int i=0; i < MAX_ROW; i++){
        for(int j=0; j < MAX_COL; j++){
            cout << setw(3) << dungeonArray[i][j];
        }
        cout << endl;
    }
}

/*******************************************************
 *           gets a valid move (L,R,U,D)               *
 *  Returns: Char Player Move                          *
 *  TODO:                                              *
 *[ ]Accept input without hitting enter and use Arrows *
 ******************************************************/
char getMove(char dungeonArray[][MAX_COL],int currentROW,int currentCOL){
    /***************** variables *******************/
    char move;
    bool boardDimensions, isInputCorrect;
    
    do{
        cout << "Please Choose your move. (U,D,L,R)" << endl;
        cin >> move;
        move = toupper(move);
        
        /***************** Boolean check *******************/
        boardDimensions = !((currentROW==0 && move==UP ) || (currentROW==(MAX_ROW-1) && move==DOWN) || (currentCOL==0 && move==LEFT) || (currentCOL==(MAX_COL-1) && move==RIGHT));
        isInputCorrect = ( (move == UP or move == DOWN or move == LEFT or move == RIGHT) and !cin.fail() );
        
        if (boardDimensions == false){
            clearOutCin();
            cout << "Invalid Move, ";
            cout<< "Current Location: " << currentROW << " " << currentCOL << endl; // debuging
        }
        else if(isInputCorrect == false){
            clearOutCin();
            cout << "You have entered an Invalid value, " << endl;
            cout << isInputCorrect << endl;
        }
        
    }while(boardDimensions == false || isInputCorrect == false);
    return move;
}

/*****************************************************
 *                  Game Status Check                *
 *  returns: 1=WIN, 0=Lose,  2=no win no lose        *
 *                                                   *
 *****************************************************/
int checkMove(char dungeonArray[][MAX_COL],int currentROW,int currentCOL){
    /**** Variable Definition ****/
    char currentLocation = dungeonArray[currentROW][currentCOL];
    
    /**** game status check ****/
    if (currentLocation == TRAP) // Check Trap
        return 0;
    else if (currentLocation == CASH) // Check Win
        return 1;
    else if(currentLocation == SPACE) // Check playing
        return 2;
    else{
        cout << "error: checking Win." << dungeonArray[currentROW][currentCOL] << endl; // FOR DEBUGING.
        return 0;
    }
}

/**************************************
 *                                    *
 *        Move Player Function        *
 * TODO:                              *
 *************************************/
void movePlayer(char dungeonArray[][MAX_COL],int &currentROW,int &currentCOL,char moveDiraction){
    
    dungeonArray[currentROW][currentCOL] = SPACE; // Erasing previous move
    
    /*********************** Assigning Diraction ***********************/
    switch(moveDiraction){
        case UP:    --currentROW; break;
        case DOWN:  ++currentROW; break;
        case LEFT:  --currentCOL; break;
        case RIGHT: ++currentCOL; break;
    }
}

/**************************************
 *  update the dungeon for next move  *
 *
 *
 *************************************/
void updateDungeon(char dungeonArray[][MAX_COL],int ROW,int COL){
    
    // erase past char
    dungeonArray[ROW][COL] = SPACE;
    // move player
    
    dungeonArray[ROW][COL] = PLAY;
}

/**************************************
 *  do you want to play again?  *
 *  returns:
 *
 *************************************/
bool repeat(){
    char answer;  bool answerCheck;
    
    do{
        cout << "Do you want to play again?" << endl;
        cin >> answer;
        answer = toupper(answer);
        answerCheck = (answer == YES or answer == NO);
        if(answerCheck == false){
            cout << "Invalid Input, ,";
            continue;
        }
    
    }while(answerCheck == false);
    
    if (answer == YES)
        return true;
    return false;
}
