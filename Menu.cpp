#include "Menu.h"
#include "FoodLibrary.h"
#include "FoodJournal.h"
#include "FoodItem.h"
#include <iostream>

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

        switch (choice)
        {
        case 1:
            foodLibraryRun.viewFoodList();
            break;
        case 2:
            foodLibraryRun.addFoodItem();
            break;
        case 3:
            Menu::nameToRemove;
            std::cout << "Enter the name of the product you want to remove: ";
            std::cin >> nameToRemove;
            foodLibraryRun.removeFoodItem(nameToRemove);
            break;
        case 4:
            std::cout << "Enter the name of the product you want to edit: ";
            std::cin >> nameToEdit;
            foodLibraryRun.editFoodItem(nameToEdit);
            break;
        case 5:
            std::cout << "Enter the name of the product you want to find: ";
            std::cin >> nameToSearch;
            foodLibraryRun.searchFoodByName(nameToSearch);
            break;
        case 6:
            std::cout << "Enter enter calorie limits with using a space: ";
            std::cin >> minCalories >> maxCalories;
            foodLibraryRun.searchFoodByCalories(minCalories, maxCalories);
            break;
        case 7:
            foodLibraryRun.viewFoodByAlphabeticalOrder();
            break;
        case 8:
            foodLibraryRun.viewFoodByCaloriesDescending();
            break;
        case 9:
            foodJournalRun.recordDailyIntake();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            exit(0);
        }

    }
}