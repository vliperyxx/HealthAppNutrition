#include "FoodLibrary.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

FoodLibrary::FoodLibrary() {
}

FoodLibrary::~FoodLibrary() {
}

void FoodLibrary::addFoodItem(){
    FoodItem foodItem;

    std::string name;
    double calories = 0.0, protein = 0.0, carbohydrates = 0.0, fat = 0.0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Дозволяє очистити буфер вводу перед використанням std::getline 
    
    std::cout << "Enter the name of the product: ";
    foodItem.setNameOfTheProduct(name);
   
    std::cout << "Enter the number of calories: ";
    foodItem.setCalories(calories);

    std::cout << "Enter the amount of protein: ";
    foodItem.setProtein(protein);

    std::cout << "Enter the amount of carbohydrates: ";
    foodItem.setCarbohydrates(carbohydrates);

    std::cout << "Enter the amount of fat: ";
    foodItem.setFat(fat);

    name = foodItem.getNameOfTheProduct();
    calories = foodItem.getCalories();
    protein = foodItem.getProtein();
    carbohydrates = foodItem.getCarbohydrates();
    fat = foodItem.getFat();

    if (name.empty()) {
        std::cout << "Product name is required. Food item not added.\n";
        return;
    }

    for (const FoodItem& existingItem : foodItems) {
        if (existingItem.getNameOfTheProduct() == name) {
            std::cout << "Food item already exists in the database.\n";
            return;
        }
    }

    foodItems.push_back(foodItem);
    std::cout << "Food item added successfully.\n";

    std::ofstream outputFile("foodDatabase.txt", std::ios::app); // Відкриваємо файл для запису/дописування
    if (outputFile.is_open()) {
        outputFile << name << "|" << calories << "|" << protein << "|" << carbohydrates << "|" << fat << std::endl;
        outputFile.close();
    }
    else {
        std::cout << "Unable to open the file for writing.\n";
    }
}

