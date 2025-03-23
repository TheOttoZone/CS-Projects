// BankStruct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct BankAcct {
	string name;
	double balance;
	int id;
};

// declaring a function
void displayAccts(vector<BankAcct> a);

int main()
{
	// set output flags so that we display 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	char choice;
	//int acctsSize = 0;
	vector<BankAcct> accts;
	int idChoice[2]; // made this an array to be able to use 1 variable for the ids in transferring, probably NOT the best way to do this
	int input;
	string sInput;
	double dInput;

	/// Test data
	BankAcct wecu{ "WECU", 3.50, 0 };
	BankAcct icu{ "ICU", 24.98, 1 };
	accts.push_back(wecu);
	accts.push_back(icu);
	//acctsSize = 2;

	do {
		// display interface
		system("cls");
		cout << "ID\tAccount\tBalance\n";
		cout << "------------------------\n";
		displayAccts(accts);//, acctsSize);
		cout << "(A)dd\t(D)eposit\t(W)ithdraw\t(T)ransfer\t(R)emove\t(Q)uit\n\n";
		//cout << accts.size();
		// user input
		cin >> choice;
		choice = tolower(choice);
		switch (choice) {
		case 'a':
			// Add account
			cout << "Enter an account name: ";
			cin >> sInput;
			cout << "Enter an account balance: ";
			cin >> dInput;
			// if there are no accounts, give this account an id of 0 instead of 1 more than the last account.
			if (!accts.empty()) {
				accts.push_back({ sInput , dInput, accts.back().id + 1 });
			}
			else {
				accts.push_back({ sInput , dInput, 0 });
			}
			
			//accts[acctsSize].id = accts[acctsSize - 1].id + 1;
			//acctsSize++;
			break;
		case 'd':
			// Deposit
			cout << "Enter an account id: ";
			cin >> idChoice[0];
			cout << "Enter the amount to deposit: ";
			cin >> input;
			accts[idChoice[0]].balance += input;
			break;
		case 'w':
			// Withdraw
			cout << "Enter an account id: ";
			cin >> idChoice[0];
			cout << "Enter the amount to withdraw: ";
			cin >> input;
			accts[idChoice[0]].balance -= input;
			break;
		case 't':
			// Transfer
			cout << "Enter the account id to transfer funds from: ";
			cin >> idChoice[0];
			cout << "Enter the account id to transfer funds to: ";
			cin >> idChoice[1];
			cout << "Enter the amount of funds to transfer: ";
			cin >> dInput;
			if (dInput > accts[idChoice[0]].balance) {
				cout << "The initial account does not have enough funds to complete the requested transfer. Please try again.";
				break;
			}
			accts[idChoice[0]].balance -= dInput;
			accts[idChoice[1]].balance += dInput;
			break;
		case 'r':
			// Remove
			cout << "Enter the account id to remove: ";
			cin >> idChoice[0];
			accts.erase(accts.begin() + idChoice[0]);
		case 'q':
			// Quit program
			cout << "Quitting... \n";
			break;
		}
	} while (choice != 'q');
}

// define function
void displayAccts(vector<BankAcct> a)
{
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].id << "\t" << a[i].name << "\t" << a[i].balance << "\n";
	}
}