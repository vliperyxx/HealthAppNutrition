#include "SearchFoodByCaloriesAction.h"
#include <iostream>

void SearchFoodByCaloriesAction::execute() {
    std::string nameToSearch;
    std::cout << "Enter the name of the product you want to find: ";
    std::cin >> nameToSearch;
    foodLibrary.searchFoodByName(nameToSearch);
}
