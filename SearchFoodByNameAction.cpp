#include "SearchFoodByNameAction.h"
#include <iostream>

void SearchFoodByNameAction::execute() {
    std::string nameToSearch;
    std::cout << "Enter the name of the product you want to find: ";
    std::cin >> nameToSearch;
    foodLibrary.searchFoodByName(nameToSearch);
    std::cin >> nameToSearch;
}
