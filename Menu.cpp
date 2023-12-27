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
#include "ViewFoodDiaryAction.h"
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
    actions[10] = new ViewFoodDiaryAction();
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
    std::cout << "9. Add an entry to the food diary" << std::endl;
    std::cout << "10. View food diary" << std::endl;
    std::cout << "11. Exit" << std::endl;
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
    }
}