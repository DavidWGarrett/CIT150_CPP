/*
David Garrett
Chapter 11 Lab 2
11-21-22
*/

#include <iostream>

// header file includes information about house and investment class
// necessary to create the houseThatIsAnInvestment object
#include "houseThatIsAnInvestment.h"

int main()
{
    // Passes initial value, current value, street address, and square footage to the constructor
    HouseThatIsAnInvestment aHouse(140000, 175000,"12 Oak Street", 2000);

    // Displays just infomation about the investment
    std::cout << "This is a plain investment" << std::endl;
    aHouse.Investment::display();

    // Displays just information about the house
    std::cout << "\nThis is a plain House" << std::endl;
    aHouse.House::display();

    // Displays information about  both the house and investment
    std::cout << "\nThis is a House that is also an investment" << std::endl << std::endl;
    aHouse.display();
    return 0;

}


