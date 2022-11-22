/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#ifndef H_courseType
#define H_courseType
#include <fstream>
#include <string>
#include <iomanip>

#pragma once

class courseType
{
public:
	void setCourseInfo(std::string, std::string, int); // mutator
	void print(std::ostream&); // prints to output file
	int getCredits() { return courseCredits; } // accessor
	std::string getCourseNumber() { return courseNum; } // accessor
	std::string getCourseName() { return courseName; } // accessor
	courseType() { courseName = ""; courseNum = ""; courseCredits = 0; } // constructor
private:
	std::string courseName;
	std::string courseNum;
	int courseCredits;
};

#endif

