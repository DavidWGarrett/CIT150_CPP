#include "houseThatIsAnInvestment.h"

// function definitions for houseThatIsAnInvestment header

//constructor
HouseThatIsAnInvestment::HouseThatIsAnInvestment(double initial, double current, std::string address, double sqft)
	: Investment(initial, current), House(address, sqft)
{
	;
}

//display info about the investment and house
void HouseThatIsAnInvestment::display()
{
	House::display();
	Investment::display();
}