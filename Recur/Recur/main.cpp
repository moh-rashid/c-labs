//
//  main.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//

#include <iostream>

#include "recursion.h"

using namespace std;

#define TEST_PALENDROME
#define TEST_SUBSETS

int main()
{
#ifdef TEST_PALENDROME
    
    cout << "Testing palindromes" << endl << endl;
    
    const int NUM_WORDS = 5;
    string words[] = {"avid diva", "civic", "banana", "racecar", "dog"};
    
    for(int i = 0; i < NUM_WORDS; i++)
    {
        cout << words[i] << (isPalindrome(words[i])?" is ":" is not ") << "a palindrome" << endl;
    }
    
    cout << "They should all pass except banana and dog" << endl << endl;
    cout << "Done testing palindromes" << endl << endl;
    
#endif // TEST_PALENDRONME
    
    
#ifdef TEST_SUBSETS
    
    cout << "Testing subsets.  The order does not matter." << endl << endl;
    
    cout << "subsets of abc are: abc, ab, ac, bc, a, b, c" << endl;
    cout << "your results are: ";
    printAllSubsets("abc");
    cout << endl << endl;;
    
    
    cout << "subsets of abcd are: abcd, abc, abd, acd, ab, ac, ad, a, bcd, bc, bd, cd, b, c, d" << endl;
    cout << "your results are: ";
    printAllSubsets("abcd");
    cout << endl << endl;
    
    cout << "Done testing subsets" << endl << endl;
    
    
#endif // TEST_SUBSETS
    
    return 0;
}
