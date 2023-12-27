#pragma once
#include "MenuAction.h"
#include <map>

class ViewFoodAction : public MenuAction
{
private:
	std::map<int, MenuAction*> viewActions;
public:
	ViewFoodAction();
	void execute() override;
};


