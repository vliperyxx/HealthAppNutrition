#pragma once
#include <vector>
#include "FoodItem.h"

/*клас, в якому прописані основні методи для пошуку продукту/страви
за назвою, можливістю додати/видалити/редагувати інформацію про продукт, а також
переглянути знайдені пошукові результати за сортуванням по алфавіту/калорійністю*/

class FoodLibrary 
{
public:
    FoodLibrary();
    ~FoodLibrary();
    void addFoodItem();
    void removeFoodItem(const std::string& name);
    void editFoodItem(const std::string& nameToEdit);
    void viewFoodList();
    std::vector<FoodItem> searchFoodByName(const std::string& name);
    std::vector<FoodItem> searchFoodByCalories(double minCalories, double maxCalories);
    std::vector<FoodItem> searchFoodByAlphabeticalOrder();
    void viewFoodByAlphabeticalOrder();
    std::vector<FoodItem> searchFoodByCaloriesDescending();
    void viewFoodByCaloriesDescending();

private:
    std::vector<FoodItem> foodItems;
};



