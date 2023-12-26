#include "Menu.h"
#include "MenuAction.h"
#include "ViewFoodListAction.h"
#include "AddFoodItemAction.h"
#include "RemoveFoodItemAction.h"
#include "EditFoodItemAction.h"
#include "SearchFoodByNameAction.h"
#include "SearchFoodByCaloriesAction.h"
#include "ViewFoodByCaloriesDescendingAction.h"
#include "ViewFoodByOrderAction.h"
#include "RecordDailyIntakeAction.h"
#include "FoodLibrary.h"
#include "FoodJournal.h"
#include "FoodItem.h"
#include <iostream>

Menu::Menu() {
    actions[1] = new ViewFoodListAction();
    actions[2] = new AddFoodItemAction();
    actions[3] = new RemoveFoodItemAction();
    actions[4] = new EditFoodItemAction();
    actions[5] = new SearchFoodByNameAction();
    actions[6] = new SearchFoodByCaloriesAction();
    actions[7] = new ViewFoodByOrderAction();
    actions[8] = new ViewFoodByCaloriesDescendingAction();
    actions[9] = new RecordDailyIntakeAction();
}

void Menu::showMenu() const
{
    std::cout << "\tMenu:" << std::endl;
    std::cout << "1. View food library" << std::endl;
    std::cout << "2. Add food to library" << std::endl;
    std::cout << "3. Remove food from library" << std::endl;
    std::cout << "4. Edit food in library" << std::endl;
    std::cout << "5. Search food by name" << std::endl;
    std::cout << "6. Search food by calories" << std::endl;
    std::cout << "7. View food list in aplhapetical order" << std::endl;
    std::cout << "8. View food list in calories descending" << std::endl;
    std::cout << "9. Food diary" << std::endl;
    std::cout << "10. Exit" << std::endl;
}

void Menu::run()
{
    int choice = 0;
    while (true)
    {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice <= actions.size() && choice > 0) {
            actions[choice]->execute();
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
            exit(0);
        }

        /*switch (choice)
        {
        case 1:
            foodLibrary.viewFoodList();
            break;
        case 2:
            foodLibrary.addFoodItem();
            break;
        case 3:
            Menu::nameToRemove;
            std::cout << "Enter the name of the product you want to remove: ";
            std::cin >> nameToRemove;
            foodLibrary.removeFoodItem(nameToRemove);
            break;
        case 4:
            std::cout << "Enter the name of the product you want to edit: ";
            std::cin >> nameToEdit;
            foodLibrary.editFoodItem(nameToEdit);
            break;
        case 5:
            std::cout << "Enter the name of the product you want to find: ";
            std::cin >> nameToSearch;
            foodLibrary.searchFoodByName(nameToSearch);
            break;
        case 6:
            std::cout << "Enter enter calorie limits with using a space: ";
            std::cin >> minCalories >> maxCalories;
            foodLibrary.searchFoodByCalories(minCalories, maxCalories);
            break;
        case 7:
            foodLibrary.viewFoodByAlphabeticalOrder();
            break;
        case 8:
            foodLibrary.viewFoodByCaloriesDescending();
            break;
        case 9:
            foodJournal.recordDailyIntake();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            exit(0);
        }*/

    }
}