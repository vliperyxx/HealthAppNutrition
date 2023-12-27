#include "FoodItemAction.h"
#include "AddFoodItemAction.h"
#include "EditFoodItemAction.h"
#include "ViewFoodListAction.h"
#include "RemoveFoodItemAction.h"
#include <iostream>

FoodItemAction::FoodItemAction() {
    foodItemActions[1] = new ViewFoodListAction();
    foodItemActions[2] = new AddFoodItemAction();
    foodItemActions[3] = new EditFoodItemAction();
    foodItemActions[4] = new RemoveFoodItemAction();
}

void FoodItemAction::execute() {
    std::cout << "What do you want to do with food?"
        << "(1 - view food list, 2 - add food, 3 - edit food, 4 - remove food): ";
    std::cin >> choice;

    if (choice <= foodItemActions.size() && choice > 0) {
        foodItemActions[choice]->execute();
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        exit(0);
    }
}