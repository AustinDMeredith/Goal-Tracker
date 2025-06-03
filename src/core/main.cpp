#include "goal.h"
#include "progressLog.h"
#include "goalStorage.h"
#include "progStorage.h"
#include "cli.h"
#include <iostream>
using namespace std;

int main()
{
    GoalStorage goalStorage;
    startUp(goalStorage);
    goalSearch(goalStorage);
    cout << endl;
    save(goalStorage);
}
