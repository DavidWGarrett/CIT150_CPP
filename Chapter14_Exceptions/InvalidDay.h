/*]
David Garrett
Chapter 14 Lab 1
12-12-22
*/

#ifndef INVALIDDAY_H
#define INVALIDDAY_H

#include <iostream>

#pragma once
class invalidDay
{
public:
	invalidDay() { message = "User input an invalid day."; } // Invalid message
	invalidDay(std::string str) { message = str; }
	std::string what() { return message; }
private:
	std::string message;
};

#endif