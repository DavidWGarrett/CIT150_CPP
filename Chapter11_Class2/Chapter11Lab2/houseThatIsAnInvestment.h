#ifndef H_houseThatIsAnInvestment
#define H_houseThatIsAnInvestment

#pragma once

#include <iostream>
#include <string>
#include "investment.h"
#include "house.h"

//class definition, only has function declarations
class HouseThatIsAnInvestment : public Investment, public House
{
public:
	HouseThatIsAnInvestment() { ; }
	HouseThatIsAnInvestment(double, double, std::string, double);
	void display();
};

#endif