#include<iostream>
#include<cctype>


using namespace std;

int main()
{
    //variables that hold small and large values and count of numbers entered
    int small=0,large=0,count=0;
    //variable used to control the loop
    bool repeat=true;
    int userInput;
    //run a loop that accept numbers from user until user enters 0
    do
    {
        //read a number from user
        cout << "Enter a positive number: " << endl;
        cin >> userInput;
        
        // checks for bad input
        if (!cin){
            cout << "You have entered an invalid value, ";
            cin.clear();
            cin.ignore(256,'\n');
        }
        //checks if input is 0
        else if(userInput == 0)
        {
            repeat = false;
        }
        // checks if input is from 1 to 100
        else if((userInput < 0) || (userInput > 100)){
            cout << "The number you entered is invalid, Please try again. ";
            cin.clear();
        }
        //checks if input larger than 0
        else if(userInput > 0)
        {
            //checks if count is 0
            if(count == 0)
            {
                //set input as small and large
                small = userInput;
                large = userInput;
                count++;
            }
            else
            {
                //if userInput is less than small then assign userInput to small
                if(userInput < small)
                {
                    small = userInput;
                    count++;
                }
                //if userInput is greater than large then assign userInput to large
                else if(userInput > large)
                {
                    large = userInput;
                    count++;
                    repeat = true;
                }
            }
        }
    }
    while(repeat == true);
    
    //print the small and large values
    cout << "\nThe smallest number entered is: " << small <<endl;
    cout << "The largest number entered is: " << large << "\n" << endl;
    return 0;
}
