// David Garrett
// Chapter 7 Lab 1 Pig Latin
// 10-23-22

#include <iostream>

using namespace std;

void addWay(string& input);
void addDash(string& input);
void addAy(string& input);
bool containsVowel(string& input);
bool containsVowel(char firstElement);
void rotateCharacters(string& input);
void convertToPigLatin(string& word);

// Program translate a word into pig Latin. 

int main()
{
    string word, translatedWord;

    // User enters a word in
    cout << "Enter in any word and it'll be converted to pig Latin: ";
    cin >> word;

    translatedWord = "" + word;

    // Converts to pig Latin
    convertToPigLatin(translatedWord);

    // Display the translated word
    cout << "The pig latin form of " << word << " is: " << translatedWord;

    return 0;
}

// AddWay, addDash, addAy appends the appropriate characters when needed during translation
void addWay(string& input)
{
    input.append("-way");
}

void addDash(string& input)
{
    input.append("-");
}

void addAy(string& input)
{
    input.append("ay");
}

bool containsVowel(string& input)
{
    // Function determines if word has a vowel. It'll iterate through
    // each character and return a true or false if there's a vowel

    bool containsVowel = false;

    for (int i = 0; i < input.length(); ++i)
    {
        switch (input[i])
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            containsVowel = true;
            break;
        }
    }

    return containsVowel;
}

bool containsVowel(char firstElement)
{
    // Function determins if first character is a vowel. Return true if
    // it is a vowel.
    // Also, example of function overloading

    bool containsVowel = false;

    switch (firstElement)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        containsVowel = true;
    }

    return containsVowel;
}

void rotateCharacters(string& input)
{
    // Function moves the first character to the end and move
    // all other characters forward 1 index.
    // New string is created which appends the new characters in the
    // appropriate order.

    string rotated = "";

    for (int i = 0; i < input.length() - 1; ++i)
    {
        rotated.append(1, input[i + 1]);
    }

    rotated.append(1, input[0]);

    // string in main is rotated
    input.swap(rotated);
}

void convertToPigLatin(string& word)
{
    // Decision tree based on the rules of pig Latin.
    // Will add "-", "ay", "way" at approprioate times or
    // rotate the characters of the word

    // Contains Vowels
    if (containsVowel(word))
    {
        if (containsVowel(word[0]))
            addWay(word);
        else
        {
            addDash(word);

            while (!containsVowel(word[0]))
                rotateCharacters(word);

            addAy(word);
        }
    }
    // No vowels, add "-way"
    else
        addWay(word);
}