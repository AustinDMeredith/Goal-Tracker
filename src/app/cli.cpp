#include "cli.h"
#include "goalStorage.h"
#include "progStorage.h"
#include "goal.h"
#include "progressLog.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// saves any changes made by user
void save(const GoalStorage& goalStorage, const ProgStorage& progStorage)
{
    // opens the save files
    ofstream foutGoal("../src/log/goalData/goalData.txt");
    ofstream foutLog("../src/log/logData/logData.txt");
    
    // checks if files opened properly
    if(!foutGoal || !foutLog) { 
        cout << "Save failed" << endl;
        return;
    }
    
    // writes goal data to save file
    for(const auto& pair : goalStorage.getGoals()) { 
        foutGoal 
        << pair.first << '|'
        << pair.second.getName() << '|'
        << pair.second.getCategory() << '|'
        << pair.second.getTargetValue() << '|'
        << pair.second.getCurrentProgress() << '|'
        << pair.second.getDeadline() << '\n'; 
    }

    // writes log data to save file
    for(const auto& pair : progStorage.getLogs()) {
        foutLog
        << pair.first << '|'
        << pair.second.getDate() << '|'
        << pair.second.getLogName() << '|'
        << pair.second.getProgressMade() << '\n';
    }

    cout << "Save complete";
    return;
}

// lists names of goals
void printMenu(const GoalStorage& goalStorage) {
    cout << "Home     - Your Goals -" << endl << "-----------------------" << endl;
    
    for(const auto& pair : goalStorage.getGoals()) {
        cout << pair.second.getName() << endl;
    }

    cout << endl << "To view a goal type View Goal.";
    return;
}

// lists functions
void printHelp() {
    cout << "Here is a list of all the functions." << endl
    << "Help - Prints all the functions." << endl
    << "Home - Takes user to the Home page." << endl
    << "New Goal - Takes user to the New Goal page." << endl
    << "Log Progress - Takes user to the Log Progress page." << endl
    << "Save - Saves any changes made by the user." << endl
    << "Quit - Quits the program and saves changes." << endl;
    return;
}

// lists version
void printVersion() {
    cout << "Pre-Release Version 0.0.1" << endl;
    return;
}

