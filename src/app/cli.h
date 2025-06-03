#ifndef CLI_H
#define CLI_H
#include "goalStorage.h"
#include "progStorage.h"

void save(const GoalStorage& goalStorage, const ProgStorage& progStorage);
void printMenu(const GoalStorage& goalStorage);
void printHelp();
void printVersion();
void startUp(GoalStorage& goalStorage, ProgStorage& progStorage);
bool shutDown(GoalStorage& goalStorage, ProgStorage& progStorage, bool isRunning);
void goalSearch(GoalStorage& goalStorage);
void createGoal(GoalStorage& goalStorage);
void logProgress(ProgStorage& progStorage);
int parse(std::string input);

// function to handle the command line arguments
// function to handle creating a goal
// function to handle deleting a goal
// function to handle logging progress
// function to handle listing goals and progress
// function to handle marking a goal as complete
// function to handle setting a reminder
// function to handle changing a deadline
// function to handle changing a goal's priority

#endif 