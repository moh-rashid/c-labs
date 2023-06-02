
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int randomNum1, randomNum2, answer;
    
    // we seed the function to get a true random number everytime the program runs.
    srand(static_cast<unsigned>(time(NULL)));
    // we need 2 random numbers from 1 to 99
    randomNum1 = (rand() % 99) + 1;
    randomNum2 = (rand() % 99) + 1;
    
    cout << "what is the sum of " << randomNum1 << " and " << randomNum2 << "? " << endl;
    cin >> answer;
    
    // replaces what the user entered with the correct answer.
    answer = randomNum1 + randomNum2;
    
    cout << "\n" << setw(3) << randomNum1 << "\n+" << setw(2) << randomNum2 << "\n---\n" << setw(3) << answer << "\n" << endl;
    
    return 0;
}
