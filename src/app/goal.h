#ifndef GOAL_H
#define GOAL_H
#include <string>

class Goal {
private:
	std::string name;
	std::string category;
	double targetValue;
	double currentProgress;
	std::string deadline;

public:
	Goal(std::string name, std::string category, double targetValue, double currentProgress, std::string deadline);

	std::string getName() const;
	std::string getCategory() const;
	double getTargetValue() const;
	double getCurrentProgress() const;
	std::string getDeadline() const;

	void addProgress(double amount);

	double getProgressPercent() const;

	void displayGoal() const;
};

#endif