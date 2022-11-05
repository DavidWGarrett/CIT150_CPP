/*
 * David Garrett
 * Chapter 3 Lab 1 Student Grade
 * 9-26-22
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

/* 
 * Program reads a text file with someone's name and five test scores seperated
 * by a space. 
 * Outputs a new text file with a more readable formatting and includes
 * the average of the five test scores.
 */

int main()
{
	// Declarations

	string firstName, lastName;
	double score1, score2, score3, score4, score5, avg;
	ifstream in;
	ofstream out;

	// Opens both the input and output file. test.txt exist in same folder as StudentGrade.cpp

	in.open("test.txt");
	out.open("testavg.txt");

	// Reads input file, Each successive value seperated by a space initialized into variable

	in >> firstName >> lastName >> score1 >> score2 >> score3 >> score4
	   >> score5;

	// Calculates average test score

	avg = (score1 + score2 + score3 + score4 + score5) / 5;

	// Outputs new text file with new, more readable formatting
	// New textfile includes name, five test scores, and average score

	out << fixed << showpoint << setprecision(2);
	out << "Student Name: " << firstName << " " << lastName << endl;
	out << "Test Scores:" << setw(6) << score1 << setw(6) << score2
		<< setw(6) << score3 << setw(6) << score4 << setw(6) << score5
		<< endl;
	out << "Average Test Score: " << avg;

	// Disassociates file stream variables from storage area
	
	in.close();
	out.close();
}

