/*
David Garrett
Chapter 10 Lab 2
11-10-22
*/

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time t1(3);
    cout << "With one valid argument: ";
    t1.display();
    Time t2(23, 20);
    cout << "With two valid arguments: ";
    t2.display();
    Time t3(24, 1);
    cout << "With invalid hours: ";
    t3.display();
    Time t4(12, 62);
    cout << "With invalid minutes: ";
    t4.display();
    cout << "Going to new hour: ";
    t1.display();
    t1.add(65);
    t1.display();
    cout << "Going to new day: ";
    t2.display();
    t2.add(55);
    t2.display(); // I have the first hour start at 0 rather than 1
    return 0;
}