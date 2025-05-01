// CS 132 - Lab 2 - Classes.cpp 
//

#include <iostream>
#include <vector>

using namespace std;

class Food {
public:
    Food(string name, int calories, vector<string> flavors) {
        this->name = name;
        this->calories = calories;
        this->flavors = flavors;
    };
    int getCalorieCount() {
        return this->calories;
    };
    bool hasFlavor(string flavor) {
        for (int i = 0; i < flavors.size(); i++) {
            if (flavors[i] == flavor) {
                return true;
            }
        }
        return false;
    }
    string name;
private:
    int calories;
    vector<string> flavors;
};

int main()
{
    vector<Food> foods{
        { "Grilled Cheese", 350, {"cheesy", "gooey"} },
        { "Chocoloate Cake", 400, { "sweet", "rich" } },
        { "Strawberry" , 4, {"sweet", "juicy", "tart" } },
        { "Cheeseburger" , 800, {"cheesy", "juicy"}}
    };
    string search;
    do {
        cout << "Enter in a flavor to search for: ";
        cin >> search;
        for (Food food : foods) {
            if (food.hasFlavor(search)) {
                cout << food.name << ", " << food.getCalorieCount() << " calories" << endl;
            }
        }
    } while (search != "q");
    return 0;
}

