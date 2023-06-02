//
//  main.cpp
//  Lab 4
//
//  Created by Mohammed AlRashid on 5/6/19.
//  Copyright © 2019 Lane CC. All rights reserved.
//

#include <iostream>
using namespace std;


int getSize();
int *createArray(int arraySize);
void sortArray(int arraySize, int *pointer);
void displayArray(int arraySize, int *pointer);



int main(int argc, const char * argv[]) {
    
    int arraySize = getSize();
    
    int *arrayPTR;
    arrayPTR = createArray(arraySize);
    sortArray(arraySize, arrayPTR);
    displayArray(arraySize, arrayPTR);
    
    delete[] arrayPTR;
    return 0;
}


/******** GET SIZE FUNCTION *********/
int getSize(){
    int size;
    bool check;
    
    do{
        cout << "Please Enter a number between 10 and 20." << endl;
        cin >> size;
        check = (size < 10 && size > 20);
        
        if(check == true)
            cout << "You have entered an invalid Value" << endl;
        
    }while(check == true);
    
    
    return size;
}

/********* Create Array Function ***************/
int *createArray(int arraySize){
    
    int *myArrayPTR;
    
    myArrayPTR = new int [arraySize];
    
    for(int i=0;i<arraySize;i++){
        myArrayPTR[i] = rand() % 99 +1;
    }
    
    return myArrayPTR;
}

void sortArray(int arraySize, int *pointer){
    int i, j, min, temp;
    for (i = 0; i < arraySize - 1; i++) {
        min = i;
        for (j = i + 1; j < arraySize; j++)
            if (pointer[j] < pointer[min])
                min = j;
        temp = pointer[i];
        pointer[i] = pointer[min];
        pointer[min] = temp;
    }
}

void displayArray(int arraySize, int *pointer){
    int j=0;
    
    for(int i=0; i<arraySize ;i++){
        if(!(j%6))
        {j=1; cout << "\n";}
        cout << pointer[i] << " ";
        j++;
    }
        cout << endl;
}
