#include <iostream>
#include "goal.h"
using namespace std;

int main()
{
	Goal g1(1, "finish Goal Tracker project", "School", 100, 0, "2025-6-01");

    g1.addProgress(1);
    g1.displayGoal();

    g1.addProgress(2);
    g1.displayGoal();
}