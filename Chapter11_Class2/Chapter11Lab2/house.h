#ifndef H_house
#define H_house

#pragma once

#include <iostream>
#include <string>


//class definition, some function defintions in the house.cpp

class House
{
public:
	House() { streetAddress = ""; squareFeet = 0.0; }
	House(std::string, double);
	void display();
	std::string getStreetAddress() { return streetAddress; }
	void setStreetAddress(std::string address) { streetAddress = address; }
	double getSquareFeet() { return squareFeet; }
	void setSquareFeet(double sqft) { squareFeet = sqft; }
protected:
	std::string streetAddress;
	double squareFeet;
};

#endif 