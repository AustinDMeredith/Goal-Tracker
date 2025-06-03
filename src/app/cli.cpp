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
    ofstream foutGoal("../log/goalData/goalData.txt");
    ofstream foutLog("../log/logData/logData.txt");
    
    // checks if files opened properly
    if(!foutGoal || !foutLog) { 
        cout << "Save failed" << endl;
        return;
    }
    
    // writes goal data to save file
    for(const auto& pair : goalStorage.getGoals()) { 
        foutGoal 
        << pair.second.getId() << '|'
        << pair.second.getName() << '|'
        << pair.second.getCategory() << '|'
        << pair.second.getTargetValue() << '|'
        << pair.second.getCurrentProgress() << '|'
        << pair.second.getDeadline() << '\n'; 
    }

    // writes log data to save file
    for(const auto& pair : progStorage.getLogs()) {
        foutLog
        << pair.second.getId() << '|'
        << pair.second.getGoalId() << '|'
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
        cout << pair.first << ". " << pair.second.getName() << endl;
    }

    return;
}

// lists functions
void printHelp() {
    cout << "Here is a list of all the functions." << endl
    << "Help - Prints all the functions." << endl
    << "Home - Takes user to the Home page." << endl
    << "New Goal - Allows user to the create a New Goal." << endl
    << "Log Progress - Allows users to Log Progress." << endl
    << "View Goal Details - Allows the user to view goal details." << endl
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
    ifstream finGoal("../log/goalData/goalData.txt");
    ifstream finLog("../log/logData/logData.txt");

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
        string idStr, goalName, category, targetValueStr, currentValueStr, deadline; // temporary storage for all goal data during startup
        
        getline(iss, idStr, '|');
        getline(iss, goalName, '|');
        getline(iss, category, '|');
        getline(iss, targetValueStr, '|'); // string value, needs to be typecase before construction
        getline(iss, currentValueStr, '|'); // string value, needs to be typecase before construction
        getline(iss, deadline, '|');
        
        double targetValue = std::stod(targetValueStr);
        double currentValue = std::stod(currentValueStr);
        int id = std::stoi(idStr);

        Goal goal(id, goalName, category, targetValue, currentValue, deadline);
        goalStorage.addGoal(id, goal);
    }
    
    // reads logs from save file
    while(getline(finLog, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string mapId, idStr, goalIdStr, logDate, logName, logProgressStr; // temporary storage for all log data during startup
        
        getline(iss, idStr, '|');
        getline(iss, goalIdStr, '|');
        getline(iss, logDate, '|');
        getline(iss, logName, '|');
        getline(iss, logProgressStr, '|'); // string value, needs to be typecase before construction
        
        double logProgress = std::stod(logProgressStr);
        int id = std::stoi(idStr);
        int goalId = std::stoi(goalIdStr);
        
        ProgressLog log(id, goalId, logDate, logName, logProgress);
        progStorage.addLog(id, log);
    }

    // clears screen, prints welcome note
    system("cls");
    cout << "Welcome To Osmium" << endl;
    printVersion();
    cout << "Type Help to view list of commands" << endl << endl;
}

// finds goal and returns it
void goalSearch(GoalStorage& goalStorage) {
    string mapIdStr;
    printMenu(goalStorage);
    cout << endl << "Enter the number of the goal you want to view >";
    getline(cin, mapIdStr);

    int mapId = stoi(mapIdStr);
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

    int id = goalStorage.getNextId();
    Goal goal(id, goalName, category, targetValue, currentValue, deadline);
    goalStorage.addGoal(id, goal);

    system("cls");
    cout << "Goal has been successfully created" << endl;
}

void logProgress(ProgStorage& progStorage, GoalStorage& goalStorage) {
    string logDate, logName, progressMadeStr;
    double progressMade;
    string mapIdStr;
    
    cout << "Log Progress!" << endl
    << "Please follow the instructions to log your progress." << endl;

    printMenu(goalStorage);
    cout << "Enter the number of the goal you want to log progress for >";
    getline(cin, mapIdStr);

    int mapId = std::stoi(mapIdStr);

    system("cls");
    Goal* goal = goalStorage.findGoal(mapId);
    if(goal) {
        goal->displayGoal();

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

        int id = progStorage.getNextId();
        int goalId = goal->getId();
        ProgressLog log(id, goalId, logDate, logName, progressMade);
        progStorage.addLog(id, log);

        goal->addProgress(log.getProgressMade());
    } else {
        cout << "Goal not found." << endl;
    }
    system("cls");
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
    } else if(input == "VIEWGOALDETAILS") {
        return 7;
    }
}