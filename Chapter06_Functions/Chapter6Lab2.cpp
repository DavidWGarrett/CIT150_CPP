// David Garrett
// Chapter 6 Lab 2
// 10-21-22

#include <iostream>
using namespace std;

// Function prototype
double fahrenheitToCelsius(double temperature);
void celsiusToFahrenheit(double& temperature);

// Program ask user to enter a temperature and if the user wants temperature
// converted to Fahrenheit or Celsius. Depending on choice, the appropriate 
// function is called that calculates the new temperature.

int main()
{
	double temperature, convertedTemperature;
	int choice, toCelsius = 1, toFahrenheit = 2;

	// User enters temperature and their choice of conversion

	cout << "Enter a temperature to convert: ";
	cin >> temperature;
	cout << "Enter 1 to convert Fahrenheit to Celsius, or 2 to convert Celsius to Fahrenheit: ";
	cin >> choice;

	if (choice == toCelsius)
	{
		// Passes the value of temperature to function. Returns temperature in celsius
		convertedTemperature = fahrenheitToCelsius(temperature);
		cout << temperature << " degrees Fahrenheit converted to Celsius is " << convertedTemperature;
	}
	else if (choice == toFahrenheit)
	{
		// Pass by reference. Sends address of variable
		celsiusToFahrenheit(temperature);
	}
}

double fahrenheitToCelsius(double temperature)
{
	//conversion and returns value
	double tempCels = (temperature - 32) * 5 / 9;
	return tempCels;
}

void celsiusToFahrenheit(double& temperature)
{
	// conversion and outputs the temperature in Fahrenheit
	double tempFahr = (temperature * 1.8) + 32;
	cout << temperature << " degrees Celsius convert to Fahrenheit is " << tempFahr;
}