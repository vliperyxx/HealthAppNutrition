#include "FoodDiaryAction.h"
#include "RecordDailyIntakeAction.h"
#include "ViewFoodDiaryAction.h"
#include <iostream>

FoodDiaryAction::FoodDiaryAction() {
    foodDiaryActions[1] = new RecordDailyIntakeAction();
    foodDiaryActions[2] = new ViewFoodDiaryAction();
}

void FoodDiaryAction::execute() {
    std::cout << "What do you want to do with food diary?"
        << "(1 - add an entry, 2 - view entries): ";
    std::cin >> choice;

    if (choice <= foodDiaryActions.size() && choice > 0) {
        foodDiaryActions[choice]->execute();
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        exit(0);
    }
}