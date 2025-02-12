// CS131 Proj 6 FileIO Grade Translator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const string filepath = "D:\\CS131\\Folder\\";
const string filename = "gradedata.txt";

// Grade translator
string translateGrade(int numGrade, char curveType, int curvePercent) {
	switch (curveType) {
	case 'S': case 's':
		numGrade = (numGrade + (100 - curvePercent));

	case 'R': case 'r':
		numGrade = (sqrt(numGrade) * 10);
	default:
		break;
	}

	if (numGrade >= 93)
		return "A";
	else if (numGrade >= 90)
		return "A-";
	else if (numGrade >= 87)
		return "B+";
	else if (numGrade >= 83)
		return "B";
	else if (numGrade >= 80)
		return "B-";
	else if (numGrade >= 77)
		return "C+";
	else if (numGrade >= 73)
		return "C";
	else if (numGrade >= 70)
		return "C-";
	else if (numGrade >= 67)
		return "D+";
	else if (numGrade >= 63)
		return "D";
	else if (numGrade >= 60)
		return "D-";
	else if (numGrade < 60)
		return "F";
}

// swap function
void swapInts(int& n1, int& n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int main()
{
	ifstream inFile;
	ofstream outFile;
	int numGrade;
	char curveType;
	int curvePercent;
	inFile.open(filepath + filename);

	// choose a curve type
	cout << "Choose a curve type: [N]o curve, [S]tandard curve, or Square [R]oot curve:";
	cin >> curveType;

	// swap code to find the highest grade
	int lastNum = -1;
	string name;
	while (inFile >> name >> numGrade) {
		if (lastNum == -1) {
			lastNum = numGrade;
			continue;
		}
		// compare them and IF out of order
		if (lastNum > numGrade) {
			// THEN swap
			swapInts(lastNum, numGrade);
		}
		lastNum = numGrade;
	}
	// reopen the file to go through it again and set the curve percent to the highest grade we found in the file
	inFile.close();
	inFile.open(filepath + filename);
	curvePercent = numGrade;

	// output the final grades of the students to the console
	while (inFile >> name >> numGrade) {
		cout << name << " " << translateGrade(numGrade, curveType, curvePercent) << endl;
	}
	system("pause");
	return(0);
}
