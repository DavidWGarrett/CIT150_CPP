/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#include "personType.h"


// Prints name
void personType::print() const
{
	std::cout << firstName << " " << lastName;
}

//mutator
void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

// two accessor methods
string personType::getFirstName() const
{
	return firstName;
}
string personType::getLastName() const
{
	return lastName;
}

//constructor
personType::personType(string first, string last)
{
	firstName = first;
	lastName = last;
}