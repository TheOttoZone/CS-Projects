// CS 132 - Lab 3 - Classes II.cpp
//

#include <iostream>
#include <vector>

using namespace std;

class Food {
public:
    Food(string name, int calories, string modifer /*vector<string> flavors*/ ) {
        this->name = name;
        this->calories = calories;
        this->modifer = modifer; 
        //this->flavors = flavors;
    };
    int getCalorieCount() {
        return this->calories;
    };
   /* bool hasFlavor(string flavor) {
        for (int i = 0; i < flavors.size(); i++) {
            if (flavors[i] == flavor) {
                return true;
            }
        }
        return false;
    }*/
    string name;
    string modifer; // defines how you describe the item, like *packaged* noodles or *minced* garlic
private:
    int calories;
    //vector<string> flavors;
};

struct ingredient {
    Food food;
    int qty;
};

class Recipe {
public:
    Recipe(string name, int servings) {
        this->name = name;
        this->servings = servings;
    }
    vector<ingredient> ingredients;
    string getName(){
        return this->name;
    }
    int getServings() {
        return this->servings;
    }
    int getCalorieTotal() {
        int calorieTotal = 0;
        for (ingredient ii : ingredients) {
            calorieTotal += ii.food.getCalorieCount();

        }
        return calorieTotal;
    }
    void display() {
        printf("%s\nServes %d\n%d calories\n", this->name.c_str(), this->servings, getCalorieTotal());
        for (ingredient ii : ingredients) {
            if (ii.qty > 1) {
                printf("%d %s %s (%d calories each)\n", ii.qty, ii.food.modifer.c_str(), ii.food.name.c_str(), ii.food.getCalorieCount());
            }else
            printf("%d %s %s (%d calories)\n", ii.qty, ii.food.modifer.c_str(), ii.food.name.c_str(), ii.food.getCalorieCount());
        }

    }
private:
    string name;
    int servings;
};

int main()
{
    // create foods
    Food noodles{ "Spaghetti Noodles", 360, "package" };
    Food tomato{ "Tomatoes", 80, "whole" };
    Food basil{ "Basil", 10, "whole" };
    Food onion{ "Yellow Onion", 120, "chopped" };
    Food garlic{ "Garlic Clove", 20, "minced" };

    // create ingredient versions of the foods with a quantity
    ingredient ingredient_noodles{ noodles, 1 };
    ingredient ingredient_tomato{ tomato, 3 };
    ingredient ingredient_basil{ basil, 2 };
    ingredient ingredient_onion{ onion, 1 };
    ingredient ingredient_garlic{ garlic, 1 };

    // create recipe and print
    Recipe spaghetti{ "Mom's Spaghetti", 6 };
    spaghetti.ingredients = { ingredient_noodles, ingredient_tomato, ingredient_basil, ingredient_onion, ingredient_garlic };
    spaghetti.display();

    system("pause");
    return 0;
}

