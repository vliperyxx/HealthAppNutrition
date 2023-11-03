#pragma once
#include "FoodLibrary.h"
#include "FoodJournal.h"
#include "FoodItem.h"
#include <string>
class Menu //Menu
{
public:
	void showMenu() const;
	void run();

	FoodLibrary foodLibraryRun;
	FoodJournal foodJournalRun;
	std::string nameToRemove;
	std::string nameToEdit;
	std::string nameToSearch;
	double minCalories, maxCalories;
};

