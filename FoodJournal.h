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
    FoodLibrary library;
};



