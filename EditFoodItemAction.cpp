#include "EditFoodItemAction.h"
#include <iostream>

void EditFoodItemAction::execute() {
    std::string nameToEdit;
    std::cout << "Enter the name of the product you want to edit: ";
    std::cin.ignore();
    std::getline(std::cin, nameToEdit);
    foodLibrary.editFoodItem(nameToEdit);
}
