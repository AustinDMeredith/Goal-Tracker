#include "goal.h"
#include <iostream>
using namespace std;

Goal::Goal(int id, string name, string category, double targetValue, double currentProgress, string deadline) : id(id), name(name), category(category), targetValue(targetValue), currentProgress(currentProgress), deadline(deadline) {}

int Goal::getId() const {
    return id;
}

string Goal::getName() const {
    return name;
}

string Goal::getCategory() const {
    return category;
}

double Goal::getTargetValue() const {
    return targetValue;
}

double Goal::getCurrentProgress() const {
    return currentProgress;
}

string Goal::getDeadline() const {
    return deadline;
}

void Goal::addProgress(double amount) {
    currentProgress += amount;
    if (currentProgress > targetValue) {
        currentProgress = targetValue;
    }
}

double Goal::getProgressPercent() const {
    return (currentProgress / targetValue) * 100;
}

void Goal::displayGoal() const {
    cout << "Goal ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Category: " << category << "\n"
              << "Target: " << targetValue << "\n"
              << "Current: " << currentProgress << "\n"
              << "Deadline: " << deadline << "\n"
              << "Progress: " << getProgressPercent() << "%\n";
}
