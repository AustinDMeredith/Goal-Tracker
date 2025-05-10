#include "goal.h"
#include "process.h"
#include "goalStorage.h"
#include "progStorage.h"
#include <iostream>
using namespace std;

int main()
{
    GoalStorage goalStorage;
    ProgStorage progStorage;
    
    Goal goal(1, "finish Goal Tracker project", "School", 100, 0, "2025-6-01");
    goalStorage.addGoal("finish Goal Tracker project", goal);
    goal.displayGoal();
    cout << endl;

    ProgressLog progress(1, 1, "5/9/25", "got the log stoage working", 3);
    progStorage.addLog("got the log stoage working", progress);
    goal.addProgress(3);
    goalStorage.updateGoal("finish Goal Tracker project", goal);
    progress.displayProgress();
    cout << endl;
    goal.displayGoal();
}