// Added in the header

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	// Declare variables, numberOfGuesses needs to be 1 less than the desired amount
	int numberToGuess, numberGuessed, numberOfGuesses = 2;

	// initialize random number
	srand(time(NULL));
	numberToGuess = rand() % 10 + 1;
	
	// Debug cheat
	//cout << numberToGuess;

	// Prompt user for their first guess
	cout << "Guess a number from 1-10!\n";
	cin >> numberGuessed;

	// Logic for repeat guesses or winning
	for (; numberOfGuesses > 0; numberOfGuesses--) {
		if (numberGuessed == numberToGuess) {
			if (numberOfGuesses == 2) {
				cout << "You guessed the number first try! Wow!\n";
				break;
			}
			else {
				cout << "You guessed the number!\nYou guessed it in " << 3 - numberOfGuesses << " tries! ";
				break;
			}
		}
		else if (numberGuessed < numberToGuess) {
			cout << "Higher!";
			cin >> numberGuessed;
		}
		else if (numberGuessed > numberToGuess) {
			cout << "Lower!";
			cin >> numberGuessed;
		}			
	}
	
	// Logic for not guessing the number
	if (numberOfGuesses == 0) {
		cout << "You did not guess the number. It was " << numberToGuess << ".\n";
	}

	system("pause");
	return(0);
}