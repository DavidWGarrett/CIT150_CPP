/*
David Garrett
Chapter 13 Lab 1 myString
12-5-22
*/

#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
	// Program compares four different strings and demostrates operator overloading

	newString str1 = "Sunny";
	const newString str2("Warm");
	newString str3;
	newString str4;

	// Can display string within the newString objects with cout
	cout << "Line 10: " << str1 << " " << str2 << " ***" << str3 << "###." << endl;

	if (str1 <= str2) // compares the ascii value of strings
		cout << "Line 12: " << str1 << " is less " << "than or equal to " << str2 << endl;
	else
		cout << "Line 14: " << str2 << " is less " << "than " << str1 << endl;

	cout << "Line 15: Enter a string with a length " << "of at least 7: ";

	cin >> str1; // User types in a string
	cout << "\nLine 18: The new value of " << "str1 = " << str1 << endl;

	str4 = str3 = "Birth Day"; // Initialize new string into strPtr in str3 and 4 object
	cout << "Line 20: str3 = " << str3 << ", str4 = " << str4 << endl;

	str3 = str1; // Initialize str1's strPtr into str3's strPtr
	cout << "Line 22: The new value of str3 = " << str3 << endl;

	str1 = "Bright Sky";
	str3[1] = str1[5]; // Passes only one character and changes character of str3's strPtr at index 1
	cout << "Line 25: After replacing the second " << "character of str3 = " << str3 << endl;

	str3[2] = str2[0]; // Passes only one character and changes character of str3's strPtr at index 2
	cout << "Line 27: After replacing the third " << "character of str3 = " << str3 << endl;

	str3[5] = 'g'; // Passes one character and changes character of str3's strPtr at index 5
	cout << "Line 29: After replacing the sixth " << "character of str3 = " << str3 << endl;

	return 0;
}