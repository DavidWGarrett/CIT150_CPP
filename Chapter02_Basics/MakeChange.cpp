/*
 * David Garrett
 * Chapter 2, Lab 1 MakeChange
 * September 19th, 2022
 */

#include <iostream>
using namespace std;

/* Program asks user how many cents he or she has and displays the maximum amount
 * of each coin that person could have
 */

// Constants used for finding the maximum amount of each coin and remaining change
const int HALF_DOLLAR = 50, QUARTER = 25, DIME = 10, NICKEL = 5;

int main()
{
	int change;

	// Ask user to input the amount of cents
	cout << "Please enter in the number of cents you have: ";
	cin >> change;

	// The change is divide by 50 to figure out how many half dollar coins and displays amount to user
	cout << "The maximum number of half dollars you can have is " << change / HALF_DOLLAR << "." << endl;
	change %= HALF_DOLLAR; // Modulus operator finds the remaining amount of change

	// Process repeats for quarters, dimes, and nickels
	cout << "The maximum number of quarters you can have is " << change / QUARTER << "." << endl;
	change %= QUARTER;

	cout << "The maximum number of dimes you can have is " << change / DIME << "." << endl;
	change %= DIME;

	cout << "The maximum number of nickels you can have is " << change / NICKEL << "." << endl;
	change %= NICKEL;

	// Remaining change is displayed to the user as number of pennies
	cout << "The maximum number of pennies you can have is " << change << "." << endl;

	return 0;
}