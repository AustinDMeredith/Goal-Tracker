#ifndef PROGRESSLOG_H
#define PROGRESSLOG_H
#include <string>

class ProgressLog
{
private:
    int id;
    int goalId;
    std::string date;
    double progressMade;

public:
    ProgressLog(int id, int goalId, std::string date, double progressMade);

    int getId() const;
    int getGoalId() const;
    std::string getDate() const;
    double getProgressMade() const;

    void displayProgress() const;
};

#endif