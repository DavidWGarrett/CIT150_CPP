/*
 * David Garrett
 * Chapter 4 Lab 1 Cable Company Billing
 * 9-30-2022
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Constants used for calculating the total bill

const double BILL_PROC_FEE_RES = 4.50;
const double BASIC_SERVICE_FEE_RES = 20.50;
const double PREMIUM_CHAN_PRICE_RES = 7.50;
const double BILL_PROC_FEE_BUS = 15.00;
const double BASIC_SERVICE_FEE_BUS_FIRST_TEN = 75.00;
const double BASIC_SERVICE_FEE_BUS_AFTER_TEN = 5.00;
const double PREMIUM_CHAN_PRICE_BUS = 50.00;
const int MAX_CONNECTION_LIMIT = 10;

/*
 * Program does three things 
 * 
 * 1. Ask the user to type in their cable customer information, 
 * 2. Calculate the cable bill based on the type of bustomer and the 
 * amount of premium channels subscribed 
 * 3. Show the total bill.
 */

int main()
{
	char typeOfCustomer;
	int accountNumber, numOfPremiumChannels, basicServiceConnections;
	double totalBill;

	cout << fixed << showpoint << setprecision(2);

	// Program asks user to input account number, customer type, and number of premium channels

	cout << "This program computers a cable bill.\n\nEnter account number (an integer): ";
	cin >> accountNumber;

	cout << "Enter customer type: R or r (Residential), B or b (Business): ";
	cin >> typeOfCustomer;

	// If customer is residential or business, will continue asking questions and
	// calculate the total bill. If not, program will say "Invalid input"

	if (typeOfCustomer == 'B' || typeOfCustomer == 'b' || typeOfCustomer == 'R' ||
		typeOfCustomer == 'r')
	{
		// If customer is a business, will ask for number of basic service connections

		if (typeOfCustomer == 'B' || typeOfCustomer == 'b')
		{
			cout << "Enter the number of basic service connections: ";
			cin >> basicServiceConnections;
		}

		cout << "Enter the number of premium channels: ";
		cin >> numOfPremiumChannels;

		// Calculations for total bill. Calculations are different based on customer type

		if (typeOfCustomer == 'B' || typeOfCustomer == 'b')
		{
			totalBill = BILL_PROC_FEE_BUS + BASIC_SERVICE_FEE_BUS_FIRST_TEN +
				(numOfPremiumChannels * PREMIUM_CHAN_PRICE_BUS);

			if (basicServiceConnections > MAX_CONNECTION_LIMIT)
			{
				totalBill += ((basicServiceConnections - MAX_CONNECTION_LIMIT) *
					BASIC_SERVICE_FEE_BUS_AFTER_TEN);
			}
		}
		else if (typeOfCustomer == 'R' || typeOfCustomer == 'r')
		{
			totalBill = BILL_PROC_FEE_RES + BASIC_SERVICE_FEE_RES +
				        (numOfPremiumChannels * PREMIUM_CHAN_PRICE_RES);
		}

		// Program tells user their account number and total money owed

		cout << "\nAccount number: " << accountNumber << endl;
		cout << "Amount due: $" << totalBill;
	}

	// If user doesn't give an input indicating the customer is business or residential,
	// program will stop

	else
	{
		cout << "\nInvalid customer type.";
	}
}