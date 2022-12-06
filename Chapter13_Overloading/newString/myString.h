/*
David Garrett
Chapter 13 Lab 1 myString
12-5-22
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

#include <iostream>

class newString
{
	// output contents of string when used with "cout <<"
	friend std::ostream& operator<< (std::ostream&, const newString&);

	// Can be used to input a string with cin
	friend std::istream& operator>> (std::istream&, newString&);

public:
	// copy the contents of the string on right side of operator into left side of operator
	const newString& operator=(const newString&);

	// constructor
	newString(const char*);
	newString();
	newString(const newString&);

	// destructor
	~newString();

	// makes sure index is within bounds
	char& operator[] (int);
	const char& operator[](int) const;

	// compare the contents of the string objects
	bool operator==(const newString&) const;
	bool operator!=(const newString&) const;
	bool operator<=(const newString&) const;
	bool operator<(const newString&) const;
	bool operator>=(const newString&) const;
	bool operator>(const newString&) const;

private:
	// copy the contents of a string into the newString object
	char* strcopy(const char* str2);
	char* strcopy(char* str1, const char* str2);

	char* strPtr;
	int strLength;
};

#endif