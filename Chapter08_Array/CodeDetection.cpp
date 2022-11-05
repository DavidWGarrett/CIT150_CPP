// David Garrett
// Chapter 8 Lab 1 Code Detection
// 10-24-22

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void goodLength(int length);
int getNumber(ifstream& file);
void readCode(ifstream& file, int code[], int& length);
bool codeSame(int code[], int length);
void printCode(ofstream& output, int code[], int length);

const int LIMIT = 250;

// Program will read a text file that has a code and a duplicate code. The first number
// will tell the program the length of the code. Using that length, the program will
// initialize all the values in the code into an array. Afterwards, will compare the two codes
// to see if they are the same or not, and then specify if the codes match. The results are
// outputed to console and an output text file.

int main()
{
    ifstream infile;
    ofstream outfile;
    string input, output;
    int length = 0;
    int code[LIMIT];

    cout << "Enter the input file name: ";
    cin >> input;
    infile.open(input);

    // Program will exit if input file does not exist
    if (!infile.fail())
    {
        cout << "Enter the output file name: ";
        cin >> output;
        outfile.open(output);

        // Initialize code to array
        readCode(infile, code, length);

        // Print code to console/output file
        printCode(outfile, code, length);

        // Tells user if two codes are the same or not
        if (codeSame(code, length))
            cout << "Message transmitted OK.";
        else
            cout << "Two Codes are not the same. Message not OK.";
    }
    else
        cout << "The file you typed in does not exist.";

}


int getNumber(ifstream& file)
{
    int counter = 0;
    int value;
    char numList[LIMIT];
    char chara = file.get();

    // Creates character array of only numbers. Will stop looping when program
    // reads a space
    while (static_cast<int>('0') <= chara && chara <= static_cast<int>('9'))
    {
        numList[counter] = chara;
        chara = file.get();
        counter++;
    }

    // Converts character array to integer
    value = atoi(numList);

    // Return that value to readCode function
    return value;
}

void readCode(ifstream& file, int code[], int& length)
{
    // Initialize the values read from the text file into an array

    // Initialize values before for loop
    int convertedNumber = getNumber(file);
    length = code[0] = convertedNumber;
    goodLength(length); // Test to see if length is over 250. Abort if over 250
    length += 1;

    for (int i = 1; i < ((length*2)); ++i)
    {
        int convertedNumber = getNumber(file);
        code[i] = convertedNumber;
    }
}

bool codeSame(int code[], int length)
{
    // Test to see if of the two codes have the same values
    bool codeSame = true;

    for (int i = 0; i < length - 1; ++i)
    {
        if (code[i] != code[i + length])
        {
            codeSame = false;
            break;
        }
    }
    return codeSame;
}

void printCode(ofstream& output, int code[], int length)
{
    // Will print code and a copy code to console and output file

    cout << setw(12) << "Code Digit"
         << setw(17) << "Code Digit Copy" << endl;

    output << setw(12) << "Code Digit"
           << setw(17) << "Code Digit Copy" << endl;

    for (int i = 1; i < length; ++i)
    {
        cout << setw(7) << code[i]
            << setw(15) << code[i + length] << endl;

        output << setw(7) << code[i]
            << setw(15) << code[i + length] << endl;
    }        
}

void goodLength(int length)
{
    // Test to see if length of first number of the code is over 250
    // Will abort program if over 250

    if (length > LIMIT)
    {
        cout << "The length is over 250, the program will now terminate";
        abort();
    }
}