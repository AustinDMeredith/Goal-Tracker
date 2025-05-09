#include "goalStorage.h"
#include <iostream>
using namespace std;

// Add a goal to the storage
void GoalStorage::addGoal(const std::string& id, const Goal& goal) {
    goals[id] = goal;
} 

// Update a goal in the storage
void GoalStorage::updateGoal(const std::string& id, const Goal& updatedGoal) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        result->second = updatedGoal;
        cout << "Success" << endl;
    } else {
        cout << "No goal with ID " << id << " found.";
    }
}

// Remove a goal from the storage
void GoalStorage::removeGoal(const std::string& id) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        goals.erase(result);
    } else {
        cout << "No goal with ID " << id << " found.";
    }
}

// Find a goal by its ID
Goal* GoalStorage::findGoal(const std::string& id) {
    auto result = goals.find(id);
    if(result != goals.end()) {
        return &result->second;
    }
    return nullptr;
}