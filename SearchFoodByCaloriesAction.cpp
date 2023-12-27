#include "SearchFoodByCaloriesAction.h"
#include <iostream>

void SearchFoodByCaloriesAction::execute() {
    double minCalories, maxCalories;
    std::cout << "Enter enter calorie limits with using a space: ";
    std::cin >> minCalories >> maxCalories;
    foodLibrary.searchFoodByCalories(minCalories, maxCalories);
}
