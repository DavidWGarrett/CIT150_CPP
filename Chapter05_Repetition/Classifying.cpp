/* 
David Garrett
Chapter 5 Lab 1 Classifying
10-10-2022
*/

#include <iostream>

using namespace std;

// Program ask user to type in 20 integers, program prints out those twenty integers on screen, and
// counts the number of even, odd, and zero number and prints that to user.

int main()
{
    int userInt, zeros = 0, evens = 0, odds = 0, counter;
    int MAX_USER_INPUT = 20;
    int userNumbers[20];

    cout << "Please enter 20 integers. Positive, negative, or zeros.\n\n";

    // Loops twenty times for the twenty integers

    for (counter = 0; counter < MAX_USER_INPUT; ++counter)
    {
        // User inputs number

        cin >> userInt;
        
        // if user types in any other characters, the program will stop

        if (cin.fail())
        {
            cout << "\nInvalid Input. Relaunch program to try again.\n";
            break;
        }

        // number stored in array

        userNumbers[counter] = userInt;

        // Determines if number is even or odd and increments a counter for each type of number
        // Also counts the numer of zeros

        if (userInt % 2 == 0)
        {
            ++evens;

            if (userInt == 0)
            {
                ++zeros;
            }
        }
        else if  (userInt % 2 == 1 || userInt % 2 == -1)
        {
            ++odds;
        }
    }

    // User must type in 20 integers or program terminates

    if ((evens + odds) == MAX_USER_INPUT)
    {
        // Prints out the integers the user typed in

        for (int i = 0; i < MAX_USER_INPUT; ++i)
        {
            cout << userNumbers[i] << " ";
        }

        // Prints the number of evens, odds, and zeros to user

        cout << "\n\nThere are " << evens << " even numbers which include " << zeros << " zeros.\n"
            << "The number of odd numbers are: " << odds;
    }
}