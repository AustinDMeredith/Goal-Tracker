#include "cli.h"
#include "goalStorage.h"
#include "progStorage.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void save(const GoalStorage& goalStorage)
{
    // opens the save file
    ofstream foutGoal("C:/Coding Projects/Goal-Tracker/src/log/goalData/goalData.txt"); 
    
    // checks if file opened properly
    if(!foutGoal) { 
        cout << "Save failed" << endl;
        return;
    }
    
    // writes data to save file
    for(const auto& pair : goalStorage.getGoals()) { 
        foutGoal 
        << pair.first << '|'
        << pair.second.getName() << '|'
        << pair.second.getCategory() << '|'
        << pair.second.getTargetValue() << '|'
        << pair.second.getCurrentProgress() << '|'
        << pair.second.getDeadline() << '\n'; 
    }

    cout << "Save complete";
    return;
}

void printMenu() {
    cout << "Welcome To Osmium" << endl
    << "Type Help to view list of commands" << endl;
    return;
}

void printHelp() {
    cout << "Here is a list of all the functions." << endl
    << "Help - Prints all the functions." << endl
    << "Home - Takes user to the Home page." << endl
    << "New Goal - Takes user to the New Goal page." << endl
    << "Log Progress - Takes user to the Log Progress page." << endl
    << "Save - Saves any changes made by the user." << endl
    << "Quit - Quits the program and saves changes." << endl;
}

void printVersion() {
    cout << "Pre-Release Version 0.0.1" << endl;
    return;
}

void startUp() {
    GoalStorage goalStorage;
    ifstream finGoal("C:/Coding Projects/Goal-Tracker/src/log/goalData/goalData.txt");
    system("cls");

    if(!finGoal) {
        cout << "Failed to read goals from save file" << endl;
        return;
    }

    // reads from save file 
    string line;
    while(getline(finGoal, line)) {
        istringstream iss(line);
        string mapId, goalName, category, targetValue, currentValue, deadline;
        
        getline(iss, mapId, '|');
        getline(iss, goalName, '|');
        getline(iss, category, '|');
        getline(iss, targetValue, '|'); // this is a string value and needs to be typecast
        getline(iss, currentValue, '|'); // this is a string value and needs to be typecast
        getline(iss, deadline, '|');


        


    }
    printVersion();
    printMenu();
}