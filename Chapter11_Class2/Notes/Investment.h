#pragma once

class investment
{
public:
	investment() { ; }
	investment(double, double)
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

investment::investment(double initial, double current)
{
	initialValue = initial;
	currentValue = current;
	profit = current - intial;
	percentProfit = profit / initialValue;
}