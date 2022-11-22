#include "house.h"

// function definitions for house header


// constructor
House::House(std::string address, double sqft)
{
	setStreetAddress(address);
	setSquareFeet(sqft);
}

// display info about house
void House::display()
{
	std::cout << "Street Address: " << streetAddress << std::endl;
	std::cout << "Square Feet: " << squareFeet << std::endl;
}