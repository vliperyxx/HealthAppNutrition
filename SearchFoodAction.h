#pragma once
#include "MenuAction.h"
#include <map>
class SearchFoodAction : public MenuAction
{
private:
	std::map<int, MenuAction*> searchActions;
public:
	SearchFoodAction();
	void execute() override;
};


