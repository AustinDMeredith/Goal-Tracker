#ifndef PROG_STORAGE_H
#define PROG_STORAGE_H
#include <map>
#include <string>
#include "progressLog.h"

class ProgStorage {
private:
    std::map<int, ProgressLog> progLogs;

public:
    int getNextId() const;
    void addLog(const int& id, const ProgressLog& progLog);
    void updateLog(const int& id, const ProgressLog& updatedLog);
    void removeLog(const int& id);
    const std::map<int, ProgressLog>& getLogs() const;
    

    ProgressLog* findLog(const int& id);

};

#endif