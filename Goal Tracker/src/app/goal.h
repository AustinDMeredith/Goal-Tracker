#ifndef GOAL_H
#define GOAL_H
#include <string>

class Goal
{
private:
	int id;
	std::string name;
	std::string category;
	double targetValue;
	double currentProgress;
	string deadline;

public:
	Goal(int id, std::string name, std::string category, double targetValue, double currentProgress, std::string deadline);

	int getId() const;
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