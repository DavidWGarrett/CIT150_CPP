/*
David Garrett
Chapter 13 Lab 1 myString
12-5-22
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include "myString.h"

using namespace std;

// constructor
newString::newString(const char* str)
{
	strLength = strlen(str);
	strPtr = new char[strLength + 1];
	strcopy(str);
}

// default constructor
newString::newString()
{
	strLength = 0;
	strPtr = new char[1];
	strPtr[0] = '\0';
}

// constructor
newString::newString(const newString& rightStr)
{
	strLength = rightStr.strLength;
	strPtr = new char[strLength + 1];
	strcopy(rightStr.strPtr);
}

// destructor
newString::~newString()
{
	delete[] strPtr;
}

// copy the contents of the string on right side of operator into left side of operator
const newString& newString::operator=(const newString& rightStr)
{
	if (this != &rightStr)
	{
		delete[] strPtr;
		strLength = rightStr.strLength;
		strPtr = new char[strLength + 1];
		strcopy(rightStr.strPtr);
	}
	return *this;
}

// makes sure index is within bounds
char& newString::operator[] (int index)
{
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

// makes sure index is within bounds
const char& newString::operator[](int index) const
{
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

// compare the contents of the string
bool newString::operator==(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) == 0);
}
bool newString::operator<(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) < 0);
}
bool newString::operator<=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) <= 0);
}
bool newString::operator>(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) > 0);
}
bool newString::operator>=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) >= 0);
}
bool newString::operator!=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) != 0);
}

// output contents of string when used with "cout <<"
ostream& operator<<(ostream& osObject, const newString& str)
{
	osObject << str.strPtr;
	return osObject;
}

// Can be used to input a string with cin
istream& operator>> (istream& isObject, newString& str)
{
	char temp[81];
	isObject >> setw(81) >> temp;
	str = temp;
	return isObject;
}

// copy the contents of a string into the newString object
char* newString::strcopy(const char* str)
{
	for (int i = 0; i < strLength; i++)
		strPtr[i] = str[i];
	strPtr[strLength] = '\0';
	return strPtr;
}

// copy the contents of a string into the newString object
char* newString::strcopy(char* str1, const char* str2)
{
	for (int i = 0; i < strlen(str1); i++)
		str1[i] = str2[i];
	str1[strlen(str1)] = '\0';
	return str1;
}