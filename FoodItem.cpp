#include "FoodItem.h"
#include <iostream>


FoodItem::FoodItem() {
}

FoodItem::FoodItem(const std::string& newName, double newCalories, double newProtein, double newCarbohydrates, double newFat)
    : name(newName), calories(newCalories), protein(newProtein), carbohydrates(newCarbohydrates), fat(newFat) {};

FoodItem::~FoodItem() {
}

std::string FoodItem::getNameOfTheProduct() const
{
    return name;
}

void FoodItem::setNameOfTheProduct(const std::string& newName)
{
    std::cin >> name;
}

double FoodItem::getCalories() const
{
    return calories;
}

void FoodItem::setCalories(double newCalories)
{
    std::cin >> calories;
}

double FoodItem::getProtein() const
{
    return protein;
}

void FoodItem::setProtein(double newProtein)
{
    std::cin >> protein;
}

double FoodItem::getCarbohydrates() const
{
    return carbohydrates;
}

void FoodItem::setCarbohydrates(double newCarbohydrates)
{
    std::cin >> carbohydrates;
}

double FoodItem::getFat() const
{
    return fat;
}

void FoodItem::setFat(double newFat)
{
    std::cin >> fat;
}


