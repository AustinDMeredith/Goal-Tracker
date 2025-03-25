#include "progressLog.h"
#include <iostream>
using namespace std;

ProgressLog::ProgressLog(int id, int goalId, string date, string logName, double progressMade) : id(id), goalId(goalId), date(date), logName(logName), progressMade(progressMade) {}

int ProgressLog::getId() const {
	return id;
}

int ProgressLog::getGoalId() const {
	return goalId;
}

string ProgressLog::getDate() const {
	return date;
}

string ProgressLog::getLogName() const {
	return logName;
}

double ProgressLog::getProgressMade() const {
	return progressMade;
}

void ProgressLog::displayProgress() const {
	cout << "Activity Name ";
}