#include "SearchFoodAction.h"
#include "SearchFoodByCaloriesAction.h"
#include "SearchFoodByNameAction.h"
#include <iostream>

SearchFoodAction::SearchFoodAction() {
    searchActions[1] = new SearchFoodByCaloriesAction();
    searchActions[2] = new SearchFoodByNameAction();
}

void SearchFoodAction::execute() {
    std::cout << "How do you want to search food?"
        << "(1 - by calories, 2 - by name): ";
    std::cin >> choice;

    if (choice <= searchActions.size() && choice > 0) {
        searchActions[choice]->execute();
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        exit(0);
    }
}