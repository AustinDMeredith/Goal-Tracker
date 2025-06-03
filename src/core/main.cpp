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
    ProgStorage progStorage;
    bool isRunning = true;
    startUp(goalStorage, progStorage);
    printMenu(goalStorage);
    
    while(isRunning) {
        string input;
        int option = 0;
        cout << endl << "Osmium >";
        getline(cin, input);
        option = parse(input);
        if(option == 1) {
            system("cls");
            printHelp();
        } else if(option == 2) {
            system("cls");
            printMenu(goalStorage);
        } else if(option == 3) {
            system("cls");
            createGoal(goalStorage);
        } else if(option == 4) {
            system("cls");
            logProgress(progStorage);
        } else if(option == 5) {
            system("cls");
            save(goalStorage, progStorage);
        } else if(option == 6) {
            isRunning = shutDown(goalStorage, progStorage, isRunning);
        } else if(option == 7) {
            goalSearch(goalStorage);
        } else {
            system("cls");
            cout << "Your input could not be read.";
            printHelp();
        }       
    }
}
