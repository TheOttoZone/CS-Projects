// Vectors, strings, structs oh my!.cpp 

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*1) Download the input file named persons.txt

Download persons.txt and place it in a directory that you can read from.*/
const string FILE_LOCATION = "D:\\CS132\\persons.txt";

// 2) Produce a new Person struct definition to contain a person's info.
struct Person {
	string ssn;
	string fName;
	string lName;
	string email;
};

// 4) Create a readPerson pass - by - reference function that takes the input file stream, 
// reads each person's info into an vector of Person structs, and returns that vector
vector<Person> readPerson(ifstream& inFile) {
	inFile.open(FILE_LOCATION);
	string line, col;
	vector<Person> people;

	while (getline(inFile, line)) {
		stringstream inString(line);
		Person p;
		int i = 0;
		while (getline(inString, col, '\t')) {
			switch (i) {
			case 0:
				p.ssn = col;
				break;
			case 1:
				p.fName = col;
				break;
			case 2:
				p.lName = col;
				break;
			case 3:
				p.email = col;
				break;
			}
			i++;
		}
		people.push_back(p);
	}
	return people;
}

int main()
{
	// 3) Open the file input stream.
	ifstream inFile;

	// 5) In main, loop through the vector and print each Person to the console in this format: 
	// DYSON, DON : 2222 : ddson@hotmail.com(printf might make this a little easier)
	for (Person& p : readPerson(inFile)) {
		printf("%s, %s:%s:%s\n\n", p.lName.c_str(), p.fName.c_str(), p.ssn.c_str(), p.email.c_str());
	}
	system("pause");
	return 0;
}

