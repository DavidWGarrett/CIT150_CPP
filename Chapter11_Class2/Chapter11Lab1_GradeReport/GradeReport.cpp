/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#include <iostream>
#include <fstream>
#include <string>
#include "studentType.h"
#include "courseType.h"

using namespace std;

void getStudentData(ifstream& infile, studentType studentList[], int numberOfStudents);
void printGradeReports(ofstream& outfile, studentType studentList[], int numberOfStudents, double tuitionRate);

const int MAX_STUDENTS = 10;

int main()
{
	studentType studentList[MAX_STUDENTS];
	int noOfStudents;
	double tuitionRate;
	ifstream infile;
	ofstream outfile;

	infile.open("stData.txt");

	// file must exist or program stops
	if (!infile)
	{
		cout << "The input file does not exist. "
			<< "Program terminates." << endl;
		return 1;
	}

	outfile.open("sDataOut.txt");

	// First line of text contains number of students and tuition rate
	infile >> noOfStudents;
	infile >> tuitionRate;

	// reads info from text file, passes info to course and student objects
	getStudentData(infile, studentList, noOfStudents);

	// outputs info to output text in a more readable format
	printGradeReports(outfile, studentList,
		noOfStudents, tuitionRate);
	return 0;
}

void getStudentData(ifstream& infile, studentType studentList[], int numberOfStudents)
{
	string fName;
	string lName;
	int ID; 
	int noOfCourses;
	char isPaid; 
	bool isTuitionPaid;
	string cName; 
	string cNo; 
	int credits; 
	courseType courses[6];
	char cGrades[6];

	// reads text file
	for (int count = 0; count < numberOfStudents; count++)
	{
		infile >> fName >> lName >> ID >> isPaid;

		if (isPaid == 'Y')
			isTuitionPaid = true;
		else
			isTuitionPaid = false;

		infile >> noOfCourses;

		// gets the course information for a particular student, pass info to course object
		for (int i = 0; i < noOfCourses; i++)
		{
			infile >> cName >> cNo >> credits >> cGrades[i];
			courses[i].setCourseInfo(cName, cNo, credits);
		}

		// Passes all the gathered info including the course object to the student object
		studentList[count].setInfo(fName, lName, ID, noOfCourses, isTuitionPaid, courses, cGrades);
	}
}

// Prints info the output text
void printGradeReports(ofstream& outfile, studentType studentList[], int numberOfStudents, double tuitionRate)
{
	for (int count = 0; count < numberOfStudents; count++)
		studentList[count].print(outfile, tuitionRate);
}
