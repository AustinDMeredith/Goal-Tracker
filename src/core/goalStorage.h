#ifndef GOAL_STORAGE_H
#define GOAL_STORAGE_H
#include "goal.h"
#include <map>
#include <string>

class GoalStorage {
private:
    std::map<int, Goal> goals; // Map to store goals with their IDs as keys

public:
    int getNextId() const;
    void addGoal(const int& id, const Goal& goal); // Add a goal to the storage
    void updateGoal(const int& id, const Goal& updatedGoal); // Update a goal in the storage
    void removeGoal(const int& id); // Remove a goal from the storage
    const std::map<int, Goal>& getGoals() const;

    Goal* findGoal(const int& id); // Find a goal by its ID
};

#endif