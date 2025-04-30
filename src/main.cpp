#include "goal.h"
#include "progressLog.h"
#include <iostream>
using namespace std;

int main()
{
	//Goal goalSchool(1, "finish Goal Tracker project", "School", 100, 0, "2025-6-01");
    //goalSchool.displayGoal();
    //cout << endl;
    
    //ProgressLog progressLog1(1, 1, "2023-10-01", "Completed first draft", 20.0);

    //goalSchool.addProgress(progressLog1.getProgressMade());
    //goalSchool.displayGoal();
    //cout << endl;
    //progressLog1.displayProgress();

    // menu selection variables
    int menuOption;

    //goal creation variables
    int id;
	string name;
	string category;
	double targetValue;
	double currentProgress;
	string deadline;

    //progress log creation variables

    //while(true) {
        system("cls");
        cout << "Goal Tracker Version 1.0" << endl;
        cout << "=========================" << endl;
        cout << "Menu Options" << endl
            << "1. Create a Goal" << endl
            << "2. Log a Progress Update" << endl
            << "3. Search for Goal" << endl
            << "4. Search for Progress Log" << endl
            << "Enter Number Option" << endl;
    //}
    
}