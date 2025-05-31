#include "goal.h"
#include "progressLog.h"
#include "goalStorage.h"
#include "progStorage.h"
#include "cli.h"
#include <iostream>
using namespace std;

int main()
{
    system("cls");
    GoalStorage goalStorage;
    
    Goal goal(1, "finish Goal Tracker project", "School", 100, 0, "2025-6-01");
    goalStorage.addGoal("finish Goal Tracker project", goal);
    goal.displayGoal();
    cout << endl;

    save(goalStorage);
}