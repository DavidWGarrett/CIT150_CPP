/*
 * David Garrett
 * Chapter 3 Lab 1 Movie Ticket
 * 9-26-22
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
 * The movie theatre you are running is having a charity event and is donating a percentage of ticket
 * sales to the charity.
 * 
 * The program will ask you to input information about the price of tickets, number of tickets, and
 * the percentage of total sales planned to be donated.
 * 
 * The program will output a formatted and properly aligned message restating the information
 * you inputed and also output the total sales, money donated, and net sales after donation.
 */

int main()
{
    // Declarations 

    string movieName;
    int adultTicket, childTicket;
    double adultPrice, childPrice, salesTotal, salesNet, donated, percentage;

    // Tell user what the program wants

    cout << "This program will ask you to input information about sales information "
         << "and the percentage of sales planned to be donated to charity.\n\n";

    // Ask user to input the relevant information

    cout << "Type in the name of the movie: ";
    getline(cin, movieName); // Use getline since movie name may have a space

    cout << "Type in the number of adult ticket sales: ";
    cin >> adultTicket;

    cout << "Type in the number of child ticket sales: ";
    cin >> childTicket;

    cout << "Type in the price of adult tickets: ";
    cin >> adultPrice;

    cout << "Type in the price of child tickets: ";
    cin >> childPrice;

    cout << "Type in the percentage donated to charity: ";
    cin >> percentage;

    /* Calculations.Figures out:
     * 1. Amount of money made from ticket sales
     * 2. Amount of money donated to charity
     * 3. Amount of money leftover after money was donated to charity
     */

    salesTotal = (adultTicket * adultPrice) + (childTicket * childPrice);
    donated = salesTotal * percentage * 0.01;
    salesNet = salesTotal - donated;

    // Outputs with the information formatted with each line aligned with each other
  
    cout << fixed << showpoint << setprecision(2); // Outputs decimal numbers to 2 places
    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";

    /* Left side of line is 40 characters long, tells user what the following information is,
     * and fills the remaining trailing space with periods
     * 
     * Right side of line outputs the information the user inputed and also output
     * total sales, amount donated, and net sales.
     * On the right side of line, all decimal numbers and $ symbols align
     */

    cout << left << setw(40) << setfill('.') << "Movie Name: " << setfill(' ')
         << right << " " << movieName << endl;
    cout << left << setw(40) << setfill('.') << "Number of Tickets Sold: " << setfill(' ') 
         << right << setw(12) << (adultTicket + childTicket) << endl;
    cout << left << setw(40) << setfill('.') << "Gross Amount: " << setfill(' ') 
         << right << " $" << setw(10) << salesTotal << endl;
    cout << left << setw(40) << setfill('.') << "Percentage of Gross Amount Donated:"
         << setfill(' ') << right << setw(12) << percentage << "%" << endl;
    cout << left << setw(40) << setfill('.') << "Amount Donated: " << setfill(' ')
         << right << " $" << setw(10) << donated << endl;
    cout << left << setw(40) << setfill('.') << "Net Sale: " << setfill(' ')
         << right << " $" << setw(10) << salesNet << endl;
}
