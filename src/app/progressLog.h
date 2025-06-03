#ifndef PROGRESSLOG_H
#define PROGRESSLOG_H
#include <string>

class ProgressLog {
private:
    std::string date;
    std::string logName;
    double progressMade;

public:
    ProgressLog(std::string date, std::string logName, double progressMade);

    std::string getDate() const;
    std::string getLogName() const;
    double getProgressMade() const;

    void displayProgress() const;
};

#endif