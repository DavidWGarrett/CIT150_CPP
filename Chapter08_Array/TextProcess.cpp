/*
David Garrett
Chapter 8 Lab 1 Text Processing
10-27-22
*/

#include <iostream>
#include <fstream>
using namespace std;

void copyText(ifstream& input, ofstream& output, char& ch, int list[]);
void characterCount(char chara, int letterCount[]);
void countMessage(ofstream& output, int lines, int letterCount[]);

const int LIMIT = 26;

/*
Program reads a text file, process through each character in the text file, 
make a tally for each kind of letter in text file, and output the results
into the console and a new text file
*/

int main()
{
    ifstream input;
    ofstream output;
    int letters[LIMIT];
    int lines = 0;
    char chara;

    // Initialize 26 integers of value 0 to the letters array
    for (int i = 0; i < LIMIT; ++i)
        letters[i] = 0;

    input.open("input.txt");

    // Must have input.txt file with the code of the program
    if (!input.fail())
    {
        output.open("output.txt");

        // Get first character of input text file
        chara = input.get();

        // Will loop till end of file on input text file
        while (!input.eof())
        {
            // Will copy characters from input file to output file and console
            copyText(input, output, chara, letters);
            lines++; // Counts lines in text file. copyText iterates one line at a time. 
            chara = input.get(); // Get next character after a newline
        }

        // Save lines and letters to text file and display on console
        countMessage(output, lines, letters);

        // Disassociate variables from file name
        input.close();
        output.close();
    }
    else
        cout << "Cannot open input file.";
}

void copyText(ifstream& input, ofstream& output, char& ch, int list[])
{
    while (ch != '\n')
    {
        cout << ch; // output the character to console
        output << ch; //output the character to text file
        characterCount(ch, list); // counts letters
        ch = input.get(); //read the next character

        if (input.eof()) // exit loop if at end of file where there's no newline character
            break;
    }
    cout << '\n'; // Add new line to console

    if (!input.eof())
        output << ch; //output the newline character to text file
}

void characterCount(char chara, int letterCount[])
{
    int asciiChara = static_cast<int>(chara);
    // Uppercase 65-90 Lowercase 97-122

    int lowerCaseA = static_cast<int> ('a');
    int lowerCaseZ = static_cast<int> ('z');
    int upperCaseA = static_cast<int> ('A');
    int upperCaseZ = static_cast<int> ('Z');

    // Determines if character is a letter or not
    bool lowerCaseLetter = ((lowerCaseA <= asciiChara) && (asciiChara <= lowerCaseZ));
    bool upperCaseLetter = ((upperCaseA <= asciiChara) && (asciiChara <= upperCaseZ));

    if (lowerCaseLetter || upperCaseLetter)
    {
        // If it's a lower case letter, will calculate the upper case letter ascii value
        if (lowerCaseLetter)
        {
            asciiChara -= lowerCaseZ - upperCaseZ;
        }

        // After which letter is determined, that letter's count will be incrimented one
        // inside of the array
        letterCount[asciiChara - upperCaseA]++;
    }
}

void countMessage(ofstream& output, int lines, int letterCount[])
{
    // Print number of lines to console and output text file
    cout << "The number of lines = " << lines << endl;
    output << "\nThe number of lines = " << lines << endl;

    // Print the number of each letters to console and output text file
    for (int i = 0; i < LIMIT; ++i)
    {
        cout << static_cast<char>(i + static_cast<int> ('A')) << " count = "
            << letterCount[i] << endl;
        output << static_cast<char>(i + static_cast<int> ('A')) << " count = "
            << letterCount[i] << endl;
    }
}

