/*]
David Garrett
Chapter 14 Lab 1
12-12-22
*/

#include <iostream>
#include <map>
#include "InvalidDay.h"
#include "invalidMonth.h"

using namespace std;

struct date
{
    int year;
    int month;
    int day;
};

void setMap(map<int, string>& months);
void inputYear(date& date, int daysInEachMonth[]);
void inputMonth(date& date);
void inputDay(date& date, int dayInEachMonth[]);

// Program asks user to input their birth day, month, and year and then prints the birth date
// Uses exceptions to deal with situations where user inputs an invalid number

int main()
{
    // 
    int daysInEachMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    struct date date; // struct holds year, month, day variables
    map<int, string> months; // 

    setMap(months); // Maps integers to a string of each month's name
    inputYear(date, daysInEachMonth); // user inputs brith year
    inputMonth(date); // user inputs birth month
    inputDay(date, daysInEachMonth); // user inputs birth day

    // Prints date of birth day. 
    cout << "\nBirth Day: " << months[date.month] << " " << date.day << ", " << date.year;

}

void setMap(map<int, string>& months)
{
    // maps user's input for month to string of each month's name

    months.insert(pair<int, string>(1, "January"));
    months.insert(pair<int, string>(2, "February"));
    months.insert(pair<int, string>(3, "March"));
    months.insert(pair<int, string>(4, "April"));
    months.insert(pair<int, string>(5, "May"));
    months.insert(pair<int, string>(6, "June"));
    months.insert(pair<int, string>(7, "July"));
    months.insert(pair<int, string>(8, "August"));
    months.insert(pair<int, string>(9, "September"));
    months.insert(pair<int, string>(10, "October"));
    months.insert(pair<int, string>(11, "November"));
    months.insert(pair<int, string>(12, "December"));
}

void inputYear(date& date, int daysInEachMonth[])
{
    int year;

    cout << "Enter birth year: ";

    // Loops till user input is valid

    do
    {
        try
        {
            cin >> year;

            // If year is before 1900, will be force to input new birth year
            if (year < 1900)
                throw year;

            break;
        }
        catch (int year)
        {
            cout << "Invalid input. Please re-enter birth year: ";
        }
    } while (true);

    // Initialize birth year
    date.year = year;

    // Adds extra day to February if leap year
    if (year % 4 == 0)
        daysInEachMonth[1] += 1;
}

void inputMonth(date& date)
{
    int month;

    cout << "Enter birth month: ";

    // Loops till user input is valid

    do
    {
        try
        {
            cin >> month;

            // If month isn't in the 1-12 range, throws exception

            if (month < 1 || month > 12)
                throw invalidMonth();

            break;
        }
        catch (invalidMonth invalidMonth)
        {
            // what function for invalidMonth exceptions calls error function

            cout << invalidMonth.what() << " Please re-enter birth month: ";
        }
    } while (true);

    // Initialize birth month
    date.month = month;
}


void inputDay(date& date, int dayInEachMonth[])
{
    int day;

    cout << "Enter birth day: ";

    // Loops till user input is valid

    do
    {
        try
        {
            cin >> day;

            // Uses the array that has days of each month
            // If user input falls outside the scope of the days in a particular month, throws exception

            if (day < 0 || day > dayInEachMonth[date.month - 1])
                throw invalidDay();

            break;
        }
        catch (invalidDay invalidDay)
        {
            // what function for invalidDay exceptions calls error function

            cout << invalidDay.what() << " Please re-enter birth day: ";
        }


    } while (true);

    // Initialize birth day
    date.day = day;
}