#pragma once
#include "MenuAction.h"
#include <map>
class FoodItemAction : public MenuAction
{
private:
	std::map<int, MenuAction*> foodItemActions;
public:
	FoodItemAction();
	void execute() override;
};


