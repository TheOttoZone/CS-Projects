// CS131 Project 8 Vowel Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// define word length
const int WORD_LENGTH = 10;

// define vowel set I HATE Y I HATE Y
const char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};

int main()
{
    // define word array with length word length + 1 to account for terminating character
    char word[WORD_LENGTH + 1];
    int wordVowelCount = 0;

    // prompt user for word
    cout << "Input a word that is " << WORD_LENGTH << " letters long or less: ";
    cin >> word;

    // go through each letter in word and check if it is any of the vowels
    for (int i = 0; i <= sizeof(word); i++) {
        for (int ii = 0; ii <= sizeof(vowels) - 1; ii++) {
            if (word[i] == vowels[ii]) {
                wordVowelCount++;
            }
        }
    }

    // output vowel count
    cout << endl << "There are " << wordVowelCount << " vowels in " << word << "." << endl;

    // flush cin just in case the user went over the word length
    cin.clear();
    fflush(stdin);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // define line string
    string line;
    int lineVowelCount = 0;

    // prompt user for something to count vowels in
    cout << "Type anything here to have its vowels counted: ";
    getline(cin, line);

    // count vowels in the string except its a lot nicer and only works with string for some reason
    for (int i = 0; i < sizeof(vowels); i++) {
        lineVowelCount += count(line.begin(), line.end(), vowels[i]);
    }

    // output vowel count
    cout << "There are " << lineVowelCount << " vowels in that sentence you entered!";
}
