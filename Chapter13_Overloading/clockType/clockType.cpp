/*
David Garrett
Chapter  13 Lab 1 clockType
12-5-22
*/

#include "clockType.h"

using namespace std;

// Used to output time
ostream& operator<<(ostream& osObject, const clockType& timeOut)
{
	if (timeOut.hour < 10)
		osObject << '0';

	osObject << timeOut.hour << ':';

	if (timeOut.minute < 10)
		osObject << '0';

	osObject << timeOut.minute << ':';

	if (timeOut.second < 10)
		osObject << '0';

	osObject << timeOut.second;

	return osObject;
}

// used to input time
istream& operator>> (istream& is, clockType& timeIn)
{
	char ch;
	is >> timeIn.hour;
	if (timeIn.hour < 0 || timeIn.hour >= 24)
		timeIn.hour = 0;

	is.get(ch);
	is >> timeIn.minute;

	if (timeIn.minute < 0 || timeIn.minute >= 60)
		timeIn.minute = 0;

	is.get(ch);
	is >> timeIn.second;

	if (timeIn.second < 0 || timeIn.second >= 60)
		timeIn.second = 0;

	return is;
}

// validates and can be used to set time in clockType object
void clockType::setTime(int hour, int minute, int second)
{
	validateTime(hour, minute, second);

	this->setHour(hour);
	this->setMinute(minute);
	this->setSecond(second);
}

// Can change the values passed to clockType object to be the same as the clock's values
void clockType::getTime(int& hour, int& minute, int& second)
{
	hour = this->getHour();
	minute = this->getMinute();
	second = this->getSecond();
}

// make sure the info user inputs is within range
// if not, defaults to 0
void clockType::validateTime(int& hour, int& minute, int& second)
{
	if (hour < 0 && hour > 24)
		hour = 0;

	if (minute < 0 && minute > 60)
		minute = 0;

	if (second < 0 && second > 60)
		second = 0;
}

// constructor
clockType::clockType(int hour, int minute, int second)
{
	this->setTime(hour, minute, second);
}

// adds one second
clockType clockType::operator++()
{
	second++;

	if (second > 59)
	{
		second = 0;
		minute++;
		if (minute > 59)
		{
			minute = 0;
			hour++;
			if (hour > 23)
				hour = 0;
		}
	}

	return *this;
}

// six functions to compare two clockType objects/ time
bool clockType::operator==(const clockType& clock) const
{
	return (this->hour == clock.hour && this->minute == clock.minute
		    && this->second == clock.second);
}

bool clockType::operator!=(const clockType& clock) const
{
	return (this->hour != clock.hour || this->minute != clock.minute
		    || this->second != clock.second);
}

bool clockType::operator<=(const clockType& clock) const
{
	return ((this->hour < clock.hour) || (this->hour == clock.hour && this->minute < clock.minute)
			|| (this->hour == clock.hour && this->minute == clock.minute && this->second <= clock.second));
}

bool clockType::operator<(const clockType& clock) const
{
	return ((this->hour < clock.hour) || (this->hour == clock.hour && this->minute < clock.minute)
			|| (this->hour == clock.hour && this->minute == clock.minute && this->second < clock.second));
}

bool clockType::operator>=(const clockType& clock) const
{
	return ((this->hour > clock.hour) || (this->hour == clock.hour && this->minute > clock.minute)
			|| (this->hour == clock.hour && this->minute == clock.minute && this->second >= clock.second));
}

bool clockType::operator>(const clockType& clock) const
{
	return ((this->hour > clock.hour) || (this->hour == clock.hour && this->minute > clock.minute)
			|| (this->hour == clock.hour && this->minute == clock.minute && this->second > clock.second));
}