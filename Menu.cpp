#include "Menu.h"
#include "MenuAction.h"
#include "FoodItemAction.h"
#include "SearchFoodAction.h"
#include "ViewFoodAction.h"
#include "FoodDiaryAction.h"
#include "FoodLibrary.h"
#include "FoodJournal.h"
#include "FoodItem.h"
#include <iostream>

Menu::Menu() {
    actions[1] = new FoodItemAction();
    actions[2] = new SearchFoodAction();
    actions[3] = new ViewFoodAction();
    actions[4] = new FoodDiaryAction();
}

void Menu::showMenu() const
{
    std::cout << "\tMenu:" << std::endl;
    std::cout << "1. Food library" << std::endl;
    std::cout << "2. Search food" << std::endl;
    std::cout << "3. View food list" << std::endl;
    std::cout << "4. Food diary" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void Menu::run()
{
    while (true)
    {
        int choice = 0;
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice <= actions.size() && choice > 0) {
            actions[choice]->execute();
        }
        else {
            std::cout << "See you soon!" << std::endl;
            exit(0);
        }
    }
}