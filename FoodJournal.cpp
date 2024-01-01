#include "FoodJournal.h"
#include "FoodItem.h"
#include "FoodLibrary.h"
#include <iostream>
#include <fstream>
#include <vector>

FoodJournal::FoodJournal() {
}

FoodJournal::~FoodJournal() {
}

// Метод, що додає щоденний прийом їжі з розрахунком сумарних значень
void FoodJournal::recordDailyIntake() {
    std::string date;
    std::cout << "Enter date (or 'q' to quit): ";
    std::cin >> date;

    if (date == "q") {
        return;
    }

    double totalCalories = 0.0;
    double totalProtein = 0.0;
    double totalCarbohydrates = 0.0;
    double totalFat = 0.0;

    std::vector<DailyIntakeItem> dailyItems; // Створення вектору для зберігання введених продуктів

    std::string productName;
    while (true) {
        std::cout << "Enter product name (or 'q' to finish adding products for the day): ";
        std::cin.ignore();
        std::getline(std::cin, productName);

        if (productName == "q") {
            break;
        }

        // Пошук продукту в бібліотеці та отримання інформації про нього
        std::vector<FoodItem> searchResults = library.searchFoodByName(productName);

        if (searchResults.empty()) {
            std::cout << "Product not found in the library.\n";
        }
        else {
            // Відобразити знайдені продукти і дозволити користувачу вибрати один з них
            std::cout << "Found products:\n";
            for (size_t i = 0; i < searchResults.size(); ++i) {
                const FoodItem& item = searchResults[i];
                std::cout << i + 1 << ". " << item.getNameOfTheProduct() << " (" << item.getCalories() << " calories)\n";
            }
            std::cout << "Select a product (1-" << searchResults.size() << "): ";
            int selection;
            std::cin >> selection;

            if (selection >= 1 && selection <= searchResults.size()) {
                const FoodItem& selectedProduct = searchResults[selection - 1];
                totalCalories += selectedProduct.getCalories();
                totalProtein += selectedProduct.getProtein();
                totalCarbohydrates += selectedProduct.getCarbohydrates();
                totalFat += selectedProduct.getFat();
                std::cout << "Product added: " << selectedProduct.getNameOfTheProduct() << "\n";

                // Зберегти інформацію про введений продукт
                DailyIntakeItem dailyItem;
                dailyItem.productName = selectedProduct.getNameOfTheProduct();
                dailyItem.calories = selectedProduct.getCalories();
                dailyItem.protein = selectedProduct.getProtein();
                dailyItem.carbohydrates = selectedProduct.getCarbohydrates();
                dailyItem.fat = selectedProduct.getFat();
                dailyItems.push_back(dailyItem);
            }
            else {
                std::cout << "Invalid selection.\n";
            }
        }
    }

    // Зберегти інформацію про введені продукти в щоденнику
    dailyIntakeItems.insert(dailyIntakeItems.end(), dailyItems.begin(), dailyItems.end());

    // Записати дані до щоденника
    std::ofstream journalFile("foodJournal.txt", std::ios::app); // Відкриваємо файл для дописування
    if (journalFile.is_open()) {
        journalFile << "Date: " << date << "\n";
        journalFile << "Total Calories: " << totalCalories << "\n";
        journalFile << "Total Protein: " << totalProtein << "\n";
        journalFile << "Total Carbohydrates: " << totalCarbohydrates << "\n";
        journalFile << "Total Fat: " << totalFat << "\n";
        journalFile << "Products:\n";
        for (const DailyIntakeItem& item : dailyItems) {
            journalFile << "- " << item.productName << "(" << item.calories << " calories);" << "\n";
        }
        journalFile << "---------------------------\n";
        journalFile.close();
        std::cout << "Daily intake recorded successfully.\n";
    }
    else {
        std::cout << "Unable to open the journal file for writing.\n";
    }
}

void FoodJournal::viewAllEntries() const {
    std::ifstream journalFile("foodJournal.txt");
    if (journalFile.is_open()) {
        std::string line;
        while (std::getline(journalFile, line)) {
            std::cout << line << "\n";
        }
        journalFile.close();
    }
    else {
        std::cout << "Unable to open the journal file for reading.\n";
    }
}

