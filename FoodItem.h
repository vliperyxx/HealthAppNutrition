#pragma once
#include <string>

/*клас, в якому буде зберігатись вся потрібна інформація про
продукти харчування/страви, кількість білків, жирів, вуглеводів
та калорійність*/

class FoodItem
{
public:
    FoodItem();
    FoodItem(const std::string& newName, double newCalories, double newProtein, double newCarbohydrates, double newFat);
    ~FoodItem();
    std::string getNameOfTheProduct() const;
    void setNameOfTheProduct(const std::string& newName);
    double getCalories() const;
    void setCalories(double newCalories);
    double getProtein() const;
    void setProtein(double newProtein);
    double getCarbohydrates() const;
    void setCarbohydrates(double newCarbohydrates);
    double getFat() const;
    void setFat(double newFat);

private:
    std::string name;
    double calories;
    double protein;
    double carbohydrates;
    double fat;
};



