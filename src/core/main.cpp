#include "goal.h"
#include "goalStorage.h"
#include <iostream>
using namespace std;

int main()
{
	Goal goalSchool(1, "finish Goal Tracker project", "School", 100, 0, "2025-6-01");
    GoalStorage storage;
    storage.addGoal("finish Goal Tracker project", goalSchool);
    
}