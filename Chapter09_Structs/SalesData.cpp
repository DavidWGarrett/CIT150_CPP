/*
David Garrett
Chapter 9 Lab 1 Sales Data Analysis
10-31-22
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
const int NUMBER_OF_EMPLOYEES = 6;
const int QUARTERS = 4;

struct employee
{
    int identifier;
    double salesQuarter[QUARTERS];
    double total;
};

void initializer(struct employee employeeList[]);
void setID(string idFile, struct employee employeeList[]);
void gatherData(string fileName, struct employee employeeList[]);
void addToQuarter(int month, double money, struct employee employeeList[], int employee);
void outputData(string fileName, struct employee employeeList[]);
void addQuarterly(double quarter[], struct employee employeeList[]);
void inputUserIdentifierFile(string& fileName);
void inputSalesDataFile(string& fileName);
void inputNameOfOutputFile(string& fileName);


int main()
{
    string idFileName;
    string salesFileName;
    string outputSales;
    employee employeeList[NUMBER_OF_EMPLOYEES];
    
    // Set struct employeeList members to 0
    initializer(employeeList);

    // Gets the name of the file with the sales person's ID
    inputUserIdentifierFile(idFileName);

    // Add those IDs to the struct variable employeeList
    setID(idFileName, employeeList);

    // Gets the name of the file with all the sales
    inputSalesDataFile(salesFileName);

    // Add those sales to the struct variable employeeList arranged by quarters
    gatherData(salesFileName, employeeList);

    // Gets the name of the text file to output the report to
    inputNameOfOutputFile(outputSales);

    // Arrange the report into a table format and write to text file
    // It'll also output the max sales by quarter and sales person
    outputData(outputSales, employeeList);
}

void initializer(struct employee employeeList[])
{
    // initialize all members of the struct to 0

    for (int i = 0; i < NUMBER_OF_EMPLOYEES; ++i)
    {
        employeeList[i].total = 0.0;
        employeeList[i].identifier = 0;

        for (int j = 0; j < QUARTERS; j++)
        {
            employeeList[i].salesQuarter[j] = 0;
        }
    }

}

void setID(string idFile, struct employee employeeList[])
{
    ifstream file;
    int ID;

    file.open(idFile);

    // If file doesn't exist, the program will abort
    if (file.fail())
    {
        cout << "Failed to open the file. Program will not stop.";
        abort();
    }

    // Will now iterate through each line of the file. Will store each ID
    // into the employeeList variable
    while (!file.eof())
    {
        file >> ID;

        for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
        {
            if (employeeList[i].identifier == ID)
                break;
            if (employeeList[i].identifier == 0)
            {
                employeeList[i].identifier = ID;
                break;
            }
        }
    }
    file.close();
}

void gatherData(string fileName, struct employee employeeList[])
{
    ifstream salesFile;
    int ID;
    int month;
    double money;

    salesFile.open(fileName);

    // If file doesn't exist, the program will abort
    if (salesFile.fail())
    {
        cout << "Failed to open the file. Program will not stop.";
        abort();
    }

    // Will now iterate through each line of the file. Will store each employee's
    // sale to the corresponding quarter
    while (!salesFile.eof())
    {
        // Gets values from text file
        salesFile >> ID >> month >> money;

        for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
        {
            if (employeeList[i].identifier == ID)
            {
                // Adds to the specific employee's quarter

                addToQuarter(month, money, employeeList, i);
                break;
            }
        }
    }

    salesFile.close();
}

void addToQuarter(int month, double money, struct employee employeeList[], int employee)
{
    // Adds money to overall total
    employeeList[employee].total += money;

    int i = 0;
    int firstMonth = 1;
    int lastMonth = 3;

    // Figures out which quarter the month is in
    while (!(month >= firstMonth && month <= lastMonth))
    {
        i++;
        firstMonth += 3;
        lastMonth += 3;
    }

    // Adds to that quarter
    employeeList[employee].salesQuarter[i] += money;

}

void outputData(string fileName, struct employee employeeList[])
{
    ofstream file;
    double total[QUARTERS];
    double largestTotalEmployee = 0.0;
    int largestTotalID;
    double largestQuarter = 0.0;
    int largestSalesQuarter;

    // Opens file to output formated table to
    file.open(fileName);

    file << "-------------------------- Annual Sales Report " 
        << "----------------------------" << endl << endl;
    file << setw(5) << "ID" << setw(13) << "QT1" << setw(13) <<
        "QT2" << setw(13) << "QT3" << setw(13) << "QT4" << setw(13) <<
        "Total" << endl;
    file << "____________________________________________"
        << "__________________________________" << endl;

    // Outputs each person's sales for each quarters including the total to the text file
    // Also, finds the employee with the largest total sales
    for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
    {

        file << setw(7) << employeeList[i].identifier
            << fixed << showpoint << setprecision(2);
            
        for (int j = 0; j < QUARTERS; j++)
        {
            file << setw(13) << employeeList[i].salesQuarter[j];
        }

        file << setw(13) << employeeList[i].total << endl;

        if (largestTotalEmployee < employeeList[i].total)
        {
            largestTotalEmployee = employeeList[i].total;
            largestTotalID = employeeList[i].identifier;
        }
    }
    
    // Adds the sales of the four quarters
    addQuarterly(total, employeeList);

    file << setw(7) << "Total" << fixed << showpoint << setprecision(2);
      
    // Outputs the sales of the four quarters to text file
    // Also, finds the quarter with the highest sales
    for (int i = 0; i < QUARTERS; i++)
    {
        file << setw(13) << total[i];

        if (largestQuarter < total[i])
        {
            largestQuarter = total[i];
            largestSalesQuarter = i + 1;
        }

    }

    file << endl << endl;


    // Outputs the salesperson with the highest sales and the quarter with the highest sales
    // to the text file
    file << "Max Sale by SalesPerson: ID = " << largestTotalID << ", Amount = $"
        << largestTotalEmployee << endl;
    file << "Max Sale by Quarter: Quarter = " << largestSalesQuarter << ", Amount = $"
        << largestQuarter << endl;

}

void addQuarterly(double quarter[], struct employee employeeList[])
{
    // Finds the total sales for each quarter

    for (int i = 0; i < QUARTERS; i++)
    {
        quarter[i] = 0.0;

        for (int j = 0; j < NUMBER_OF_EMPLOYEES; j++)
        {
            quarter[i] += employeeList[j].salesQuarter[i];
        }
    }
}

void inputUserIdentifierFile(string& fileName)
{
    // Gets the name of the file with the sales person's ID
    // I used salesID.txt

    cout << "Please enter in the name of the file containing the "
        << "list of user IDs: ";
    cin >> fileName;
}

void inputSalesDataFile(string& fileName)
{
    // Gets the name of the file with all the sales
    // I used salesData.txt

    cout << "Please enter in the name of the file containing the "
        << "sales data: ";
    cin >> fileName;
}

void inputNameOfOutputFile(string& fileName)
{
    // Gets the name of the text file to output the report to

    cout << "Please enter in the name of the file to record the "
        << "annual sales report to: ";
    cin >> fileName;
}