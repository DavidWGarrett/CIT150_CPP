/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#ifndef H_studentType
#define H_studentType
#include <fstream>
#include <string>
#include "personType.h" // Inheritance 
#include "courseType.h" // Aggregation

// Derived Class of personType class
class studentType : public personType
{
public:
	void setInfo(std::string, std::string, int, int, bool, courseType[], char[]); // mutator
	void print(std::ostream&, double); // print info the output file
	int getHoursEnrolled(); // figures out how many hours student enrolled
	double getGpa(); // calculate gpa based on letter grade and credit hours
	double billingAmount(double); // multiple tuition rate by hours enrolled
	studentType(); // constructor

private:
	int sId;
	int numberOfCourses;
	bool isTuitionPaid;
	courseType coursesEnrolled[6];
	char coursesGrade[6];
	void sortCourses();
};
#endif