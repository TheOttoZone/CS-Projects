// CS131 Call by Reference Change Maker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

using namespace std;

// Separates the change for the transaction into the different coins/dollars
void makeChange(double amount, int& dollars, int& quarters, int& dimes, int& nickels, int& cents) {
    dollars = amount;
    cents = (amount - dollars) * 100;
    quarters = cents / 25;
    cents = cents - (quarters * 25);
    dimes = cents / 10;
    cents = cents - (dimes * 10);
    nickels = cents / 5;
    cents = cents - (nickels * 5);
}

int main()
{
    // easier to understand/use random generator that i found
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(0.01, 100); // generates a random number between 0.01 and 100 with double floating point precision

    // initialize variables and round the cost equal to a random number to two decimal places.
    double amount, owe, cost = round(distribution(generator) * 100) / 100;
    int dollars, quarters, dimes, nickels, cents;
    
    cout.precision(2); // set cout to only show 2 decimal places. $69.69000000 is ugly!
    cout << "You have purchased a random box of randomness! It costs $" << fixed << cost << "." << endl << "Pay up:";
    cin >> amount;
   
    // if we enter a number lower than the cost, ask for more money and add that to the amount given
    while (amount < cost) {
        cout << "Are you trying to swindle me? Give me the rest of the money! You owe me $" << cost - amount << "!" << endl;
        cin >> owe;
        amount = amount + owe;
    }
    
    // subtract the cost from the amount given to determine our leftover amount we need to separate into coins
    amount = amount - cost + 0.002;
    makeChange(amount, dollars, quarters, dimes, nickels, cents);
    
    // final output
    cout << "Thank you! Your change is:" << endl << dollars << " dollars, " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << cents << " pennies." << endl;
    system("pause");
    return 0;
}
