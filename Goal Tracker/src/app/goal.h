#ifndef GOAL_H
#define GOAL_H
#include <string>

Class Goal
{
private:
	int id;
	std::string name;
	std::string category;
	double targetValue;
	double currentProgress;
	std::string deadline;

public:
	Goal(int id, std::string name, std::string category, double targetValue, double currentProgress, std::sting deadline);

	int getId() const;
	string getName() const;
	string getCategory() const;
	
}