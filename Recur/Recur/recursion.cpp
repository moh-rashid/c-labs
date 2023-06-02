//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
// 

#include "recursion.h"
#include <iostream>

using namespace std;

// this is your recursive palindrome program
// it might have different arguments, depending on how you solved the problem
bool recPalindrome(string word,int index,int length)
{
    if (index >= length)
        return true;
    
    if (word[index] != word[length])
        return false;
    
    return recPalindrome(word,++index, --length);
}


// this is the wrapper that calls your recursive palendrome testing program
bool isPalindrome(string word)
{


    
    int length = static_cast<int>(word.length() - 1);
    int index = 0;
    
    return recPalindrome(word,index,length);
}

// this is your recursive subset generating program
// you might have a different set of arguments, depending on how you code it
void recPrintAllSubsets(string word, string output)
{
    // put your code here
    if (word.length() == 0)
        
    {
        cout << output << " ";
        return;
        
    }
    
    recPrintAllSubsets(word.substr(1), output);
    recPrintAllSubsets(word.substr(1), output + word[0]);
}

// this is the wrapper that calls your subset generating program
// change it to match your function signature
void printAllSubsets(string word){
    
    recPrintAllSubsets(word, "");
}