void FoodLibrary::removeFoodItem(const std::string& nameToRemove) {
    std::ifstream inputFile("foodDatabase.txt");
    std::ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        std::cout << "Unable to open files for reading/writing.\n";
        return;
    }

    std::string foodName;
    double caloriesAmount, proteinAmount, carbohydratesAmount, fatAmount;

    while (inputFile >> foodName >> caloriesAmount >> proteinAmount >> carbohydratesAmount >> fatAmount) {
        if (foodName == nameToRemove) {
            // Пропускаємо запис, який ми хочемо видалити
        }
        else {
            tempFile << foodName << "|" << caloriesAmount << "|" << proteinAmount << "|" << carbohydratesAmount << "|" << fatAmount << std::endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (remove("foodDatabase.txt") != 0) {
        std::cout << "Unable to delete the original file.\n";
        return;
    }
    if (rename("temp.txt", "foodDatabase.txt") != 0) {
        std::cout << "Unable to rename the temporary file.\n";
    }
    else {
        std::cout << "Food item removed successfully.\n";
    }
}

void FoodLibrary::editFoodItem(const std::string& nameToEdit) {
    std::ifstream inputFile("foodDatabase.txt");
    std::ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        std::cout << "Unable to open files for reading/writing.\n";
        return;
    }

    std::string foodName;
    double calorieAmt, proteinAmt, carbAmt, fatAmt;

    while (inputFile >> foodName >> calorieAmt >> proteinAmt >> carbAmt >> fatAmt) {
        if (foodName == nameToEdit) {
            FoodItem editedFoodItem;
            double newCalories = 0.0, newProtein = 0.0, newCarb = 0.0, newFat = 0.0;

            std::cout << "Enter the new name of the product: ";
            editedFoodItem.setNameOfTheProduct(nameToEdit);

            std::cout << "Enter the new number of calories: ";
            editedFoodItem.setCalories(newCalories);

            std::cout << "Enter the new amount of protein: ";
            editedFoodItem.setProtein(newProtein);

            std::cout << "Enter the new amount of carbohydrates: ";
            editedFoodItem.setCarbohydrates(newCarb);

            std::cout << "Enter the new amount of fat: ";
            editedFoodItem.setFat(newFat);

            tempFile << editedFoodItem.getNameOfTheProduct() << "|" << editedFoodItem.getCalories()
                << "|" << editedFoodItem.getProtein() << "|" << editedFoodItem.getCarbohydrates()
                << "|" << editedFoodItem.getFat() << std::endl;
        }
        else {
            tempFile << foodName << "|" << calorieAmt << "|" << proteinAmt << "|" << carbAmt << "|" << fatAmt << std::endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (remove("foodDatabase.txt") != 0) {
        std::cout << "Unable to delete the original file.\n";
        return;
    }
    if (rename("temp.txt", "foodDatabase.txt") != 0) {
        std::cout << "Unable to rename the temporary file.\n";
    }
    else {
        std::cout << "Food item edited successfully.\n";
    }
}

void FoodLibrary::viewFoodList() {
    std::ifstream inputFile("foodDatabase.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file for reading.\n";
        return;
    }

    std::cout << "List of food items:\n";

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string foodName, calorieAmt, proteinAmt, carbAmt, fatAmt;

        std::getline(ss, foodName, '|');
        std::getline(ss, calorieAmt, '|');
        std::getline(ss, proteinAmt, '|');
        std::getline(ss, carbAmt, '|');
        std::getline(ss, fatAmt, '|');

        std::cout << "Name: " << foodName << "\n";
        std::cout << "Calories: " << calorieAmt << "\n";
        std::cout << "Protein: " << proteinAmt << "\n";
        std::cout << "Carbohydrates: " << carbAmt << "\n";
        std::cout << "Fat: " << fatAmt << "\n";
        std::cout << "---------------------------\n";
    }

    inputFile.close();
}

std::vector<FoodItem> FoodLibrary::searchFoodByName(const std::string& nameToSearch) {
    std::vector<FoodItem> searchResults;
    std::ifstream inputFile("foodDatabase.txt");
    std::string foodName;
    double calorieAmt, proteinAmt, carbAmt, fatAmt;

    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file for reading.\n";
        return searchResults;
    }

    while (inputFile >> foodName >> calorieAmt >> proteinAmt >> carbAmt >> fatAmt) {
        if (foodName.find(nameToSearch) != std::string::npos) {
            searchResults.emplace_back(foodName, calorieAmt, proteinAmt, carbAmt, fatAmt);
        }
    }

    inputFile.close();

    if (searchResults.empty()) {
        std::cout << "No products found with the name: " << nameToSearch << std::endl;
    }
    else {
        std::cout << "Search results for: " << nameToSearch << std::endl;
        for (const FoodItem& item : searchResults) {
            std::cout << "Name: " << item.getNameOfTheProduct() << std::endl;
            std::cout << "Calories: " << item.getCalories() << std::endl;
            std::cout << "Protein: " << item.getProtein() << std::endl;
            std::cout << "Carbohydrates: " << item.getCarbohydrates() << std::endl;
            std::cout << "Fat: " << item.getFat() << std::endl;
        }
    }

    return searchResults;
}

