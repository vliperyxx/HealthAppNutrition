#pragma once
#include <string>
#include "FoodLibrary.h"

/*���� ��� ���������� �������� ������,
����, ����, ��������� �� �� ��������� �����
� ��������*/

class FoodJournal
{
public:
    FoodJournal();
    ~FoodJournal();

    void recordDailyIntake();
    FoodLibrary library;
};



