#include "ViewFoodAction.h"
#include "ViewFoodByCaloriesDescendingAction.h"
#include "ViewFoodByOrderAction.h"
#include <iostream>

    ViewFoodAction::ViewFoodAction() {
    viewActions[1] = new ViewFoodByOrderAction();
    viewActions[2] = new ViewFoodByCaloriesDescendingAction();
}

void ViewFoodAction::execute() {
    std::cout << "How do you want to view food library?"
        << "(1 - by alphabetical order, 2 - by calories descending): ";
    std::cin >> choice;

    if (choice <= viewActions.size() && choice > 0) {
        viewActions[choice]->execute();
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        exit(0);
    }
}