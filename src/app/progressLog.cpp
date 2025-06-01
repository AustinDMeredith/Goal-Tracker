#include "progressLog.h"
#include <iostream>
using namespace std;

ProgressLog::ProgressLog(string date, string logName, double progressMade) : date(date), logName(logName), progressMade(progressMade) {}

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
	cout << "Activity Name: " << logName << endl;
	cout << "Date: " << date << endl;	
	cout << "Progress Made: " << progressMade << "%" << endl;
}