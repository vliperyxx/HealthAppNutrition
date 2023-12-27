#pragma once
#include "FoodLibrary.h"
#include "FoodJournal.h"

class MenuAction {
public:
    int choice = 0;
    FoodLibrary foodLibrary;
	FoodJournal foodJournal;
    virtual void execute() = 0;
};