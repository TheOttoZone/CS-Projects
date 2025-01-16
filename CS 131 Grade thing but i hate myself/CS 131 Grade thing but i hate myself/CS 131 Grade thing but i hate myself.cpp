// Grade translator that does not use ifs or logic!
#include <iostream>
using namespace std;

int main()
{
    int numgrade;
    char lettergrade;

    // Prompt user for a grade
    cout << "Enter in a % grade:";
    cin >> numgrade;

    // Old non working mathmatical solution that gets E's and G's and stuff
    lettergrade = abs((numgrade/10)-74);
    cout << lettergrade;

    //// Take the inputted grade and use it as the index for an array that has 100 numbers and use them as ascii characters 
    //char array[100] = { 70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,68,68,68,68,68,68,68,68,68,68,67,67,67,67,67,67,67,67,67,67,66,66,66,66,66,66,66,66,66,66,65,65,65,65,65,65,65,65,65,65 };
    //cout << array[numgrade];

    system("pause");
    return(0);
}
