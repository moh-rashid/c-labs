#include <iostream>

#include <stdlib.h>

#include <time.h>

using namespace std;

// struct definition
struct Location{
    
    int row,col;
};

// function declaration

int* initBoard();

void printBoard(int *board,bool *userBoard, Location *l1);

void printBoard(int *board, bool *userBoard,Location *l1,Location *l2);

Location* input();

void updateBoard(int *board, bool *userBoard, Location *l1, Location *l2,int &space);

int main() {
    
    srand(time(NULL));
    
    bool userBoard[16];
    
    for(int i=0;i<16;i++)
        
        userBoard[i] =false;
    
    int *board = initBoard();
    
    int countMoves = 0;
    
    int countSpace = 0;
    
    while(countSpace < 16)
        
    {
        
        cout<<" Enter the first location "<<endl;
        
        Location *l1 = input();
        
        printBoard(board,userBoard,l1);
        
        cout<<" Enter the second location "<<endl;
        
        Location *l2 = input();
        
        printBoard(board,userBoard,l1,l2);
        
        updateBoard(board,userBoard,l1,l2,countSpace);
        
        countMoves++;
        
    }
    
    cout<<" Total number of moves required : "<<countMoves<<endl;
    
    return 0;
    
}

// function to init the board

int* initBoard(){
    
    int *arr = new int[16];
    
    //printBoard(arr,4,4);
    
    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            int ind = rand()%16;

            while(arr[ind] != 0){
                
                ind = rand()%16;
            }
            
            arr[ind] = (i+1);
        }
    }
    
    return arr;
    
}

// function to print the board

void printBoard(int *board,bool *userBoard, Location *l1){
    
    cout<<" Board : "<<endl;
    
    for(int i=0;i<4;i++) {
        
        for(int j=0;j<4;j++){
            
            if(userBoard[4*i+j])
                cout<<" ";
            
            else if(i == l1->row && j == l1->col)
                cout<<board[4*i+j]<<" ";
            
            else
                cout<<"X ";
        }
        
        cout<<endl;
    }
}

// function to print the board

void printBoard(int *board, bool *userBoard,Location *l1,Location *l2)

{
    
    cout<<" Board : "<<endl;
    
    for(int i=0;i<4;i++)
        
    {
        
        for(int j=0;j<4;j++)
            
        {
            
            if((i == l1->row && j == l1->col) || (i == l2->row && j == l2->col))
                
                cout<<board[4*i+j]<<" ";
            
            else if(userBoard[4*i+j])
                
                cout<<" ";
            
            else
                
                cout<<"X ";
            
        }
        
        cout<<endl;
        
    }
    
}

// function to take input of location from the user

Location* input()

{
    
    Location *l = new Location;
    
    cout<<" Enter the row(0-3) : ";
    
    cin>>l->row;
    
    while(l->row < 0 || l->row > 3)
        
    {
        
        cout<<" Invalid row value. Enter the row(0-3) : ";
        
        cin>>l->row;
        
    }
    
    cout<<" Enter the column(0-3) : ";
    
    cin>>l->col;
    
    while(l->col < 0 || l->col > 3)
        
    {
        
        cout<<" Invalid column value. Enter the column(0-3) : ";
        
        cin>>l->col;
        
    }
    
    return l;
    
}

// function to update userBoard according to the inputs of user

void updateBoard(int *board, bool *userBoard, Location *l1, Location *l2,int &space)

{
    
    if(board[4*l1->row+l1->col] == board[4*l2->row+l2->col])
        
    {
        
        userBoard[4*l1->row+l1->col] = true;
        
        userBoard[4*l2->row+l2->col] = true;
        
        space = space + 2;
        
    }
    
}
