#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


// istream constructor
#include <fstream>      // std::filebuf

int main() {
    
    //extern istream david;

    int b, c, d, e, f;
    char g, h, i;
    double k, l, m, n;

    char j = 'b';

    //david >> b >> c;
    double numba = 55;
    cout << scientific << showpoint << numba << endl;

    // setfill, left, right, setw
    
    cout << setfill('A') << setw(100) << "Hello? :" << left << "\n" << setfill('B') << setw(20) << right;

    //cin.get(j);
    //cout << j << " :new value";
    //cout << "\ntest";


    //int a = pow(b, c);
    //cout << a << b << "help";
}

/*
int main()
{
    class istream

    // WON'T WORK WITHOUT ASTERISK
    char c;
    ifstream david;
    david >> c 
    //david >> c;

    char a;
    int b;

    // ENTER CAPITALIZE A, OUTPUT CAPITALIZE A IF CHAR
    // IF INT, LETTERS ARE OUTPUTED AS ZERO, DECIMALS ARE TRUNCATED
    // IF DOUBLE, LETTERS OUTPUTED AS ZERO, DECIMALS ARE NOT TRUNCATED. INTS DISPLAY WITHOUT DECIMAL POINT
    // IT IGNORES WHITE SPACE
    cout << "Enter a character: ";
    cin >> b;
    cout << "You entered " << b << endl;
}
*/