// gathers save data and prints welcome note
void startUp(GoalStorage& goalStorage, ProgStorage& progStorage) {
    // opens save files
    ifstream finGoal("../src/log/goalData/goalData.txt");
    ifstream finLog("../src/log/logData/logData.txt");

    // pre-startup check to see if files opened properly
    if(!finGoal || !finLog) {
        cout << "Failed to read from save file." << endl;
        return;
    }
    
    // reads goals from save file 
    string line;
    while(getline(finGoal, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string mapId, goalName, category, targetValueStr, currentValueStr, deadline; // temporary storage for all goal data during startup
        
        getline(iss, mapId, '|');
        getline(iss, goalName, '|');
        getline(iss, category, '|');
        getline(iss, targetValueStr, '|'); // string value, needs to be typecase before construction
        getline(iss, currentValueStr, '|'); // string value, needs to be typecase before construction
        getline(iss, deadline, '|');
        
        double targetValue = std::stod(targetValueStr);
        double currentValue = std::stod(currentValueStr);

        Goal goal(goalName, category, targetValue, currentValue, deadline);
        goalStorage.addGoal(mapId, goal);
    }
    
    // reads logs from save file
    while(getline(finLog, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string mapId, logDate, logName, logProgressStr; // temporary storage for all log data during startup
        
        getline(iss, mapId, '|');
        getline(iss, logDate, '|');
        getline(iss, logName, '|');
        getline(iss, logProgressStr, '|'); // string value, needs to be typecase before construction
        
        double logProgress = std::stod(logProgressStr);
        
        ProgressLog log(logDate, logName, logProgress);
        progStorage.addLog(mapId, log);
    }

    // clears screen, prints welcome note
    //system("cls");
    cout << "Welcome To Osmium" << endl;
    printVersion();
    cout << "Type Help to view list of commands" << endl << endl;
}

// finds goal and returns it
void goalSearch(GoalStorage& goalStorage) {
    string mapId;
    printMenu(goalStorage);
    cout << "(Enter name exactly as you see it) >";
    getline(cin, mapId);

    system("cls");
    Goal* goal = goalStorage.findGoal(mapId);
    if(goal) {
        goal->displayGoal();
    } else {
        cout << "Goal not found." << endl;
    }
}

void createGoal(GoalStorage& goalStorage) {
    string goalName, category, targetValueStr, currentValueStr, deadline;
    double targetValue, currentValue;
    
    cout << "Create A Goal!" << endl
    << "Please follow the instructions to create a goal." << endl;
    cout << "What do you want to achieve? (Goal Name) >";
    getline(cin, goalName);
    cout << "When do you want to achieve this goal by? (YYYY-DD-MM) >";
    getline(cin, deadline);
    cout << "What category does this fall under? >";
    getline(cin, category);
    // includes an input checker because this is important
    while(true) {
        cout << "What is your target value? (Enter a number) >";
        getline(cin, targetValueStr);

        if (targetValueStr.empty()) {
        cout << "Input cannot be empty." << endl;
        continue; 
        } try {
            targetValue = std::stod(targetValueStr);
            break;
            // Success: value now holds the converted number
        } catch (const invalid_argument&) {
            cout << "Invalid input: not a number." << endl;
        } catch (const out_of_range&) {
            cout << "Input is out of range for a double." << endl;
        }
    }
    while(true) {
        cout << "What is your current progress? (Enter a number) >";
        getline(cin, currentValueStr);

        if (currentValueStr.empty()) {
        cout << "Input cannot be empty." << endl;
        continue;
        } try {
            currentValue = std::stod(currentValueStr);
            break;
            // Success: value now holds the converted number
        } catch (const invalid_argument&) {
            cout << "Invalid input: not a number." << endl;
        } catch (const out_of_range&) {
            cout << "Input is out of range for a double." << endl;
        }
    }

    Goal goal(goalName, category, targetValue, currentValue, deadline);
    goalStorage.addGoal(goalName, goal);

    system("cls");
    cout << "Goal has been successfully created" << endl;
}

void logProgress(ProgStorage& progStorage) {
    string logDate, logName, progressMadeStr;
    double progressMade;
    
    cout << "Log Progress!" << endl
    << "Please follow the instructions to log your progress." << endl;
    cout << "Date (YYYY-DD-MM) >";
    getline(cin, logDate);
    cout << "What all did you work on? >";
    getline(cin, logName);
    while(true){
        cout << "How much progress did you make? (Enter a number)>";
        getline(cin, progressMadeStr);

        if (progressMadeStr.empty()) {
        cout << "Input cannot be empty." << endl;
        continue;
        } try {
            progressMade = std::stod(progressMadeStr);
            break;
        } catch (const invalid_argument&) {
            cout << "Invalid input: not a number." << endl;
        } catch (const out_of_range&) {
            cout << "Input is out of range for a double." << endl;
        }
    }

    ProgressLog log(logDate, logName, progressMade);
    progStorage.addLog(logName, log);

    system("cls");
    cout << "Progress has been successfully logged";
}

bool shutDown(GoalStorage& goalStorage, ProgStorage& progStorage, bool isRunning) {
    save(goalStorage, progStorage);
    return !isRunning;
}

int parse(string input) {
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    if(input == "HELP") {
        return 1;
    } else if(input == "HOME") {
        return 2;
    } else if(input == "NEWGOAL") {
        return 3;
    } else if(input == "LOGPROGRESS") {
        return 4;
    } else if(input == "SAVE") {
        return 5;
    } else if(input == "QUIT") {
        return 6;
    } else if(input == "VIEWGOAL") {
        return 7;
    }
}