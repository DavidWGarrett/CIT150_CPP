#ifndef H_investment
#define H_investment

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

//class definition, some function defintions in the investment.cpp

class Investment
{
public:
	Investment() { initialValue = 0.0; currentValue = 0.0; profit = 0.0; percentProfit = 0.0; }
	Investment(double, double);
	void display();
	double getInitialValue() { return initialValue; }
	void setInitialValue(double value) { initialValue = value; }
	double getCurrentValue() { return currentValue; }
	void setCurrentValue(double value) { currentValue = value; }
	double getProfit() { return profit; }
	void setProfit(double value) { profit = value; }
	double getPercentProfit() { return percentProfit; }
	void setPercentProfit(double value) { percentProfit = value; }
protected:
	double initialValue;
	double currentValue;
	double profit;
	double percentProfit;
};

#endif