/*
David Garrett
Chapter  13 Lab 1 clockType
12-5-22
*/

#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

#pragma once

#include <iostream>

class clockType
{
	// Used to output time
	friend std::ostream& operator << (std::ostream&, const clockType&);

	// used to input time
	friend std::istream& operator >> (std::istream&, clockType&);

public:
	// mutators and accessors
	void setHour(int hour) { this->hour = hour; }
	int getHour() { return hour; }
	void setMinute(int minute) { this->minute = minute; }
	int getMinute() { return minute; }
	void setSecond(int second) { this->second = second; }
	int getSecond() { return second; }
	void setTime(int, int, int);
	void getTime(int&, int&, int&);

	// adds one second
	clockType operator ++ ();

	// compares the time of the two clocks
	bool operator == (const clockType&) const;
	bool operator != (const clockType&) const;
	bool operator <= (const clockType&) const;
	bool operator < (const clockType&) const;
	bool operator >= (const clockType&) const;
	bool operator > (const clockType&) const;

	// constructors
	clockType() { hour = 0; minute = 0; second = 0; }
	clockType(int, int, int);

private:
	int hour;
	int minute;
	int second;

	// Used to make sure time inputed by user if a valid time
	void validateTime(int&, int&, int&);
};

#endif