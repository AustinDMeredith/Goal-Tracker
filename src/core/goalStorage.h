#ifndef GOAL_STORAGE_H
#define GOAL_STORAGE_H
#include "goal.h"
#include <map>
#include <string>

class GoalStorage {
private:
    std::map<std::string, Goal> goals; // Map to store goals with their IDs as keys

public:
    void addGoal(const std::string& id, const Goal& goal); // Add a goal to the storage
    void updateGoal(const std::string& id, const Goal& updatedGoal); // Update a goal in the storage
    void removeGoal(const std::string& id); // Remove a goal from the storage
    void writeToFile() const;

    Goal* findGoal(const std::string& id); // Find a goal by its ID
};

#endif