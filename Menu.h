#pragma once
#include "FoodLibrary.h"
#include "FoodJournal.h"
#include "FoodItem.h"
#include <string>
#include <map>
#include "MenuAction.h"

class Menu
{
private:
	std::map<int, MenuAction*> actions;
public:
	Menu();
	void showMenu() const;
	void run();
};

