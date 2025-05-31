#include "cli.h"
#include "goalStorage.h"
#include "progStorage.h"
#include <fstream>
#include <iostream>
using namespace std;

void save(const GoalStorage& goalStorage)
{
    // opens the save file
    ofstream foutGoal("C:/Coding Projects/Goal-Tracker/src/log/goalData/goalData.txt"); 
    
    // checks if file opened properly
    if(!foutGoal) { 
        cout << "Failed to open save file" << endl;
        return;
    }
    
    // writes data to save file
    for(const auto& pair : goalStorage.getGoals()) { 
        foutGoal 
        << pair.first << '|'
        << pair.second.getId() << '|'
        << pair.second.getName() << '|'
        << pair.second.getCategory() << '|'
        << pair.second.getTargetValue() << '|'
        << pair.second.getCurrentProgress() << '|'
        << pair.second.getDeadline() << '\n'; 
    }

    cout << "Save complete";
}