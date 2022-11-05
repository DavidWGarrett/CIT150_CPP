/*
 * David Garrett
 * Chapter 4 Lab 2 Doggy Day Care
 * 9-29-2022
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * The goal of this program is to figure out the rate and total bill that a doggy day care center
 * will charge based on the size of the dog and the number days per month the day stays
 *
 * The program asks for information about the dog and number of days stay, make a decision
 * about the daily rate using a series of if and else statements a conditional expression,
 * perform the calculations for the total bill, and output the daily rate and total bill
 * to the user.
 */

int main()
{
	int sizeOfDog, daysPerMonth, totalBill;
	int dailyRate = 0; // Initialized to 0 so calculations can be performed below line 48
	string nameOfDog;
	const int RATE_SMALL_DOG = 12, RATE_MEDIUM_DOG = 15, RATE_BIG_DOG = 19;
	const int DISCOUNT_MEDIUM_DOG = 3, DISCOUNT_OTHER_SIZE_DOG = 2;
	const int WEIGHT_MEDIUM_DOG = 10, WEIGHT_BIG_DOG = 25;
	const int DISCOUNT_FOR_OVER_TEN_DAYS = 10;

	// Ask user for name and size of dog. Also ask days per month the dog needs care.

	cout << "What is your dog's name? ";
	cin >> nameOfDog;

	cout << "What does the dog weigh in pounds? ";
	cin >> sizeOfDog;

	cout << "How many days per month will your dog need care? ";
	cin >> daysPerMonth;

	cout << "Pampared Pets Day Care Center\n\n";

	// A control structure that uses selection to decide what the daily rate will be
	// based on the weight of the dog

	if (sizeOfDog < WEIGHT_MEDIUM_DOG)
	{
		dailyRate += RATE_SMALL_DOG;
	}
	else if (sizeOfDog >= WEIGHT_BIG_DOG)
	{
		dailyRate += RATE_BIG_DOG;
	}
	else
	{
		dailyRate += RATE_MEDIUM_DOG;
	}

	// A discount is provided if days per month is over ten days. If a discount is provided,
	// then the daily rate is reduced by 3 if the dog is a medium size, or 2 if any other size

	if (daysPerMonth > DISCOUNT_FOR_OVER_TEN_DAYS)
	{
		dailyRate -= (sizeOfDog >= WEIGHT_MEDIUM_DOG && sizeOfDog < WEIGHT_BIG_DOG) ?
			DISCOUNT_MEDIUM_DOG : DISCOUNT_OTHER_SIZE_DOG;
	}

	// Calculations to find the total bill

	totalBill = dailyRate * daysPerMonth;

	// Tells user the daily rate and total bill

	cout << "The daily rate for " << nameOfDog << " is $" << dailyRate
		 << "\nPer month, you will pay $" << totalBill;
}