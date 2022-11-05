/*
* David Garrett
* Chapter 5 Lab 1 Fibonacci
* 10-4-2022
*/

#include <iostream>
using namespace std;

// Program ask user to input the first two terms of a Fibonacci sequence and a position of a certain term
// Program outputs the value at that position of the Fibonacci sequence
// For example, if a Fibonacci sequence is arranged 1, 1, 2, then the variables are arranged
// previousTerm2, previousTerm, currentTerm

int main()
{
    int currentTerm, previousTerm, previousTerm2, position;

    // User inputs first two terms and position of desired Fibonacci number

    cout << "Enter the first two Fibonacci numbers: ";
    cin >> previousTerm2 >> previousTerm;

    cout << "\nThe first two Fibonacci numbers are " << previousTerm2 << " and " 
         << previousTerm << endl << "Enter the position of the desired Fibonacci number: ";
    cin >> position;

    // For loop will only iterate up to the position of the desired Fibonacci number

    for (int i = 1; i <= position; i++)
    {
        // First term
        if (i == 1)
        {
            currentTerm = previousTerm2;
        }
        // Second term
        else if (i == 2)
        {
            currentTerm = previousTerm;
        }
        // next term will add the two previous terms together
        // Afterwards, both previousterm values are assigned the next values in Fibonacci sequence
        else if (i >= 3)
        {
            currentTerm = previousTerm + previousTerm2;
            previousTerm2 = previousTerm;
            previousTerm = currentTerm;
        }
    }

    // Output Fibonacci number

    cout << "\nThe Fibonacci number at position " << position << " is " << currentTerm;
}
