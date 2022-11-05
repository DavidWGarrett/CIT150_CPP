// David Garrett
// Chapter 6 Lab 1 Largest Number
// 10-17-22

#include <iostream>

using namespace std;

// Function prototype. Needed when main is above largest function
int largest(int* numbers, int size);

// 1. Program ask user to type in ten integers 
// 2. Program saves those ten integers in an array
// 3. Array passed to largest function
// 4. Largest function determines largest integer and returns value to main
// 5. Display largest value to user

int main()
{
	int const SIZE = 10;
	int userNumbers[SIZE], max;

	cout << "Enter " << SIZE << " numbers." << endl;

	// User types in ten integers. Integers stored in an array.
	for (int i = 0; i < SIZE; i++)
		cin >> userNumbers[i];

	// Passed the address of the first element of the array and
	// the number of elements in the array. Largest function 
	// returns the largest integer in the array.
	max = largest(&userNumbers[0], SIZE);

	cout << "The largest number is " << max;
}

// Function returns largest integer in an array
// First parameter points to the first element of an array
int largest(int *numbers, int size)
{
	// Initialized max to the first integer in the array
	int max = numbers[0];

	// Iterate through each element of the array
	// If next number is larger, that number is initialized
	// to max.
	for (int i = 1; i < size; i++)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}

	// Return the largest integer to main
	return max;
}