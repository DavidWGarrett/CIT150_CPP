// David Garrett
// Chapter 6 Lab 1 Classifying Numbers
// 10-21-22

#include <iostream>

using namespace std;

// Function Prototype
void initialize(int& zeros, int& evens, int& odds, int& count);
int getNumber();
void classifyNumber(int num, int& zeros, int& evens, int& odds);
void printResults(int zeros, int evens, int odds);

const int MAX_USER_INPUT = 20;

// Program ask user to type in 20 integers, program prints out those twenty integers on screen, and
// counts the number of even, odd, and zero number and prints that to user.

int main()
{
    int zeros, evens, odds, count;
    int userNumbers[MAX_USER_INPUT];

    // Initialize variables
    initialize(zeros, evens, odds, count);

    cout << "Please enter 20 integers. Positive, negative, or zeros.\n\n";

    // User inputs 20 numbers and program checks to see what kind of number it is 
    for (count = 0; count < MAX_USER_INPUT; ++count)
    {
        userNumbers[count] = getNumber();
        cout << userNumbers[count] << " ";
        classifyNumber(userNumbers[count], zeros, evens, odds);
    }

    // Prints results
    printResults(zeros, evens, odds);
}

void initialize(int& zeros, int& evens, int& odds, int& count)
{
    // Address of variables passed and initialized to 0

    zeros = 0;
    evens = 0;
    odds = 0;
    count = 0;
}

int getNumber()
{
    // User inputs number
    int input;
    cin >> input;

    // if user types in any other characters, the program will stop

    if (cin.fail())
    {
        cout << "\nInvalid Input. Relaunch program to try again.\n";
        abort();
    }

    // number stored in array

    return input;
}

void classifyNumber(int num, int& zeros, int& evens, int& odds)
{
    // Determines if number is even or odd and increments a counter for each type of number
    // Also counts the number of zeros

    if (num % 2 == 0)
    {
        ++evens;

        if (num == 0)
            ++zeros;
    }
    else if (num % 2 == 1 || num % 2 == -1)
        ++odds;
}

void printResults(int zeros, int evens, int odds)
{
    // Prints the number of evens, odds, and zeros to user

    cout << "\n\nThere are " << evens << " even numbers which include " << zeros << " zeros.\n"
         << "The number of odd numbers are: " << odds;
}