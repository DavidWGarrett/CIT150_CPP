#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void passFail()
{
    int g;

    cout << "Write a full number for a grade: ";
    cin >> g;

    if (g >= 70) {
        // pass
        cout << "Pass";
    }
    else {
        // fail
        cout << "Fail";
    }

}

void evalTest() {
    int g = (90 == 80);
    cout << g;

    // IT EVALUATES TO 0, NOT FALSE
}

char grades() {

    int grade;

    cout << "Input a whole number grade: ";
    cin >> grade;

    if (grade >= 90)
    {
        cout << "Your grade is an A" << endl;
        //cout << "Multiple statements";
        return 'A';
    }
    else if (grade >= 80)
    {
        cout << "Your grade is a B";
        return 'B';
    }
    else {
        if (grade >= 70) {
            cout << "Your grade is a C";
            return 'C';
        }
        else {
            cout << "You grade is an F";
            return 'F';
        }
    }
}

void switch1(char grade) {

    string pass;

    switch (grade)
    {
    case 'A':
        cout << "\nGreat Job";
        break;
    case 'B': 
        cout << "\nGood";
        break;
    case 'C':
        cout << "\nTry harder";
        break;
    case 'F':
        cout << "\nAwful";
        break;
    default:
        cout << "\nProg didn't work";
    }

    // If 'A', 'B', or 'C', pass
    // If 'F', fail

    pass = (grade < 'F') ? "You Passed" : "You Failed";
    cout << "\n" << pass;
}

void eval2() {
    bool g = true;

    cout << g; //outputs as 1
}

void questionOp() {}

int main()
{
    //grades();
    //eval2();

    switch1(grades());
}