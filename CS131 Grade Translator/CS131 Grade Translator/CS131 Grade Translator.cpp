// CS131 Grade Translator.cpp
// Translate a % grade into a letter grade

# include <iostream>
using namespace std;

int main()
{
	// Declare grade variable
	int grade;

	// Prompt user for a grade
	cout << "Enter in a % grade:";
	cin >> grade;

	// Compare entered grade to certain ranges, replicating the grading scale in other IT classes.
	if (grade >= 93)
		cout << grade << "% is an A. ";
	else if (grade >= 90)
		cout << grade << "% is an A-. ";
	else if (grade >= 87)
		cout << grade << "% is a B+. ";
	else if (grade >= 83)
		cout << grade << "% is a B. ";
	else if (grade >= 80)
		cout << grade << "% is a B-. ";
	else if (grade >= 77)
		cout << grade << "% is a C+. ";
	else if (grade >= 73)
		cout << grade << "% is a C. ";
	else if (grade >= 70)
		cout << grade << "% is a C-. ";
	else if (grade >= 67)
		cout << grade << "% is a D+. ";
	else if (grade >= 63)
		cout << grade << "% is a D. ";
	else if (grade >= 60)
		cout << grade << "% is a D-. ";
	else if (grade < 60)
		cout << grade << "% is an F. ";
	
	system("pause");
	return(0);
}
 