#pragma once
#include "MenuAction.h"
#include <map>

class FoodDiaryAction : public MenuAction
{
private:
	std::map<int, MenuAction*> foodDiaryActions;
public:
	FoodDiaryAction();
	void execute() override;
};



