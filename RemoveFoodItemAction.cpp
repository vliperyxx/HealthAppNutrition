#include "RemoveFoodItemAction.h"
#include <iostream>

void RemoveFoodItemAction::execute() {
    std::string nameToRemove;
    std::cout << "Enter the name of the product you want to remove: ";
    std::cin >> nameToRemove;
   foodLibrary.removeFoodItem(nameToRemove);
}
