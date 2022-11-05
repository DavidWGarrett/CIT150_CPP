/*
 * David Garrett
 * Chapter 2 Lab 2
 * 9-19-2022
 */

#include <iostream>
using namespace std;
const int NUMBER_OF_SCORES = 5;

// Program asks user to input five of their test scores and outputs the average

int main()
{
	int firstScore, secondScore, thirdScore, fourthScore, fifthScore;
	double average;

	// Asks user to input five test scores
	cout << "Enter the first test score: ";
	cin >> firstScore;

	cout << "Enter the second test score: ";
	cin >> secondScore;

	cout << "Enter the third test score: ";
	cin >> thirdScore;

	cout << "Enter the fourth test score: ";
	cin >> fourthScore;

	cout << "Enter the fifth test score: ";
	cin >> fifthScore;

	// Finds average of test scores 
	// Expression gets type casted from int to double to get an answer in a correct decimal format
	average = static_cast<double> (firstScore + secondScore + thirdScore + fourthScore + fifthScore) 
		                          / NUMBER_OF_SCORES;

	// Output the average of the five test scores
	cout << "The average of the test scores you entered is : " << average;

	return 0;
}


