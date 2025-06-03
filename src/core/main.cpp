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
    startUp(goalStorage, progStorage); // runs the startup procedure
    printMenu(goalStorage); 
    
    while(isRunning) {
        string input;
        int option = 0;

        cout << endl << "Osmium >";
        getline(cin, input);
        option = parse(input);

        if(option == 1) { // prints help page
            system("cls");
            printHelp();
        } else if(option == 2) { // prints menu page
            system("cls");
            printMenu(goalStorage);
        } else if(option == 3) { // prints new goal page
            system("cls");
            createGoal(goalStorage);
        } else if(option == 4) { // prints log progress page
            system("cls");
            logProgress(progStorage, goalStorage);
        } else if(option == 5) { // saves the program
            system("cls");
            save(goalStorage, progStorage);
        } else if(option == 6) { // runs shutdown procedure
            isRunning = shutDown(goalStorage, progStorage, isRunning); 
        } else if(option == 7) { // opens a goal from the home page
            system("cls");
            goalSearch(goalStorage);
        } else { // user did not enter an acceptable response
            system("cls");
            cout << "Your input could not be read." << endl;
            printHelp();
        }       
    }
}
