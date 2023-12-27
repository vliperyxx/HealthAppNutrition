#pragma once
#include <string>
#include "FoodLibrary.h"

/*клас для розрахунку спожитих калорій,
білків, жирів, вуглеводів та їх подальший запис
в щоденник*/

class FoodJournal
{
public:
    FoodJournal();
    ~FoodJournal();

    void recordDailyIntake();
    void viewAllEntries() const;

    FoodLibrary library;
private:
    struct DailyIntakeItem {
        std::string productName;
        double calories;
        double protein;
        double carbohydrates;
        double fat;
    };

    std::vector<DailyIntakeItem> dailyIntakeItems;
};



