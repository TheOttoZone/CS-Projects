// While Adder.cpp
//

#include <iostream>
using namespace std;

int main() 
{
	// Declare and initialize variables
	int number = 1, total = 0;

	// Prompt user for numbers
	cout << "Enter in numbers you would like to add! Enter a 0 to end the addition.\n";

	// Continuously allow for input to add numbers
	while (number !=0)
	{
		cin >> number;
		total = total + number;
		if (number !=0)
			cout << "+";
	}		
	
	// Show final total
	cout << "------------\n= " << total << "\n";

	system("pause");
	return(0);
}