
// BankClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using namespace std;

class BankAcct {
public:
	// constructors
	BankAcct() {} // if there are no parameters, it is a default constructor
	BankAcct(string name, double balance) {
		(*this).name = name;
		this->balance = balance; // arrow is shorthand for dereferencing and dot notation
	}
	// properties
	string name;
	// methods
	void transfer(BankAcct b1, BankAcct b2, double amnt);
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		this->balance += amount;
	}
	void print();
private:
	double balance = 0;
};
// declaring a function
void displayAccts(vector<BankAcct> accts);
int main()
{
	// set output flags so that we display 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	char choice;
	vector<BankAcct> accts;
	/// Test data
	BankAcct wecu("WECU", 3.50);
	BankAcct icu("ICU", 24.98);
	BankAcct becu;
	becu.name = "BECU";
	becu.deposit(100.00);
	accts.push_back(wecu);
	accts.push_back(icu);
	accts.push_back(becu);
	///
	do {
		// display interface
		system("cls");
		cout << "Account\tBalance\n";
		cout << "------------------------\n";
		displayAccts(accts);
		cout << "(A)dd\t(R)emove\t(D)eposit\t(Q)uit\n\n";
		// user input
		string name;
		string name2;
		double balance;
		double amount;
		BankAcct newAcct;
		cin >> choice;
		choice = tolower(choice);
		switch (choice) {
		case 'a':
			// Add account
			cout << "Enter an account name: ";
			cin >> newAcct.name;
			cout << "Enter an account balance: ";
			cin >> balance;
			newAcct.deposit(balance);
			accts.push_back(newAcct);
			break;
		case 'r':
			// Remove an account
			cout << "Enter an account name: ";
			cin >> name;
			for (int i = 0; i < accts.size(); i++) {
				if (accts[i].name == name) {
					accts.erase(accts.begin() + i);
				}
			}
			break;
		case 'd':
			// Deposit into an account
			cout << "Enter an account name: ";
			cin >> name;
			cout << "Enter a deposit amount: ";
			cin >> amount;
			for (BankAcct& acct : accts) {
				if (acct.name == name) {
					acct.deposit(amount);
					break;
				}
			}
			break;
		case 't':
			wecu.transfer(wecu, becu, 5);
		case 'q':
			// Quit program
			cout << "Quitting... \n";
			break;
		}
	} while (choice != 'q');
}
// define function
void displayAccts(vector<BankAcct> accts)
{
	// FOREACH LOOP
	for (BankAcct& acct : accts) {
		acct.print();
	}
}
void BankAcct::print()
{
	cout << this->name << "\t" << this->getBalance() << "\n";
}

void BankAcct::transfer(BankAcct b1, BankAcct b2, double amnt) {
	b1.balance -= amnt;
	b2.balance += amnt;
}