#include "goalStorage.h"
#include <iostream>
#include <fstream>
using namespace std;

int GoalStorage::getNextId() const {
    if (goals.empty()) return 1;
    int highestId = goals.rbegin()->first;
    return highestId + 1;
}

// Add a goal to the storage
void GoalStorage::addGoal(const int& id, const Goal& goal) {
    goals.emplace(id, goal);
} 

// Update a goal in the storage
void GoalStorage::updateGoal(const int& id, const Goal& updatedGoal) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        result->second = updatedGoal;
        cout << "Goal successfully updated." << endl;
    } else {
        cout << "No goal with ID " << id << " found.";
    }
}

// Remove a goal from the storage
void GoalStorage::removeGoal(const int& id) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        goals.erase(result);
        cout << "Goal successfully deleted." << endl;
    } else {
        cout << "No goal with ID " << id << " found.";
    }
}

const std::map<int, Goal>& GoalStorage::getGoals() const {
    return goals;
}

// Find a goal by its ID
Goal* GoalStorage::findGoal(const int& id) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        return &result->second;
    }
    return nullptr;
}