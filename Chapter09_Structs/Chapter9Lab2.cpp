/*
David Garrett
Chapter 9 Lab 2
11-4-2022
*/

/*
Program ask user to input five account numbers and the balances and interest rate
associated with those bank account numbers. Those numbers are stored in a struct variable.
Afterwards, all the information about the bank accounts are displayed.
Lastly, user can enter a bank account number to display the information again.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void inputInfo(struct bankAccount accounts[]);
void testDuplicateNumber(int& temp, struct bankAccount accounts[]);
void outputInfo(struct bankAccount accounts[]);
void displayData(struct bankAccount accounts[], int i);

struct bankAccount
{
    int accountNumber = 0;
    double balance = 0.0;
    double interestRate = 0.0;
};

const static int NUMBER_OF_ACCOUNTS = 5;

int main()
{
    bankAccount bankAccounts[NUMBER_OF_ACCOUNTS];
    int account;
    bool found = false;

    // User input information about the five bank accounts
    inputInfo(bankAccounts);

    // Displays all info about the bank accounts include the total and average of
    // the five accounts
    outputInfo(bankAccounts);

    cout << "Enter in a bank account number you would like to see more info on: ";
    cin >> account;

    // User enters the account of the information they want to see.
    // for loop iterates through the bankAccount array till account is found
    // Then displays information.
    // Must enter a valid bank account number.
    while (!found)
    {
        for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
        {
            if (account == bankAccounts[i].accountNumber)
            {
                found = true;
                cout << endl;
                displayData(bankAccounts, i);
                break;
            }
        }

        if (!found)
        {
            cout << "Account number not found. Enter in a new number: ";
            cin >> account;
        }
    }
}

void inputInfo(struct bankAccount accounts[])
{
    int tempArray[NUMBER_OF_ACCOUNTS];

    for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
    {
        cout << "Enter bank account number for person " << i + 1 << ": ";
        cin >> tempArray[i];

        // User must enter a unique account number
        // Will be repeatedly prompt to enter new number till a unique number is entered
        testDuplicateNumber(tempArray[i], accounts);
        
        // Store bank information into struct variable
        accounts[i].accountNumber = tempArray[i];

        cout << "Enter the balance of account " << accounts[i].accountNumber << ": ";
        cin >> accounts[i].balance;

        cout << "Enter the annual interest rate of account " << accounts[i].accountNumber << ": ";
        cin >> accounts[i].interestRate;

        cout << endl;
    }
}

void testDuplicateNumber(int& temp, struct bankAccount accounts[])
{
    // Test to see if user entered in duplicate account number
    // Forces user to re-enter numbers till unique number found

    bool duplicate = false;

    for (int j = 0; j < NUMBER_OF_ACCOUNTS; j++)
    {
        if (temp == accounts[j].accountNumber)
        {
            duplicate = true;
            cout << "Duplicate account number. Enter a new account number: ";
            cin >> temp;
        }
    }

    if (duplicate)
        testDuplicateNumber(temp, accounts);
}

void outputInfo(struct bankAccount accounts[])
{
    double total = 0.0;
    double average;

    // Displays info about all accounts
    for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
    {
        cout << fixed << showpoint << setprecision(2);

        displayData(accounts, i );

        // Accumulates total of all balances
        total += accounts[i].balance;
    }

    // Display total and average
    cout << "The total of all the balances is $" << total << endl;
    cout << "The average of all the blance is $" << total / NUMBER_OF_ACCOUNTS << endl << endl;
}

void displayData(struct bankAccount accounts[], int i)
{
    // Display account number, balance, and interest rate

    cout << fixed << showpoint << setprecision(2);

    cout << "Account: " << accounts[i].accountNumber << endl;
    cout << "Balance: $" << accounts[i].balance << endl;
    cout << "Annual Interest Rate: " << accounts[i].interestRate << "%" << endl << endl;
}
