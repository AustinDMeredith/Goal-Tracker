#include "progStorage.h"
#include <iostream>
#include <fstream>
using namespace std;

int ProgStorage::getNextId() const {
    if (progLogs.empty()) return 1;
    int highestId = progLogs.rbegin()->first;
    return highestId + 1;
}

void ProgStorage::addLog(const int& id, const ProgressLog& progLog) {
    progLogs.emplace(id, progLog);
    cout << "Progress log successfully added." << endl;
}

void ProgStorage::updateLog(const int& id, const ProgressLog& updatedLog) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        result->second = updatedLog;
        cout << "Progress log successfully updated." << endl;
    } else { 
        cout << "No progress log with ID " << id << " found.";
    }
}

void ProgStorage::removeLog(const int& id) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        progLogs.erase(result);
        cout << "Progress log successfully deleted." << endl;
    } else { 
        cout << "No progress log with ID " << id << " found.";
    }

}

const std::map<int, ProgressLog>& ProgStorage::getLogs() const {
    return progLogs;
}

ProgressLog* ProgStorage::findLog(const int& id) {
    auto result = progLogs.find(id);
    if(result != progLogs.end()) {
        return &result->second;
    }
    return nullptr;
}