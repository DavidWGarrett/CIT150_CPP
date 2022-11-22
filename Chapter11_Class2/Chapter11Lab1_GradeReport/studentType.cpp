/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#include "studentType.h"

void studentType::setInfo(std::string fName, std::string lName, int ID, int nOfCourses, bool isTPaid,
	courseType courses[], char cGrades[])
{
	setName(fName, lName); //set first and last name
	sId = ID; // set ID
	isTuitionPaid = isTPaid; //set isTuitionPaid
	numberOfCourses = nOfCourses; //set the number of courses


	//set an array of course and grades
	for (int i = 0; i < numberOfCourses; i++)
	{
		coursesEnrolled[i] = courses[i];
		coursesGrade[i] = cGrades[i];
	}
	sortCourses(); // rearrange the courses
}

// print info about student to output file
void studentType::print(std::ostream& outF, double tuitionRate)
{
	outF << "Student Name: " << getFirstName()
		<< " " << getLastName() << endl; //Step 1
	outF << "Student ID: " << sId << endl; //Step 2
	outF << "Number of courses enrolled: "
		<< numberOfCourses << endl; //Step 3
	outF << endl;
	outF << left;
	outF << "Course No" << setw(15) << " Course Name"
		<< setw(8) << "Credits"
		<< setw(6) << "Grade" << endl;
	outF << right;
	for (int i = 0; i < numberOfCourses; i++) //Step 5
	{
		coursesEnrolled[i].print(outF); //Step 5a
		if (isTuitionPaid) //Step 5b
			outF << setw(4) << coursesGrade[i] << endl;
		else
			outF << setw(4) << "***" << endl;
	}
	outF << endl;
	outF << "Total number of credit hours: "
		<< getHoursEnrolled() << endl; //Step 6
	outF << fixed << showpoint << setprecision(2); //Step 7
	if (isTuitionPaid) //Step 8
		outF << "Mid-Semester GPA: " << getGpa()
		<< endl;
	else
	{
		outF << "*** Grades are being held for not paying "
			<< "the tuition. ***" << endl;
		outF << "Amount Due: $" << billingAmount(tuitionRate)
			<< endl;
	}
	outF << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
		<< "-*-*-*-*-" << endl << endl;
}

// constructor
studentType::studentType()
{
	numberOfCourses = 0;
	sId = 0;
	isTuitionPaid = false;
	for (int i = 0; i < 6; i++)
		coursesGrade[i] = '*';
}

// adds up all credits and returns them
int studentType::getHoursEnrolled()
{
	int totalCredits = 0;
	for (int i = 0; i < numberOfCourses; i++)
		totalCredits += coursesEnrolled[i].getCredits();
	return totalCredits;
}

// finds GPA based on letter grade and credit hourss
double studentType::getGpa()
{
	double sum = 0.0;
	for (int i = 0; i < numberOfCourses; i++)
	{
		switch (coursesGrade[i])
		{
		case 'A':
			sum += coursesEnrolled[i].getCredits() * 4;
			break;
		case 'B':
			sum += coursesEnrolled[i].getCredits() * 3;
			break;
		case 'C':
			sum += coursesEnrolled[i].getCredits() * 2;
			break;
		case 'D':
			sum += coursesEnrolled[i].getCredits() * 1;
			break;
		case 'F':
			break;
		default:
			cout << "Invalid Course Grade." << endl;
		}
	}
	return sum / getHoursEnrolled();
}

// arranges coursses in alphabetical order
void studentType::sortCourses()
{
	int minIndex;
	courseType temp; //variable to swap the data
	char tempGrade; //variable to swap the grades
	string course1;
	string course2;
	for (int i = 0; i < numberOfCourses - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < numberOfCourses; j++)
		{
			//get the course numbers
			course1 =
				coursesEnrolled[minIndex].getCourseNumber();
			course2 = coursesEnrolled[j].getCourseNumber();
			if (course1 > course2)
				minIndex = j;
		}
		temp = coursesEnrolled[minIndex];
		coursesEnrolled[minIndex] = coursesEnrolled[i];
		coursesEnrolled[i] = temp;
		tempGrade = coursesGrade[minIndex];
		coursesGrade[minIndex] = coursesGrade[i];
		coursesGrade[i] = tempGrade;
	}
}


// Finds tuition
double studentType::billingAmount(double tuitionRate)
{
	return tuitionRate * getHoursEnrolled();
}