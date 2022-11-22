#include "investment.h"

// function definitions for Investment header

//constructor
Investment::Investment(double initial, double current)
{
	setInitialValue(initial);
	setCurrentValue(current);
	setProfit(current - initial);
	setPercentProfit((profit / initialValue) * 100);
}

//display info about investment
void Investment::display()
{
	std::cout << "Initial Value: " << initialValue << std::endl;
	std::cout << "Current Value: " << currentValue << std::endl;
	std::cout << "Profit: " << profit << std::endl;
	std::cout << "Percent Profit: " << std::showpoint << std::fixed << std::setprecision(2) << percentProfit << "%" << std::endl;
}