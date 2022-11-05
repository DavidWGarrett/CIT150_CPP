/*
 * David Garrett
 * Chapter 2, Lab 1 ConvertLength
 * September 19th, 2022
 */

 /*
  * Functions of the program
  *
  * 1. Ask the user to input a length in feetand inches
  * 2. Convert that length to centimeter
  * 3. Output that value to the console
  */

#include <iostream>
using namespace std;

// variables used to convert length to centimeters
const double CENTIMETERS_PER_INCH = 2.54;
const int INCHES_PER_FOOT = 12;

int main()
{
    int feet, inches, totalInches;
    double centimeters;

    // Ask user to input the number of feet the length has
    cout << "This is a program to convert a length from feet and inches to centimeters." << endl
        << "Please enter how many feet this length have: ";
    cin >> feet;

    // Ask user to input the number of remaining inches the length has
    cout << "Please enter the remaining inches this length have: ";
    cin >> inches;

    // Converts length to total inches and outputs information to user
    totalInches = (feet * INCHES_PER_FOOT) + inches;
    cout << "The length is " << feet << " feet and " << inches << " inches long for a total of "
        << totalInches << " inches long." << endl;

    // Converts length to total centimeters and outputs information to user
    centimeters = totalInches * CENTIMETERS_PER_INCH;
    cout << "\nThe length is " << centimeters << " centimeters long." << endl;

    return 0;
}