/*
David Garrett
Chapter 10 Lab 2
11-10-22
*/

#pragma once
#ifndef TIME_H // include guard
#define TIME_H

#include <iostream>
#include <iomanip>

class Time
{
public:
	Time() { hour = 0; minute = 0; } // Default constructor
	Time(int hour) { setHour(hour); minute = 0; } // Constructor, One parameter
	Time(int hour, int minute) { setHour(hour); setMinute(minute); } // Constructor, Two parameters
	void setHour(int hour); // Mutator function, sets hours
	void setMinute(int minute); // Mutator function, sets minutes
	void display(); // Displays time that is correctly formated
	void add(int); // add minutes to private variable minute

private: // Private variables. Can only be access by functions inside of class
	int hour;
	int minute;
};

void Time::setHour(int hour)
{
	// Hour cannot be larger than 23 or smaller than 0.
	// If larger than 23, will keep hour to 23
	// If smaller than 0, will keep hour to 0

	if (hour > 23)
		this->hour = 23;
	else if (hour < 0)
		this->hour = 0;
	else
		this->hour = hour;
}

void Time::setMinute(int minute)
{
	// Minute cannot be larger than 59 or smaller than 0.
	// If larger than 59, will keep minute to 59
	// If smaller than 0, will keep minute to 0

	if (minute > 59)
		this->minute = 59;
	else if (minute < 0)
		this->minute = 0;
	else
		this->minute = minute;
}

void Time::display()
{
	// Displays time with correct format

	std::cout << "Time is " << Time::hour << ":" << std::setfill('0') 
		      << std::setw(2) << Time::minute << std::endl;
}

void Time::add(int minute)
{
	// Adds minute. Minutes and hours will rollover if hits maximum amount

	this->minute += minute;

	while (this->minute > 60)
	{
		hour += 1;
		this->minute -= 60;

		if (hour > 23)
			hour = 0;
	}
}

#endif

