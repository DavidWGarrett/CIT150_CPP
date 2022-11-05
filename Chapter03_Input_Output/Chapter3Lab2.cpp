/*
 * David Garrett
 * Chapter 3 Lab 2
 * 9-26-22
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * Program asks user to input their first name and weight in kilogram.
 * Then outputs a file called "output.txt" that includes the information
 * the user inputed and their weight in pounds.
 */

int main()
{
    // Delcarations

    double weightKg, weightLb;
    string name, file = "output.txt";
    ofstream out; 

    // User inputs first name

    cout << "Enter the person's first name: ";
    cin >> name;

    // User inputs weight in kilograms

    cout << "Enter the weight in Kilograms: ";
    cin >> weightKg;
    
    // Opens output file called "output.txt" 

    out.open(file);

    // Calculation finds the person's weight in pounds

    weightLb = weightKg * 2.2;

    // Outputs text file with person's first name, weight in kilo, and pounds

    out << fixed << showpoint << setprecision(2); // output weight to two decimal places
    out << "First Name: " << name << endl << "Weight in Kilograms: "
        << weightKg << endl << "Weight in Pounds: " << weightLb;

    // File disconnected from stream
    
    out.close();
}
