/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#include "courseType.h"

// mutator
void courseType::setCourseInfo(std::string courseName, std::string courseNum, int courseCredits)
{
	this->courseName = courseName;
	this->courseNum = courseNum;
	this->courseCredits = courseCredits;
}

// print course info to output file
void courseType::print(std::ostream& file)
{
	file << std::left << std::setw(8) << courseNum << "    " << std::setw(15) << courseName
		<< std::right << std::setw(3) << courseCredits << "    ";
}