std::vector<FoodItem> FoodLibrary::searchFoodByCalories(double minCalories, double maxCalories) {
    std::vector<FoodItem> searchResults;
    std::ifstream inputFile("foodDatabase.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file for reading.\n";
        return searchResults;
    }

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string foodName, calorieAmt, proteinAmt, carbAmt, fatAmt;

        std::getline(ss, foodName, '|');
        std::getline(ss, calorieAmt, '|');
        std::getline(ss, proteinAmt, '|');
        std::getline(ss, carbAmt, '|');
        std::getline(ss, fatAmt, '|');

        double caloriesAmount = std::stod(calorieAmt);
        if (caloriesAmount >= minCalories && caloriesAmount <= maxCalories) {
            searchResults.emplace_back(foodName, caloriesAmount, std::stod(proteinAmt), std::stod(carbAmt), std::stod(fatAmt));
        }
    }

    inputFile.close();

    std::sort(searchResults.begin(), searchResults.end(), [](const FoodItem& a, const FoodItem& b) {
        return a.getCalories() < b.getCalories();
        });

    if (searchResults.empty()) {
        std::cout << "No products found within the specified calorie range (" << minCalories << " - " << maxCalories << ")." << std::endl;
    }
    else {
        std::cout << "Search results within the specified calorie range (" << minCalories << " - " << maxCalories << "):" << std::endl;
        for (const FoodItem& item : searchResults) {
            std::cout << "Name: " << item.getNameOfTheProduct() << std::endl;
            std::cout << "Calories: " << item.getCalories() << std::endl;
        }
    }

    return searchResults;
}

std::vector<FoodItem> FoodLibrary::searchFoodByAlphabeticalOrder() {
    foodItems.clear();
    std::ifstream inputFile("foodDatabase.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file for reading.\n";
        return std::vector<FoodItem>();
    }

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string foodName, calorieAmt, proteinAmt, carbAmt, fatAmt;

        std::getline(ss, foodName, '|');
        std::getline(ss, calorieAmt, '|');
        std::getline(ss, proteinAmt, '|');
        std::getline(ss, carbAmt, '|');
        std::getline(ss, fatAmt, '|');

        FoodItem newItem(foodName, std::stod(calorieAmt), std::stod(proteinAmt), std::stod(carbAmt), std::stod(fatAmt));
        foodItems.push_back(newItem);
    }

    inputFile.close();

    std::vector<FoodItem> sortedItems = foodItems;
    std::sort(sortedItems.begin(), sortedItems.end(), [](const FoodItem& a, const FoodItem& b) {
        return a.getNameOfTheProduct() < b.getNameOfTheProduct();
        });

    return sortedItems;
}

void FoodLibrary::viewFoodByAlphabeticalOrder() {
    std::vector<FoodItem> sortedItems = searchFoodByAlphabeticalOrder();

    if (sortedItems.empty()) {
        std::cout << "No products in the database.\n";
    }
    else {
        std::cout << "All products in alphabetical order:\n";
        for (const FoodItem& item : sortedItems) {
            std::cout << "Name: " << item.getNameOfTheProduct() << std::endl;
            std::cout << "Calories: " << item.getCalories() << std::endl;
        }
    }
}

std::vector<FoodItem> FoodLibrary::searchFoodByCaloriesDescending() {
    std::ifstream inputFile("foodDatabase.txt");
    std::vector<FoodItem> sortedItems;
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file for reading.\n";
        return sortedItems;
    }

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string foodName, calorieAmt, proteinAmt, carbAmt, fatAmt;

        std::getline(ss, foodName, '|');
        std::getline(ss, calorieAmt, '|');
        std::getline(ss, proteinAmt, '|');
        std::getline(ss, carbAmt, '|');
        std::getline(ss, fatAmt, '|');

        FoodItem item(foodName, std::stod(calorieAmt), std::stod(proteinAmt), std::stod(carbAmt), std::stod(fatAmt));
        sortedItems.push_back(item);
    }

    inputFile.close();

    std::sort(sortedItems.begin(), sortedItems.end(), [](const FoodItem& a, const FoodItem& b) {
        return a.getCalories() > b.getCalories();
        });

    return sortedItems;
}

void FoodLibrary::viewFoodByCaloriesDescending() {
    std::vector<FoodItem> sortedItems = searchFoodByCaloriesDescending();

    if (sortedItems.empty()) {
        std::cout << "No products in the database.\n";
    }
    else {
        std::cout << "All products sorted by calories in descending order:\n";
        for (const FoodItem& item : sortedItems) {

            std::cout << "Name: " << item.getNameOfTheProduct() << std::endl;
            std::cout << "Calories: " << item.getCalories() << std::endl;
        }
    }
}