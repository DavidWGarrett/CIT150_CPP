/*]
David Garrett
Chapter 14 Lab 1
12-12-22
*/

#ifndef INVALIDMONTH_H
#define INVALIDMONTH_H

#pragma once

#include <iostream>

class invalidMonth
{
public:
	invalidMonth() { message = "User input an invalid month."; } // Invalid message
	invalidMonth(std::string str) { message = str; }
	std::string what() { return message; }
private:
	std::string message;
};

#endif