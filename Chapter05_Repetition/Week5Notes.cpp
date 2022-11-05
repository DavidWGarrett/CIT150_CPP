// Week5Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

void firstWhile()
{
    int i = 20; // loop control variable

    while (i <= 20)
    {
        cout << i << " ";
        i += 5;
    }
    cout << "End";
}

void guessNumber()
{
    int num, guess;

    srand(time(0));
    num = rand() % 100;
    cout << "Enter value 0-99: ";
    cin >> guess;

    while (cin)
    {
        if (guess == num)
        {
            cout << "$$$ CORRECT $$$\n";
            break;
        }
        else if (guess < num)
        {
            cout << "*** TOO LOW ***\n\n";
        }
        else
        {
            cout << "### TOO HIGH ###\n\n";
        }

        cout << "Enter value 0-99: ";
        cin >> guess;
    }
    cout << "EOF";
}

void nestedWhile()
{
    int counter = 1;
    int end = 3;

    while (counter == end-2)
    { 
        cout << counter << "\n";
        ++counter;
        while (counter == (end-1))
        {
            cout << (counter - 1) << counter << "\n";
            ++counter;
            while (counter == end)
            {
                cout << (counter - 2) << (counter - 1) << counter << "\n";
                --counter;
                
            }
            cout << (counter - 1) << counter << "\n";
            --counter;
        }
        cout << counter << "\n";
        --counter;
    }
}

void pyramid(int start, int end)
{
    //i++;
    //cout << i;

    //pyramid(i, end);

    //i--;

}

void piii()
{
    double pi = 0;
    long i, n;

    cout << "Enter the value of n: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            pi = pi + (1 / (2 * i + 1));
        }
        else
        {
            pi = pi - (1 / (2 * i + 1));
        }
    }

    pi = 4 * pi;

    cout << endl << "pi = " << pi << endl;
}

int main()
{
    piii();
}