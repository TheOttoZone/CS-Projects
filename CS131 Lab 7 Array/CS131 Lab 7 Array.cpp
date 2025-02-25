// CS131 Lab 7 Array.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

using namespace std;

// Set the size of the arrays
const int ARRAY_SIZE = 5;

// Initialize functions
int findMaxScore(int Array[], int size);
int findMinScore(int Array[], int size);
int findAvgScore(int Array[], int size);

int main()
{
	 //1. Initialize arrays
	int scores[ARRAY_SIZE];
	string names[ARRAY_SIZE];
	//2. Prompt user for scores and names
	cout << "Input 5 student names: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> names[i];
	}

	cout << endl << "Input their 5 matching test scores: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> scores[i];
	}

	//3. Output highest score
	cout << endl << names[findMaxScore(scores, ARRAY_SIZE)] << " got the highest score with a " << scores[findMaxScore(scores, ARRAY_SIZE)] << ".\n\n";

	//4. Output lowest score
	cout << names[findMinScore(scores, ARRAY_SIZE)] << " got the lowest score with a " << scores[findMinScore(scores, ARRAY_SIZE)] << ".\n\n";

	//5. Output average score
	int numAverage = findAvgScore(scores, ARRAY_SIZE);
	cout << "The average score was a " << numAverage << ".\n\n";
	
	//6. Output who was closest to average
	int scoreDiff[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		scoreDiff[i] = abs(numAverage - scores[i]);
	}
	cout << names[findMinScore(scoreDiff, ARRAY_SIZE)] << " was the closest to the average.\n\n";

	system("pause");
	return 0;
}

int findMaxScore(int Array[], int size) {
	int num = Array[0];
	int renum = 0;
	for (int i = 0; i < size; i++) {
		if (Array[i] > num) {
			num = Array[i];
			renum = i;
		}
	}
	return renum;
}

int findMinScore(int Array[], int size) {
	int num = Array[0];
	int renum = 0;
	for (int i = 0; i < size; i++) {
		if (Array[i] < num) {
			num = Array[i];
			renum = i;
		}
	}
	return renum;
}

int findAvgScore(int Array[], int size) {
	int num = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		num = num + Array[i];
	}
	num = num / ARRAY_SIZE;
	return num;
}