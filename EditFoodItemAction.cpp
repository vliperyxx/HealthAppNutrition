#include "EditFoodItemAction.h"

void EditFoodItemAction::execute() {
    std::string nameToEdit;
    foodLibrary.editFoodItem(nameToEdit);
}
