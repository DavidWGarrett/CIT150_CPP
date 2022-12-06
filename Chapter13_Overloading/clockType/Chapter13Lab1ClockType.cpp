/*
David Garrett
Chapter 13 Lab 1 ClockType
12-5-22
*/

#include <iostream>
#include "ClockType.h"

using namespace std;

int main()
{
	clockType myClock(7, 24, 32); // instantiate clock object with values specified 
	clockType yourClock; // instantiate clock object with all values initialized to 0

	cout << "Line 8: myClock = " << myClock << endl; // prints clock time
	cout << "Line 9: yourClock = " << yourClock << endl;
	cout << "Line 10: Enter the time in the form " << "hr:min:sec ";

	cin >> myClock; // can input time by inputting in three numbers
	cout << endl; 
	cout << "Line 13: The new time of myClock = " << myClock << endl;
	++myClock; // adds one second

	cout << "Line 15: After incrementing the time, " << "myClock = " << myClock << endl; 

	yourClock.setTime(13, 35, 38); // Set new time

	cout << "Line 17: After setting the time, " << "yourClock = " << yourClock << endl; 

	if (myClock == yourClock) // compares the time of the two clock objects
		cout << "Line 19: The times of myClock and " << "yourClock are equal." << endl; 
	else 
		cout << "Line 21: The times of myClock and " << "yourClock are not equal." << endl; 

	if (myClock <= yourClock) // compares the time of the two clock objects
		cout << "Line 23: The time of myClock is " << "less than or equal to "
			 << "the time of yourClock." << endl;  
	else 
		cout << "Line 25: The time of myClock is " << "greater than the time of " << "yourClock." << endl; 

	return 0;
}  
