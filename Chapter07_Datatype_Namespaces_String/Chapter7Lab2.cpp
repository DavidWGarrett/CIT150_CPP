// David Garrett
// Chapter 7 Lab 2
// 10-21-22

#include <iostream>
#include <string>

using namespace std;

void findSpaces(int& spaceTwo, string info);
void hideSocialSecurity(string& socialSecurity);
void hidePassword(string& password, int spaceTwo);

// Program ask user to enter in their SS#, User ID, and password.
// Program modify the string they entered and prints out a censored version.
// The numbers in the SS# and the characters of the password are replaced by 'x'

int main()
{
    string answer, censoredAnswer = "";
    int spaceTwo;

    cout << "Enter the SS#, user ID, and password. Separate by spaces."
        << "\nFor example: 123-45-6789 Username Password\n";
    getline(cin, answer);

    // Creates new string to modify the contents of the user input
    censoredAnswer.append(answer);

    // finds the positioning of the space between username and password
    findSpaces(spaceTwo, censoredAnswer);

    // replaces the digits of the social security number with 'x'
    hideSocialSecurity(censoredAnswer);

    // replaces the password characters with the same number of 'x'
    hidePassword(censoredAnswer, spaceTwo);

    // prints out censored version of user input
    cout << censoredAnswer;
}

void findSpaces(int& spaceTwo, string info)
{
    // finds first space
    int spaceOne = info.find(" ");

    // finds second space. Value used to find the password in string
    spaceTwo = info.find(" ", spaceOne + 1);
}

void hideSocialSecurity(string& socialSecurity)
{
    int indexDashOne, indexDashTwo;

    // Locate the two dashes in the social security number
    indexDashOne = socialSecurity.find("-");
    indexDashTwo = socialSecurity.find("-", indexDashOne + 1);

    // If the dashes are position correctly, then the SS# gets replaced
    // with 'x'. Program will abort if SS# not properly inputted.
    if (indexDashOne == 3 && indexDashTwo == 6)
    {
        socialSecurity.replace(0, 11, "xxx-xx-xxxx");
    }
    else
    {
        cout << "Social Security Number not properly formatted";
        abort();
    }
}

void hidePassword(string& password, int spaceTwo)
{
    int length;
    string censor = "";

    // Last index value of string
    length = password.length() - 1;

    // figures out length of password. Prepares a new string of 'x' to
    // censor the password
    for (int i = 0; i < length - spaceTwo; ++i)
        censor += "x";

    // replace password with string of 'x'
    password.replace(spaceTwo+1, length - spaceTwo, censor);
}