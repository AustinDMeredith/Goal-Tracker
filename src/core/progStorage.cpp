#include "progStorage.h"
#include <iostream>
#include <fstream>
using namespace std;

void ProgStorage::addLog(const std::string& id, const ProgressLog& progLog) {
    progLogs.emplace(id, progLog);
    cout << "Progress log successfully added." << endl;
}

void ProgStorage::updateLog(const std::string& id, const ProgressLog& updatedLog) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        result->second = updatedLog;
        cout << "Progress log successfully updated." << endl;
    } else { 
        cout << "No progress log with ID " << id << " found.";
    }
}

void ProgStorage::removeLog(const std::string& id) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        progLogs.erase(result);
        cout << "Progress log successfully deleted." << endl;
    } else { 
        cout << "No progress log with ID " << id << " found.";
    }

}

void ProgStorage::writeToFile() const {

}

ProgressLog* ProgStorage::findLog(const std::string& id) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        return &result->second;
    }
    return nullptr;
}