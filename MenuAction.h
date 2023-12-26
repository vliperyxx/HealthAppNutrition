#pragma once
#include "FoodLibrary.h"
#include "FoodJournal.h"

class MenuAction {
public:
    FoodLibrary foodLibrary;
	FoodJournal foodJournal;
	double minCalories, maxCalories;
    virtual void execute() = 0;
};