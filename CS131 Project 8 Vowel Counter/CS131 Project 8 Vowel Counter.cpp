// CS131 Project 8 Vowel Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int WORD_LENGTH = 10;

const char vowels[] = {'a','e','i','o','u'};

int main()
{
    char word[WORD_LENGTH + 1];
    int wordVowelCount = 0;
    cout << "Input a word that is " << WORD_LENGTH << " letters long or less: ";
    cin >> word;

    for (int i = 0; i <= sizeof(word); i++) {
        for (int ii = 0; ii <= sizeof(vowels) - 1; ii++) {
            if (word[i] == vowels[ii]) {
                wordVowelCount++;
            }
        }
    }

    cout << endl << "There are " << wordVowelCount << " vowels in " << word << "." << endl;
}
