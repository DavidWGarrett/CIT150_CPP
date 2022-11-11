/*
David Garrett
Chapter 10 Lab 1 Juice Machine
11-7-22
*/

#include <iostream>

// Include header file for juice and dispenser class
#include "JuiceMachine.h"

using namespace cashRegisters;
using namespace dispensers;
using namespace std;

void showSelection();
void sellProduct(dispenser& product, registers& counter);
void showResults(registers& counter);


int main()
{
    // register object and four different kinds of dispenser objects with different juices

    registers counter;
    dispenser orange(100, 50.0, "orange");
    dispenser apple(90, 65.0, "apple");
    dispenser mango(75, 80.0, "mango");
    dispenser strawberryBanana(60, 85.0, "strawberry-bananan");
    int choice;


    showSelection();
    cin >> choice;

    // Person has 4 options for juice. If user types in "9", the exchange is done.

    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(orange, counter);
            break;
        case 2:
            sellProduct(apple, counter);
            break;
        case 3:
            sellProduct(mango, counter);
            break;
        case 4:
            sellProduct(strawberryBanana, counter);
            break;
        default:
            cout << "Invalid choice. Try again." << endl << endl;
        }

        showSelection();
        cin >> choice;
    }

    showResults(counter);
}

void showSelection()
{
    // Display info about the juice shop. Shows how to buy juice and the price.
    // Also how to exit.

    cout << "*** Welcome to Shelly's Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for orange juice (50 cents)" << endl;
    cout << "2 for apple juice (65 cents)" << endl;
    cout << "3 for mango juice (80 cents)" << endl;
    cout << "4 for strawberry banana juice (85 cents)" << endl;
    cout << "9 to exit" << endl << endl;
}

void sellProduct(dispenser& product, registers& counter)
{
    double total;
    double amount;

    // Must be in stock

    if (product.getStock() > 0)
    {
        // Person gives money 

        cout << "\nPlease deposit " << product.getCost() << " cents: ";
        cin >> total;

        // Money entered must be higher than the price. Program will ask for more money if below price.
        // If "0" is entered, the current exchange is exited

        while (total < product.getCost())
        {
            cout << "Please deposit " << product.getCost() - total << " more cents or press 0 to exit : ";
            cin >> amount;

            total += amount;

            // Exit Condition
            if (amount == 0)
            {
                cout << "Exiting..." << endl << endl;
                break;
            }

            // Return extra money
            if (total > product.getCost())
            {
                cout << "Returning " << total - product.getCost() << " cents." << endl;
                total = product.getCost();
            }

        }

        // Register takes the money, sale is made. Inventory is iterated down 1.
        if (total >= product.getCost())
        {
            counter.takeMoney(total);
            product.makeSale();

            cout << "Enjoy your " << product.getName() << " juice!!" << endl << endl;
        }
    }
    else
        cout << "Sold out!" << endl << endl;
}

void showResults(registers& counter)
{
    // Shows the current balance of the register after juice is bought
    cout << "\nThere is now " << counter.getBalance() << " cents in the register";
}
