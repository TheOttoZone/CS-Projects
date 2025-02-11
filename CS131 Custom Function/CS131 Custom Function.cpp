// CS131 Custom Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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

int main()
{
	int numGrade;
	char curveType;
	int curvePercent;
	
	cout << "Enter in a % grade, then choose either [N]o curve, [S]tandard curve, or Square [R]oot curve, then highest score in the class:";
	cin >> numGrade >> curveType >> curvePercent;
	cout << numGrade << "% is a " << translateGrade(numGrade, curveType, curvePercent) << endl;

	system("pause");
	return(0);
}
