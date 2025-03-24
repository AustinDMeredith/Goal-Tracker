#ifndef GOAL_H
#define GOAL_H
#include <string>
using namespace std;

Class Goal
{
private:
	int id;
	string name;
	string category;
	double targetValue;
	double currentProgress;
	string deadline;

public:
	Goal(int id, string name, string category, double targetValue, double currentProgress, sting deadline);

	int getId() const;
	string getName() const;
	string getCategory() const;
	
}