/*
David Garrett
Chapter 8 Lab 2
10-27-22
*/

#include <iostream>
#include <iomanip>
#include <fstream>;
#include <string>

using namespace std;
void inputSales(double sales[], ofstream& file, int counter);
void inputSales(double sales[], int counter);
void outputSales(double sales[], int counter);
void sortPrices(double sales[], double& max, double& min, double& average);
void printSortedPrices(double& min, double& max, double& avg);

// User must type in 7 prices
const int LIMIT = 7;

/* 
Program ask user to input seven prices. Program will print out those seven prices.
Next, program calculate the maximum, minimum, and average price.
Lastly, program will store those prices in a text file.
*/

int main()
{
    double sales[LIMIT];
    double highest, lowest, average;
    ofstream outFile;
    string nameOutputFile = "output.txt";

    // Associate outFile with the actual name of the file
    outFile.open(nameOutputFile);

    // User types in seven prices, stores in array and text file
    for (int i = 0; i < LIMIT; ++i)
        inputSales(sales, outFile, i);

    // Display each price typed in. Iterates through the array
    for (int i = 0; i < LIMIT; ++i)
        outputSales(sales, i);

    // Figures out minimum, maximum, and average price
    sortPrices(sales, highest, lowest, average);

    // Prints out minimum, maximum, and average price
    printSortedPrices(lowest, highest, average);

    // Disassociate outFile from the file name
    outFile.close();
    return 0;
}

void inputSales(double sales[], ofstream& file, int counter)
{
    // User types in a price. Stored in array and text file

    double input;

    cout << "Enter sales for day " << (counter + 1) << "  >>  ";
    cin >> sales[counter];
    file << sales[counter] << endl;
}

void inputSales(double sales[], int counter)
{
    double input;

    cout << "Enter sales for day " << (counter + 1) << "  >>  ";
    cin >> sales[counter];
}

void outputSales(double sales[], int counter)
{
    // Displays the price at the index specified. Formattted to always show two decimal points

    cout << fixed << showpoint << setprecision(2);
    cout << "The sales of day " << (counter + 1) << " was $" << sales[counter] << endl;
}

void sortPrices(double sales[], double& max, double& min, double& average)
{
    // Initialize variables to first value in the array
    double total = max = min = sales[0];

    // Begin iterating through all other values in array
    // Finds maximum and minimum price. 
    // Also has a accumlator variable that adds all prices to help find average price
    for (int i = 1; i < LIMIT; ++i)
    {
        total += sales[i];

        if (sales[i] < min)
            min = sales[i];
        else if (sales[i] > max)
            max = sales[i];
    }

    // Finds average price. 
    average = total / LIMIT;
}

void printSortedPrices(double& min, double& max, double& avg)
{
    // Prints out minimum, maximum, and average price. 
    // Formattted to always show two decimal points.
    cout << fixed << showpoint << setprecision(2);

    cout << "The highest amount of sales was $" << max << endl;
    cout << "The lowest amount of sales was $" << min << endl;
    cout << "The average amount of sales was $" << avg << endl;
}